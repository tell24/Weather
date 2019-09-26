#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
#include "DebugMacros.h"

#define CURRENT_DATA   0
#define HISTORY_DATA   1
#define GET_RESPONSE   5

#define DEV

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


//const byte interruptPin = 5; // Pin to set interrupt to
int interruptCounter = 0; // counter of interrupt executions

//unsigned long last_sent_time = millis(); // time last counter sent to the receiver host

WiFiServer server(80); // set WiFiServer on port 80

String data_result = "";
int type = 0;


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

current c_data;
history_packet h_data;
byte dat[32];
void setup() {
  Serial.begin(115200); // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  WiFi.hostname("ESPboard-counter");
  WiFi.begin(ssid, password); // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer

  // set interrupt handler
  //pinMode(interruptPin, INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);

  // start HTTP server
  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());
}

// send data to the receiver host
void get_post_Data( int type) {
  HTTPSRedirect* clientGet = nullptr; //WiFiClient clientGet;
  // We now create and add parameters:
  String src = "ESP";
  int vint = interruptCounter;
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

// prepare a web page to be send to a client (web browser)
String prepareHtmlPage()
{
  String htmlPage =
    String("HTTP/1.1 200 OK\r\n") +
    "Content-Type: text/html\r\n" +
    "Connection: close\r\n" + // the connection will be closed after completion of the response
    "\r\n" +
    data_result;
  return htmlPage;
}

// handle HTTP request to this board
void handle_request(WiFiClient client) {
  Serial.println("\n[Client connected]");
  int con ;
  int len;
  int instruction_type = 0;
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
      if (line.length() == 1 && line[0] == '\n')
      {
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
            Serial.print("\n temp = ");Serial.println(c_data.in_temp);
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
             case GET_RESPONSE:            
            data_result = "Simple GET respnse";
            client.println(prepareHtmlPage());
            delay(100); // give the web browser time to receive the data   
            // close the connection:
            client.stop();
            break;
        }
      }

    }



  }

  Serial.println("[Client disonnected]");
  //postData();
}

// main loop of the board
void loop() {

  // wait for a client (web browser) to connect
  WiFiClient client = server.available();
  if (client)
  {
    handle_request(client);
  }

}
