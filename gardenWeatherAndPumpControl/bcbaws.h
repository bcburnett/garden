#ifndef BCBAWS
#define BCBAWS
#include <Arduino.h>
#include "ArduinoJson.h"
#include "AsyncJson.h"
#include <ESPAsyncWebServer.h>
#include "bcbsdcard.h"
#include <SPIFFS.h>
#include "State.h"
#include <HTTPClient.h>



// define functions
String getJson(bool b);
void parseCommand(String command);
void notifyClients();
void notifyInitialClients(const String msg);
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
void initWebSocket();
void initWebServer();
void updateDB();

// web server variables
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");
// web client
HTTPClient http;
char req[450];
StaticJsonDocument<250> data;

void notifyClients() {
  ws.textAll(getJson(false));  // send non-slider updating data
}

void notifyInitialClients(const String msg) {
  ws.textAll(msg);  // send slider updating data
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) { // receive the comm from the client and convert it into a string
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len &&
      info->opcode == WS_TEXT) {
    data[len] = 0;
    parseCommand((char *)data);
  }
}


// handle websocket connections
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
             AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      notifyInitialClients(getJson(true));
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

// init websockets
void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

// init webserver
void initWebServer() {
  // Route for root / web page served from spiffs
  // TODO add routines for dynamically updating index.htm
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.htm", "text/html");
  });  
  
  server.on("/json", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "application/json", state.json);
  });
  // start the web server
  server.begin();
}



// convert state to json
String getJson(bool b) {
  
//  struct State {   
//  float humidity;
//  float pressure;
//  double pressure64;
//  float temp;
//  float dew () {
//    return  temp - ((100 - humidity) / 5.);
//  }
//  String filename;
//  bool reload;
//  String json;
//  bool ota;
//};

  data["temperature"] = state.temp;
  data["humidity"] = state.humidity;
  data["pressure"] = state.pressure;
  data["dew"] = state.dew();
  data["relay"] = state.relay;
  data["status"] = state.status;
  if (b) {
    data["initial"] = "true";
  }
  if (state.reload) {
    data["reload"] = "true";
    state.reload = false;
  }

  String response;
  serializeJson(data, response);
  state.json = response;
  writeFile(SPIFFS, "/data.json", state.json.c_str());
  return response;
}

//parse the command coming from the client(s)
void parseCommand(String command) {
  Serial.println(command);
  if (command == "relay") {
    state.relay = !state.relay;
    digitalWrite(2,state.relay);
    notifyClients();
  }
  // file upload handler

  if (command.substring(0, 4) == "upld") {
    state.filename = command.substring(5);
    deleteFile(SPIFFS, "/temp.txt");
  }

  if (command.substring(0, 4) == "comp") {
    deleteFile(SPIFFS, ("/" + state.filename).c_str());
    renameFile(SPIFFS, "/temp.txt", ("/" + state.filename).c_str());
    state.filename = "";
  }

  if (command.substring(0, 4) == "file") {
    String message = command.substring(5);
    appendFile(SPIFFS, "/temp.txt", message.c_str());
  }

  if (command == "reload") {
    notifyClients();
  }
}

void updateDB(){
      Serial.println("[HTTP] begin...\n");
      strcpy(req, ("http://192.168.1.177/~brian/esp32/mysql-data-logger/garden.php?temp=" + String(state.temp) + "&press=" + String(state.pressure) + "&p64=" + String(state.pressure64) + "&humid=" + String(state.humidity)).c_str());
      Serial.println(String(state.temp));
      Serial.println(String(state.pressure));
      Serial.println(String(state.pressure64));
      Serial.println(String(state.humidity));
      Serial.println(String(req));
      http.begin(req); //HTTP

      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }




#endif
