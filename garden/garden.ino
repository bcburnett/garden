#include <Arduino.h>
#include "State.h"
#include "time.h"
#include "WiFiCred1.h"
#include <ArduinoOTA.h>
#include <ESPmDNS.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "bcbaws.h"

#define ARDUINO_RUNNING_CORE 1

State state;
BcbAws aws;

// internal rtc variables
const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -18000;
const int daylightOffset_sec = 3600;
bool wifiavail = false;

// define functions
void UpdateClients(void *pvParameters);
void initWiFi();
void initTime();
void setup();
void loop();
void checkForIndex();
String printLocalTime();
String printLocalHour();


// localtime from internal rtc
String printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return ("");
  }
  return (asctime(&timeinfo));
}

String printLocalHour() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    return ("");
  }
  return (String(asctime(&timeinfo)).substring(11, 16) + " ");
}

void setup() {
  Serial.begin(115200);
  delay(500);
  initWiFi();
  initTime();
  aws.BcbAwsInit(&state);
  digitalWrite(2, LOW);
  pinMode(2, OUTPUT);
  state.relay(false);

  xTaskCreatePinnedToCore(UpdateClients, // function name
    "updateClients",                     // name for humans
    1024,                                // This stack size can be checked & adjusted by reading the Stack Highwater
    NULL,                                // task input parameter
    2,                                   // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    NULL,                                // task handle
    ARDUINO_RUNNING_CORE);               // Core

  ArduinoOTA
  .onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";
    SPIFFS.end();// NOTE: if updating SPIFFS this would be the place to unmount SPIFFS
    aws.ws.enable(false);// Disable client connections
    aws.ws.textAll("OTA Update Started");// Advertise connected clients what's going on
    aws.ws.closeAll();// Close them
    state.setOta(true);
  });
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle(); // check if an update is available
  if (WiFi.status() != WL_CONNECTED) // check if wifi is still connected, if not, reconnect
    initWiFi();
  vTaskDelay(60);
}

void UpdateClients(void *pvParameters) { // handle websocket and oled displays
  (void)pvParameters;
  for (;;) {
    if (!state.getOta()) {
      aws.notifyClients(); // send state to the client as a json string
    }
    vTaskDelay(10000);
  }
}

void initWiFi() {
  Serial.println("connecting to wifi");
  // connect to wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("connecting to wifi failed");
    delay(500);
    initWiFi();
  }
  Serial.println("wifi connected");
  wifiavail = true;
}

void initTime() {
  // set the clock from ntp server
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
}
