#include <SparkFunHTU21D.h>

#include <SFE_BMP180.h>


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


HTU21D th;
SFE_BMP180 pressure;

int my_pressure;
#define ALTITUDE 70.0 // altitude at home
double temp, hum, old_temp = 0, old_hum = 0;

long data_time = 0;
int http_status = 0;
int data_status = 0;

String body = "";

volatile boolean measure = false;
volatile boolean  update_inside_data = false;
uint32_t interval_milli_sec = 800000;
volatile byte tick = 0;
volatile int    interval_set = 1000;

void inline timer0_ISR (void) {
  //Serial.println(millis());
  if (tick == 0) {
    tick++;
    measure = true;
    timer0_write(ESP.getCycleCount() + (interval_milli_sec * interval_set ));
    return;
  }

  if (tick == 1) {
    update_inside_data = true;
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

int send_data(String data)
{
  // Use HTTPSRedirect class to create a new TLS connection
  client = new HTTPSRedirect(httpsPort);
  client->setTimeout(10000); // 15 Seconds
  client->setInsecure();
  client->setPrintResponseBody(true);
  client->setContentTypeHeader("application/json");

  //    Serial.print("Connecting to ");
  //    Serial.print(host);
  //    Serial.print("  ");
  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    int retval = client->connect(host, httpsPort);
    if (retval == 1) {
      flag = true;
      break;
    }
    //   else
    //      Serial.println("Connection failed. Retrying...");
  }

  if (!flag) {
    //      Serial.print("Could not connect to server: ");
    //      Serial.println(host);
    //      Serial.println("Exiting...");
    return 0;
  }
  // fetch spreadsheet data
  //   Serial.println(host + url + dataString);
  client->GET(url + data, host);

  ESP.getFreeHeap();
  ESP.getFreeContStack();

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
  //  Serial.begin(115200);
  //  Serial.flush();
  inputString.reserve(200);
  free_heap_before = ESP.getFreeHeap();
  free_stack_before = ESP.getFreeContStack();
  //  Serial.printf("Free heap: %u\n", free_heap_before);
  //  Serial.printf("Free stack: %u\n", free_stack_before);

  //  Serial.println();
  //  Serial.print("Connecting to wifi: ");
  //  Serial.println(ssid);
  // flush() is needed to print the above (connecting...) message reliably,
  // in case the wireless connection doesn't go through
  // Serial.flush();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //    Serial.print(".");
  }
  //  Serial.println("");
  //  Serial.println("WiFi connected");
  //  Serial.println("IP address: ");
  //  Serial.println(WiFi.localIP());


  Wire.begin(0, 2);

  if (pressure.begin()) {
    //  Serial.println("BMP180 init success");
  }
  else
  {
    //   Serial.println("BMP180 init fail\n\n");
  }
  th.begin();
  my_pressure = i2c_Pressure_read();
  hum = th.readHumidity();
  temp = th.readTemperature();
  String dataString = "inside," + String(temp) + "," + String(hum) + ","
                      + String(my_pressure)  + "," + String(data_status);
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
  // print the string when a newline arrives:

  if (  measure ) {
    measure = false;
    int repeat = 3;
    do {
      hum = th.readHumidity();
      temp = th.readTemperature();
      if ((hum != 998) && (temp != 998))
      {
        data_status = 0;
        break;
      }
      repeat--;
      if (hum == 998) {
        data_status |= 1;
        hum =  old_hum;
      }
      if (temp == 998) {
        data_status |= 2;
        temp = old_temp;
      }
    } while (repeat > 0);
    if (hum > 100)hum = 99.9;
    old_temp = temp;
    old_hum = hum;

    my_pressure = i2c_Pressure_read();
  }

  if ( update_inside_data) {
    update_inside_data = false;
    String dataString = "inside," + String(temp) + "," + String(hum) + ","
                        + String(my_pressure)  + "," + String(data_status);


    send_data( dataString);

    dataString = "";
  }

}
