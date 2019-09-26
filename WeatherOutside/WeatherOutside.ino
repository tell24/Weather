#include <SparkFunHTU21D.h>
#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
#include "DebugMacros.h"
#include <Wire.h>

#define DEV 
// Fill ssid and password with your network credentials
const char* ssid =  "SKY4B6A5";
const char* password = "RDFDZPDP";
// google script file
//https://script.google.com/macros/s/AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun/exec?read=current
//Hodt address
const char* host = "script.google.com";

// google script id
//const char *GScriptId = "AKfycbwdejyp_XqafKDG_xJcFKxqEyWAXvYHaymh-oKUXyql0bcqRyk";
//

//port
const int httpsPort = 443;

// Write to Google Spreadsheet
//String url = String("/macros/s/") + GScriptId + "/exec?value=";
#ifdef DEV
const char *GScriptId = "AKfycbyh3Hsl6u0REhLq2A0Wkz7x2RtXZq0D373nVmTsL9w";
String url = String("/macros/s/") + GScriptId + "/dev?value=Testing";
#else
//const char *GScriptId = "AKfycbznD66uT9RcicnAhSnAuAherAwO9iQ7hssPCfJfrQW3auBDEJ0";
//String url = String("/macros/s/") + GScriptId + "/exec?value=Testing";
#endif

String payload_base =  "{\"command\": \"appendRow\", \
                    \"sheet_name\": \"Sheet1\", \
                    \"values\": ";
String payload = "";

String inputString = "";         // a String to hold incoming data

HTTPSRedirect* client = nullptr;

unsigned int free_heap_before = 0;
unsigned int free_stack_before = 0;
int http_status = 0;
String body = "";
String dataString = "";

HTU21D th;

int tx_pin = 16;
byte channel = 3;
double     temp, hum, old_temp = 0, old_hum = 0;


uint32_t interval_milli_sec = 800000;
volatile byte tick = 0;
volatile int    interval_set = 1000;
volatile int      weather_status = 0;
volatile int      rain ;

volatile boolean measure = false;
volatile boolean  update_outside_data = false;
volatile boolean getting_data = false;
volatile boolean  update_froggy_data = false;


double  wind_speed = 0;
double  peak_wind_speed = 0;
int  bearing = 0;

typedef struct data_packet_1 {
  int16_t status;
  uint16_t wind_speed;
  uint16_t peak_wind_speed;
  uint16_t bearing;
  unsigned char checksum;
} remotedata;

remotedata remote_data;


void inline timer0_ISR (void) {
  //Serial.println(millis());
  if (tick == 0) {
    tick++;
    measure = true;
    timer0_write(ESP.getCycleCount() + (interval_milli_sec * interval_set ));
    return;
  }

  if (tick == 1) {
    update_froggy_data = true;
    tick++;
    timer0_write(ESP.getCycleCount() + (interval_milli_sec * interval_set ));
    return;
  }

  if (tick == 3) {
    update_outside_data = true;
    tick++;
    timer0_write(ESP.getCycleCount() + (interval_milli_sec * interval_set ));
    return;
  }

  if (tick >= 5) {
    tick = 0;
    timer0_write(ESP.getCycleCount() + (interval_milli_sec * interval_set ));
    return;
  }

  tick++;
  timer0_write(ESP.getCycleCount() + (interval_milli_sec * interval_set ));
}

byte Sum(byte  * message, int nBytes)
{
  uint8_t  sum = 0;


  while (nBytes-- > 0)
  {
    sum += *(message++);
  }

  return (sum);

}   /* Sum() */

boolean i2c_RainSensor_read()
{
  byte buf[3];
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
}


void i2c_WindSensor_read() {
  //  Serial.println("request wind");
  //  getting_data = true;
  //  byte s_buf[7];
  //  requestdata.type = 6;
  //  requestdata.temp = sensor_data.temp;
  //  requestdata.hum = sensor_data.hum;
  //  memcpy(s_buf, &requestdata, 6);
  //  s_buf[6] = Sum(s_buf, 8);
  //  Wire.beginTransmission(32); // transmit to device #16
  //  Wire.write(s_buf, 9);
  //  Wire.endTransmission();     // stop transmitting
  //  delay(1);
  //  byte buf[10];
  //  int c = 0;
  //  Wire.requestFrom(32, 9);    // request 3 bytes from slave device #16
  //  while (Wire.available()) { // slave may send less than requested
  //    buf[c] = Wire.read(); // receive a byte as character buf[c] = Wire.read(); // receive a byte as character
  //
  //    c++;
  //  }
  //  if (buf[6] == Sum(buf, 6))
  //  {
  //    memcpy(&remote_data, buf, 9);
  //    if (remote_data.status == 0) {
  //      wind_speed = (double)remote_data.wind_speed / 100;
  //      peak_wind_speed = (double)remote_data.peak_wind_speed / 100;
  //      bearing = remote_data.bearing;
  //    }
  //    else {
  //      wind_speed = 0;
  //      peak_wind_speed = 0;
  //      bearing = 0;
  //
  //    }
  //  }
  getting_data = false;
}


void clock_pulse() {
  digitalWrite(tx_pin, HIGH);
  delayMicroseconds(500);
  digitalWrite(tx_pin, LOW);
}


void  send_start() {
  clock_pulse();   delay(4);

}

void send_byte(byte dat)
{
  int shift = 0;
  byte res = 0;
  do {
    res = (dat << shift);
    clock_pulse();
    if ((res & 0x80) == 0x80)
      delay(2); else delay(1);
    shift++;
  } while (shift < 8);
}
void  send_nibble(byte nib)
{
  int shift = 0;
  byte res = 0;
  do {
    res = nib << shift;
    clock_pulse();

    if ((res & 0x08) == 0x08) delay(2); else  delay(1);
    shift++;
  } while (shift < 4);
}


void Send_Froggy_Data() {
  int rep = 10;
  do {
    send_start();
    send_byte(170);
    byte ch = 0x08 >> (channel - 1);
    send_nibble(ch);
    int temperature = (int) (temp * 10);
    byte th = (temperature >> 8) & 0x0f;
    byte tl = temperature  & 0xff;
    send_nibble(th);
    send_byte(tl);
    send_nibble(0x0f);
    send_byte((byte)hum);
    rep--;
  } while (rep > 0);
  clock_pulse();
}


int send_data(String data)
{
  // Use HTTPSRedirect class to create a new TLS connection
  client = new HTTPSRedirect(httpsPort);
  client->setTimeout(10000); // 15 Seconds
 //client->setInsecure();
  client->setPrintResponseBody(true);
  client->setContentTypeHeader("application/json");

      Serial.print("Connecting to ");
      Serial.print(host);
      Serial.print("  ");
  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    int retval = client->connect(host, httpsPort);
    if (retval == 1) {
      flag = true;
      break;
    }
       else
          Serial.println("Connection failed. Retrying...");
  }

  if (!flag) {
          Serial.print("Could not connect to server: ");
          Serial.println(host);
          Serial.println("Exiting...");
    return 0;
  }
  // fetch spreadsheet data
     Serial.println(host + url + dataString);
  client->GET(url + data, host);

 // ESP.getFreeHeap();
//  ESP.getFreeContStack();

  http_status = client->getStatusCode();
  body = client->getResponseBody();
  // delete HTTPSRedirect object
  delete client;
  client = nullptr;                             //  time taken 3.6 seconds
  //Serial.print("body = ");
  //Serial.println(body);
  if (body == "fail") return 0;
  return (int) body.toInt();
}

void setup() {
  Serial.begin(115200);
  Serial.flush();
  inputString.reserve(200);
 // free_heap_before = ESP.getFreeHeap();
//  free_stack_before = ESP.getFreeContStack();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  //  Serial.println("");
  //  Serial.println("WiFi connected");
  //  Serial.println("IP address: ");
  //  Serial.println(WiFi.localIP());
  Wire.begin(13, 12);
  th.begin();
  delay(1000);
  pinMode(tx_pin, OUTPUT);

  hum = th.readHumidity();
  temp = th.readTemperature();
  String dataString = "outside," + String(temp) + "," + String(hum) + ","
                      + String(0)  + "," + String(0)  + "," + String(0)  + ","
                      + String(0)  + "," + String(weather_status);
  int del = send_data( dataString);

  if (del < 60) tick = 1 + (int)(del / 10); else tick = 0;
  //     Serial.print("tick = "); Serial.println(tick);
  noInterrupts();
  timer0_isr_init();
  timer0_attachInterrupt(timer0_ISR);
  timer0_write(ESP.getCycleCount() + interval_milli_sec * interval_set );
  interrupts();
}

void loop() {

  if (  measure ) {
    measure = false;
    weather_status = 0;
    int repeat = 3;
    do {
      hum = th.readHumidity();
      temp = th.readTemperature();
      if ((hum != 998) && (temp != 998))
      {
        break;
      }
      repeat--;
      if (hum == 998) {
        weather_status |= 1;
        hum =  old_hum;
      }
      if (temp == 998) {
        weather_status |= 2;
        temp = old_temp;
      }
    } while (repeat > 0);
    if (hum > 100)hum = 99.9;
    old_temp = temp;
    old_hum = hum;

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

    //    t = millis();
    //    i2c_WindSensor_read();
    //    while (getting_data) {
    //      delay(10);
    //      if ((millis() - t ) > 1000) {
    //        Serial.println("timeout");
    //        weather_status |= 8;
    //        // give false data
    //        break;
    //      }
  }
  if ( update_froggy_data) {
    update_froggy_data = false;
    Send_Froggy_Data();
  }
  if ( update_outside_data) {
    update_outside_data = false;
    dataString = "outside," + String(temp) + "," + String(hum) + ","
                 + String(wind_speed)  + "," + String(peak_wind_speed)  + "," + String(bearing)  + ","
                 + String(rain)  + "," + String(weather_status);
    send_data( dataString);

    dataString = "";
  }
}
