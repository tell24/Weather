#include <SparkFunHTU21D.h>
#include <SFE_BMP180.h>
#include <ESP8266WiFi.h>
#include "HTTPSRedirect.h"
#include "DebugMacros.h"
#include <Wire.h>


HTU21D th;
SFE_BMP180 pressure;

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
int del = 30;
int sec_interval = 1000;

double temp, hum;

String body = "";
String dataString = "";

int my_pressure;
#define ALTITUDE 70.0 // altitude at home



int i2c_Pressure_read()
{
  // pressure BMP180
  char status;
  double T = 0, P = 0;
  status = pressure.startTemperature();
  if (status != 0)
  {
    delay(status);
    status = pressure.getTemperature(T);
    if (status != 0)
    {
      status = pressure.startPressure(3);
      if (status != 0)
      {
        delay(status);
        status = pressure.getPressure(P, T);
        if (status != 0)
        {
          //      sensor_data.inside_temp = (int)(T * 10);
          return (int) pressure.sealevel(P, ALTITUDE);
        }
      }
    }
  }
  return 0;
}

void setup() {
 //Serial.begin(115200);
 // Serial.flush();
  inputString.reserve(200);
  free_heap_before = ESP.getFreeHeap();
  free_stack_before = ESP.getFreeContStack();
//  Serial.printf("Free heap: %u\n", free_heap_before);
//  Serial.printf("Free stack: %u\n", free_stack_before);
//
//  Serial.println();
//  Serial.print("Connecting to wifi: ");
//  Serial.println(ssid);
  // flush() is needed to print the above (connecting...) message reliably,
  // in case the wireless connection doesn't go through
 // Serial.flush();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  // Serial.print(".");
  }
//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());

  Wire.begin(0, 2);

  if (pressure.begin()) {
    Serial.println("BMP180 init success");
  }
  else
  {
    Serial.println("BMP180 init fail\n\n");
  }
  
  th.begin();
  
  my_pressure = i2c_Pressure_read();
  delay(1000);
  
}


void loop() {
  
  
    hum = th.readHumidity();
    temp = th.readTemperature();
    
    my_pressure = i2c_Pressure_read();

    delay(5000);
    
    dataString = "inside," + String(temp) + "," + String(hum) + "," + String(my_pressure);

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
    //   Serial.println(host + url + dataString);
    client->GET(url + dataString, host);

    ESP.getFreeHeap();
    ESP.getFreeContStack();

    
  http_status = client->getStatusCode();
  body = client->getResponseBody();
  // delete HTTPSRedirect object
  delete client;
  client = nullptr;                             //  time taken 3.6 seconds
//Serial.println(body);
  if (http_status == 200)
    del = ((60 - body.toInt()) + 10) * sec_interval;
  else
    del = 10 * sec_interval;
  // clear the string:
  dataString = "";
  delay(del);
}
