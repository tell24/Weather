;
#include <Wire.h>
#include <SparkFunHTU21D.h>

#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
#include "DebugMacros.h"

#define CURRENT_DATA   0
#define HISTORY_DATA   1
#define RETURN_DATA    2
#define GET_RESPONSE   5


HTU21D  htu ;

#define dev 0

typedef struct data_packet_sen {
  int16_t    temp;
  int16_t    hum ;
  uint16_t  wind_speed;
  uint16_t  peak_wind_speed;
  uint16_t  bearing;
  int16_t   rain;
  int32_t   rssi;
  int16_t   status;
} sensor_data;

sensor_data sensors;


typedef struct data_packet_rem {
  int16_t status;
  uint16_t wind_speed;
  uint16_t peak_wind_speed;
  uint16_t bearing;
  unsigned char checksum;
} remotedata;

remotedata remote_data;


typedef struct data_packet1 {
  signed short out_temp;
  signed short in_temp;
  signed short out_hum;
  signed short in_hum;
  signed short wind_speed;
  signed short peak_wind_speed;
  signed short bearing;
  signed short pressure;
  signed short rainfall;
  signed short rainfall_rate;
  uint32_t timestamp;
} current;

current c_data;

typedef struct data_packet2 {
  signed short out_temp_H;
  signed short out_temp_L;
  signed short in_temp_H;
  signed short in_temp_L;
  signed short out_hum_H;
  signed short out_hum_L;
  signed short in_hum_H;
  signed short in_hum_L;
  signed short wind_speed;
  signed short peak_wind_speed;
  signed short bearing;
  signed short pressure_H;
  signed short pressure_L;
  signed short rainfall;
  uint32_t timestamp;
} history_packet;

history_packet h_data;

byte dat[32];

// Fill ssid and password with your network credentials
const char* ssid =  "SKY4B6A5";
const char* password = "RDFDZPDP";


const char* getHost = "script.google.com"; // The data receiver host name (not URL)
const int httpGetPort = 443; // The data receiver host port
const char* fingerprint = "";
//const uint8_t fingerprint[20] = {};
#ifdef DEV
const char *GScriptId = "AKfycbw2oFPGuRa3J63WP9Qxa1cpklnbjAkA4s42TOboplhrfoVGh3L1";
String url = String("/macros/s/") + GScriptId + "/dev?value=1,2,3,4,5,6,7,8,9,10,11";
String getReceiverURL = String("/macros/s/") + GScriptId + "/exec?read="; // The data receiver script
String postReceiverURL = String("/macros/s/") + GScriptId + "/dev?value=";// The data receiver script
#else
const char *GScriptId = "AKfycbw2oFPGuRa3J63WP9Qxa1cpklnbjAkA4s42TOboplhrfoVGh3L1";
String url = String("/macros/s/") + GScriptId + "/exec?value=1,2,3,4,5,6,7,8,9,10,11";
String getReceiverURL = String("/macros/s/") + GScriptId + "/exec?read="; // The data receiver script
String postReceiverURL = String("/macros/s/") + GScriptId + "/exec?value="; // The data receiver script
#endif

bool htu_found;
//unsigned long last_sent_time = millis(); // time last counter sent to the receiver host

// config static IP
IPAddress ip(192, 168, 0, 27); // where xx is the desired IP Address
IPAddress gateway(192, 168, 0, 1); // set gateway to match your network

IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network

WiFiServer server(80); // set WiFiServer on port 80
#define SDA 0
#define SCL 2

boolean getting_data;
volatile int      weather_status = 0;
double    hum ;
double    temp;
String data_result = "";
int type = 0;

boolean i2c_RainSensor_read()
{
  byte buf[3];
#if DEV
  int c = 0;
  Wire.requestFrom(8, 3);    // request 3 bytes from slave device #8

  while (Wire.available()) { // slave may send less than requested
    buf[c] = Wire.read(); // receive a byte as character buf[c] = Wire.read(); // receive a byte as character
    c++;
  }
  if (buf[2] == Sum(buf, 2)) {
    // reset drops
    Wire.beginTransmission(8); // transmit to device #16
    // device address is specified in datasheet
    Wire.write('r');             // sends value byte
    Wire.endTransmission();     // stop transmitting
    uint16_t rain_value;
    memcpy(&rain_value, buf, 2);
    rain = rain_value;
    getting_data = false;
    return true;
  }
  getting_data = false;
  return false;
#else
  sensors.rain = 0;
  getting_data = false;
  return true;
#endif
}

void i2c_WindSensor_read() {
#if DEV
  Serial.println("request wind");
  getting_data = true;
  byte s_buf[7];
  requestdata.type = 6;
  requestdata.temp = sensor_data.temp;
  requestdata.hum = sensor_data.hum;
  memcpy(s_buf, &requestdata, 6);
  s_buf[6] = Sum(s_buf, 8);
  Wire.beginTransmission(32); // transmit to device #16
  Wire.write(s_buf, 9);
  Wire.endTransmission();     // stop transmitting
  delay(1);
  byte buf[10];
  int c = 0;
  Wire.requestFrom(32, 9);    // request 3 bytes from slave device #16
  while (Wire.available()) { // slave may send less than requested
    buf[c] = Wire.read(); // receive a byte as character buf[c] = Wire.read(); // receive a byte as character

    c++;
  }
  if (buf[6] == Sum(buf, 6))
  {
    memcpy(&remote_data, buf, 9);
    if (remote_data.status == 0) {
      wind_speed = (double)remote_data.wind_speed / 100;
      peak_wind_speed = (double)remote_data.peak_wind_speed / 100;
      bearing = remote_data.bearing;
    }
    else {
      wind_speed = 0;
      peak_wind_speed = 0;
      bearing = 0;

    }
  }
#else
  sensors.status = 0;
  sensors.wind_speed = 234;
  sensors.peak_wind_speed = 760;
  sensors.bearing = 170;
#endif
  getting_data = false;
}


// send data to the receiver host
void get_post_Data( int type) {
  HTTPSRedirect* clientGet = nullptr; //WiFiClient clientGet;
  // We now create and add parameters:
  String src = "ESP";
  //  int vint = interruptCounter;
  String getReceiverURLtemp = getReceiverURL + type ; //+ "?src=" + src + "&int=" + vint;
  String postReceiverURLtemp = postReceiverURL; //+ "?src=" + src + "&int=" + vint;

  Serial.println("-------------------------------");
  Serial.print(">>> Connecting to host: ");
  Serial.println(getHost);
  clientGet = new HTTPSRedirect(httpGetPort);
  clientGet->setPrintResponseBody(true);
  clientGet->setContentTypeHeader("application/json");

  Serial.print("Connecting to ");
  Serial.println(getHost);


  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    int retval = clientGet->connect(getHost, httpGetPort);
    if (retval == 1) {
      flag = true;
      break;
    }
    else
      Serial.println("Connection failed. Retrying...");
  }

  if (!flag) {
    Serial.print("Could not connect to server: ");
    Serial.println(getHost);
    Serial.println("Exiting...");
    return;
  };
  String str_data = "" ;
  switch (type) {
    case 0:
      Serial.println("\nPOST: Current'");
      Serial.println("=========================");

      str_data =
        String (c_data.out_temp) + "," +
        c_data.in_temp + "," +
        c_data.out_hum + "," +
        c_data.in_hum + "," +
        c_data.wind_speed + "," +
        c_data.peak_wind_speed + "," +
        c_data.bearing + "," +
        c_data.pressure + "," +
        c_data.rainfall + "," +
        c_data.rainfall_rate + "," +
        c_data.timestamp;
      postReceiverURLtemp = postReceiverURLtemp + String(type) ;
      Serial.println(postReceiverURLtemp);
      Serial.println(str_data);
      clientGet->POST(postReceiverURLtemp, getHost, str_data);
      break;
    case 1:
      Serial.println("\nPOST: History'");
      Serial.println("=========================");
      str_data =
        String(type) + "," +
        h_data.out_temp_H + "," +
        h_data.out_temp_L + "," +
        h_data.in_temp_H + "," +
        h_data.in_temp_L + "," +
        h_data.out_hum_H + "," +
        h_data.out_hum_L + "," +
        h_data.in_hum_H + "," +
        h_data.in_hum_L + "," +
        h_data.wind_speed + "," +
        h_data.peak_wind_speed + "," +
        h_data.bearing + "," +
        h_data.pressure_H + "," +
        h_data.pressure_L + "," +
        h_data.rainfall + "," +
        h_data.timestamp;
      postReceiverURLtemp = postReceiverURLtemp + String(type) ;
      Serial.println(postReceiverURLtemp);
      Serial.println(str_data);
      clientGet->POST(postReceiverURLtemp, getHost, str_data);
      break;
  }
  data_result = clientGet->getResponseBody();
  Serial.println( data_result);
  // delete HTTPSRedirect object
  delete clientGet;
  clientGet = nullptr;
}

void setup() {
  Serial.begin(115200); // Start the Serial communication to send messages to the computer
  delay(100);
  Serial.println('\n');

  Wire.begin(SDA, SCL);
  delay(1000);
  int test_sensor = 0;

  double    hum, temp;
  do {
    htu.begin();
    hum = htu.readHumidity();
    temp = htu.readTemperature();
    Serial.println('.');
    test_sensor++;
    delay(500);
  } while (((int)hum != 998) && ((int)temp != 998) && (test_sensor < 5));
  if (test_sensor <= 5) htu_found = true; else  htu_found = false ;
  Serial.println(temp);
  Serial.println(hum);
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
  WiFi.config(ip, gateway, subnet);
  WiFi.hostname("ESP-01 board");
  WiFi.begin(ssid, password); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer

  Serial.print("IP SIGNAL LEVEL:\t");
  Serial.println(WiFi.RSSI());
  // set interrupt handler
  //pinMode(interruptPin, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);

  // start HTTP server
  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
}

String prepareRemoteHtmlPage()
{
  String htmlPage = "";
  if (htu_found) {
    long t = millis();
    getting_data = true;
    if (!i2c_RainSensor_read()) weather_status |= 2;
    while (getting_data) {
      delay(10);
      if ((millis() - t ) > 1000) {
        weather_status |= 4;
        break;
      }
    };                                  // time taken 1 - 2 milliseconds

    t = millis();
    i2c_WindSensor_read();
    while (getting_data) {
      delay(10);
      if ((millis() - t ) > 1000) {
        Serial.println("timeout");
        weather_status |= 8;
        // give false data
        break;
      }
    }
    sensors.rssi = WiFi.RSSI();
    sensors.temp = (int16_t)(htu.readTemperature() * 100);
    sensors.hum = (int16_t)(htu.readHumidity() * 100);
    sensors.rain = 0;
    htmlPage =
      String("HTTP/1.1 200 OK\r\n") +
      "Content-Type: text/html\r\n" +
      "Content-Length: " + String(sizeof(sensor_data)) + "\r\n" +
      "Connection: Close\r\n\r\n";
  }
}
// prepare a web page to be send to a client (web browser)
String prepareHtmlPage()
{
  String htmlPage = "";
  if (htu_found) {
    long t = millis();
    getting_data = true;
    if (!i2c_RainSensor_read()) weather_status |= 2;
    while (getting_data) {
      delay(10);
      if ((millis() - t ) > 1000) {
        weather_status |= 4;
        break;
      }
    };                                  // time taken 1 - 2 milliseconds

    t = millis();
    i2c_WindSensor_read();
    while (getting_data) {
      delay(10);
      if ((millis() - t ) > 1000) {
        Serial.println("timeout");
        weather_status |= 8;
        // give false data
        break;
      }
    }
    sensors.rssi = WiFi.RSSI();
    sensors.temp = (int16_t)(htu.readTemperature() * 100);
    sensors.hum = (int16_t)(htu.readHumidity() * 100);
    sensors.rain = 0;
    //      if (isPOST) {
    htmlPage =
      String("HTTP/1.1 200 OK\r\n") +
      "Content-Type: text/html\r\n" +
      "Content-Length: " + String(sizeof(sensor_data)) + "\r\n" +
      "Connection: Close\r\n\r\n";
    //     }
    //      else
    //      {
    //        htmlPage =
    //          String("HTTP/1.1 200 OK\r\n") +
    //          "Content-Type: text/html\r\n" +
    //          "Pragma: no-cache\r\n" +
    //          "Connection: close\r\n\r\n" +
    //          "<meta http-equiv='refresh' content='5'/>" +
    //          "<title>RBBB server</title>" +
    //          "<h1>ESP-01 board  </h1>" +
    //          "<h2 RSSI>" + String(sensors.rssi) + "</h2>" +
    //          "<h2>" + String((double)sensors.temp / 100) + "</h2>" +
    //          "<h2>" + String((double)sensors.hum / 100) + "</h2>" +
    //          "<h2>" + String((double)sensors.wind_speed / 100) + "</h2>" +
    //          "<h2>" + String((double)sensors.peak_wind_speed / 100) + "</h2>" +
    //          "<h2>" + String(sensors.bearing) + "</h2>";
    //      }
    //    }
    //    else
    //    {
    //      int32_t s = WiFi.RSSI();
    //      htmlPage =
    //        String("HTTP/1.1 200 OK\r\n") +
    //        "Content-Type: text/html\r\n" +
    //        "Pragma: no-cache\r\n" +
    //        "\r\n" +
    //        "<meta http-equiv='refresh' content='5'/>" +
    //        "<title>RBBB server</title>" +
    //        "<h1>ESP-07 board  </h1>" +
    //        "<h2>" + String(s) + "</h2>" +
    //        "<h2>Sensor not found</h2>";
    //    }

    return htmlPage;
  }
}

  // handle HTTP request to this board
  void handle_request(WiFiClient client) {
    //  Serial.println("\n[Client connected]");
    //  while (client.connected())
    //  {
    //    // read line by line what the client (web browser) is requesting
    //    while (client.available())client.read();
    //    client.print(prepareHtmlPage(isPOST));
    //    if (isPOST) {
    //      Serial.println("s_d");
    //      int size_data = sizeof(sensor_data);
    //      byte buf[size_data];
    //      Serial.println(size_data);
    //      memcpy(&buf, &sensors, size_data);
    //      client.write((const uint8_t*)buf,size_data);
    //    client.stop();
    //    }
    //    elseif
    //    client.stop();
    //  }
    //  Serial.println("[Client disonnected]");
    //  //postData();
    Serial.println("\n[Client connected]");
    int con ;
    int len;
    int type;
    int instruction_type = 0;
    int size_data;
    while (client.connected())
    {
      // read line by line what the client (web browser) is requesting
      if (client.available())
      {
        String line = client.readStringUntil('\r');
        Serial.print(line);
        if (instruction_type == 0)
        {
          int P_loc = line.indexOf("POST");
          int G_loc = line.indexOf("GET");
          if (P_loc >= 0)instruction_type = 2;
          if (G_loc >= 0)instruction_type = 1;
        }

        switch (instruction_type) {
          case 0:
            break;
          case 1:
            type = String( line.charAt(5)).toInt();
            instruction_type = 3;
            break;
          case 2:
            type = String( line.charAt(6)).toInt();
            instruction_type = 4;
            break;
          case 3:
            type = GET_RESPONSE;
            len = 0;
            break;
          case 4:
            con = line.indexOf("Content-Length:");
            if (con >= 0) {
              String lenstr = line.substring(line.indexOf(':') + 1);
              len = lenstr.toInt();
            }
            break;

        }
        // wait for end of client's request, that is marked with an empty line
         if (line.indexOf("close") >= 0 )
        { 
          line = client.readStringUntil('\r');
          if (len > 0) {
            char c = client.read();

            for (int x = 0; x < len; x ++ ) {
              dat[x] = client.read();
              Serial.println(dat[x]);
            }
          }
          switch (type) {
            case CURRENT_DATA:
              memcpy(&c_data, &dat, 24);
              Serial.print("\n temp = "); Serial.println(c_data.in_temp);
              get_post_Data(0);
              //   data_result = "proc";
              client.println(prepareHtmlPage());
              delay(100); // give the web browser time to receive the data

              // close the connection:
              client.stop();
              break;
            case HISTORY_DATA:
              memcpy(&c_data, &dat, 32);
              // get_post_Data(1);
              data_result = "not 4";
              client.println(prepareHtmlPage());
              delay(100); // give the web browser time to receive the data
              // close the connection:
              client.stop();
              break;
            case RETURN_DATA:
            Serial.println("return data");
              size_data = sizeof(sensor_data);
              byte buf[size_data];
              Serial.println(size_data);
              client.print(prepareRemoteHtmlPage());
              memcpy(&buf, &sensors, size_data);
              client.write((const uint8_t*)buf, size_data);
              client.stop();
              break;
            case GET_RESPONSE:
              data_result = "Simple GET respnse";
              client.println(prepareHtmlPage());
              delay(100); // give the web browser time to receive the data
              // close the connection:
              client.stop();
              break;
            default:
             String HtmlPage =
                String("HTTP/1.1 200 OK\r\n") +
                "Content-Type: text/html\r\n" +
                "Pragma: no-cache\r\n" +
                "Connection: close\r\n\r\n" +
                "<meta http-equiv='refresh' content='5'/>" +
                "<title>RBBB server</title>" +
                "<h1>ESP-01 board  </h1>" +
                "<h2 RSSI>" + String(sensors.rssi) + "</h2>" +
                "<h2>" + String((double)sensors.temp / 100) + "</h2>" +
                "<h2>" + String((double)sensors.hum / 100) + "</h2>" +
                "<h2>" + String((double)sensors.wind_speed / 100) + "</h2>" +
                "<h2>" + String((double)sensors.peak_wind_speed / 100) + "</h2>" +
                "<h2>" + String(sensors.bearing) + "</h2>";
              client.println(HtmlPage);
              delay(100); // give the web browser time to receive the data
              // close the connection:
              client.stop();
              break;
          }
        }
      }
    }
  }

    // main loop of the board
    void loop() {

      //  // wait for a client (web browser) to connect
      //  WiFiClient client = server.available();
      //  if (client)
      //  {
      //
      //    String instr = client.readStringUntil('\r');
      //    Serial.println(instr);
      //    int isPOST = false;
      //    if (instr.indexOf("POST") >= 0) isPOST = true;
      //    handle_request(client, isPOST);
      //  }

      // wait for a client (web browser) to connect
      WiFiClient client = server.available();
      if (client)
      {
        handle_request(client);
      }



    }
