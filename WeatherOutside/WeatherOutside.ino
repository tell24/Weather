#include <SparkFunHTU21D.h>
#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
#include "DebugMacros.h"
#include <Wire.h>

// Fill ssid and password with your network credentials
const char* ssid =  "SKY4B6A5";
const char* password = "RDFDZPDP";
// google script file
//https://script.google.com/macros/s/AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun/exec?read=current
//Hodt address
const char* host = "script.google.com";

// google script id
const char *GScriptId = "AKfycbzep_6TONHLbfjt1H23_iCb0DMc126LPo3smsun";

//port
const int httpsPort = 443;

// Write to Google Spreadsheet
String url = String("/macros/s/") + GScriptId + "/exec?value=";
String url1 = String("/macros/s/") + GScriptId + "/exec?value=Testing";

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
int del = 30;

HTU21D th;

int tx_pin = 16;
byte channel = 3;
double            temp, hum;

volatile int      sec_interval = 1000;
volatile int      weather_status = 0;
volatile int      rain ;
volatile boolean getting_data = false;


typedef struct data_packet_1 {
  int16_t status;
  uint16_t wind_speed;
  uint16_t peak_wind_speed;
  uint16_t bearing;
  unsigned char checksum;
} remotedata;

remotedata remote_data;


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
  //      sensor_data.wind_speed = remote_data.wind_speed;
  //      sensor_data.peak_wind_speed = remote_data.peak_wind_speed;
  //      sensor_data.bearing = remote_data.bearing;
  //    }
  //    else {
  //      sensor_data.wind_speed = 0;
  //      sensor_data.peak_wind_speed = 0;
  //      sensor_data.bearing = 0;
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

void setup() {
  Serial.begin(115200);
  Serial.flush();
  inputString.reserve(200);
  free_heap_before = ESP.getFreeHeap();
  free_stack_before = ESP.getFreeContStack();

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
}

void loop() {

  hum = th.readHumidity();
  temp = th.readTemperature();         // time taken 72 - 73 milliseconds

  long t = millis();
  getting_data = true;
  if (!i2c_RainSensor_read()) weather_status |= 2;
  while (getting_data) {
    delay(10);
    if ((millis() - t ) > 1000) {
      weather_status |= 2;
      break;
    }
  };                                  // time taken 1 - 2 milliseconds

  //    t = millis();
  //    i2c_WindSensor_read();
  //    while (getting_data) {
  //      delay(10);
  //      if ((millis() - t ) > 1000) {
  //        Serial.println("timeout");
  //        weather_status |= 4;
  //        // give false data
  //        break;
  //      }

  delay(1000);
  Send_Froggy_Data();
  delay(3000);

  dataString = "outside," + String(temp) + "," + String(hum) + ",0,0,0," + String(rain);

  // Use HTTPSRedirect class to create a new TLS connection
  client = new HTTPSRedirect(httpsPort);
  client->setTimeout(10000); // 10 Seconds
  client->setInsecure();
  client->setPrintResponseBody(true);
  client->setContentTypeHeader("application/json");

  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    int retval = client->connect(host, httpsPort);
    if (retval == 1) {
      flag = true;
      break;
    }
  }

  if (!flag) {
    //      Serial.print("Could not connect to server: ");
    //      Serial.println(host);
    //      Serial.println("Exiting...");
    return;
  }
  // fetch spreadsheet data
  //  Serial.println(host + url + dataString);
  client->GET(url + dataString, host);

  ESP.getFreeHeap();
  ESP.getFreeContStack();

  http_status = client->getStatusCode();
  body = client->getResponseBody();
  // delete HTTPSRedirect object
  delete client;
  client = nullptr;                             //  time taken 3.6 seconds

  if (http_status == 200)
    del = ((60 - body.toInt()) + 30) * sec_interval;
  else
    del = 10 * sec_interval;
  // clear the string:
  dataString = "";
  delay(del);
}
