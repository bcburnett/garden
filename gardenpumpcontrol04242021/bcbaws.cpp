/*
* Garden sensor sketch
* File: bcbaws.cpp
* Author: Brian C. Burnett
* GitHub repo: https://github.com/bcburnett/garden
* Directory: https://github.com/bcburnett/garden/tree/master/garden
* Questions: https://github.com/bcburnett/garden/discussions/1
* 
* This application is in the Public Domain.
* All information is provided in good faith, however I make no representation 
* or warranty of any kind, express or implied, regarding the accuracy, adequacy, 
* validity, reliability, availability or completeness of this application.
 */
 
#include"bcbaws.h"

BcbAws::BcbAws() {}

void BcbAws::BcbAwsInit(BcbAwsState* istate) {
  state = istate;
  SPIFFS.begin(true);
  delay(50);
  checkForIndex();
  delay(50);

  // send home page from spiffs
  server.on("/", HTTP_GET, [ = ](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.htm", "text/html");
  });
  
  // send config page from spiffs
  server.on("/config", HTTP_GET, [ = ](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/config.htm", "text/html");
  });

  // send json representation of state (api endpoint)
  server.on("/json", HTTP_GET, [ = ](AsyncWebServerRequest * request) {
    request->send(200, "application/json", state->getJSON());
  });
  
  // start the web server
  server.begin();

  // configure the websocket server
  ws.onEvent([ = ](AsyncWebSocket * server, AsyncWebSocketClient * client,
  AwsEventType type, void *arg, uint8_t *data, size_t len) {
    switch (type) {
      case WS_EVT_CONNECT:
        notifyClients();
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
  });

  // apply the websocket handler to the webserver
  server.addHandler(&ws);
}

void BcbAws::notifyClients() {
  ws.textAll(state->getJSON());  // send the state to the clients as json
}

void BcbAws::handleWebSocketMessage(void *arg, uint8_t *data, size_t len) { // receive the comm from the client and convert it into a string
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len &&
      info->opcode == WS_TEXT) {
    data[len] = 0;
    parseCommand((char *)data);
  }
}


void BcbAws::parseCommand(String command) {    // parse the command from the client

  if (command == "relay") {
    digitalWrite(2, state->relay(!state->relay())); // turn on or off and set state
    notifyClients();
  }
  // file upload handler

  if (command.substring(0, 4) == "upld") {   // get the name of the file
    state->filename(command.substring(5));
    SPIFFS.remove("/temp.txt");
  }

  if (command.substring(0, 4) == "comp") {   // finalize the upload, rename temp.txt to the filename
    SPIFFS.remove(("/" + state->filename()).c_str());
    SPIFFS.rename("/temp.txt", ("/" + state->filename()).c_str());
    state->filename("");
  }

  if (command.substring(0, 4) == "file") {   //append received data to temp.txt
    String message = command.substring(5);
    File file = SPIFFS.open("/temp.txt", FILE_APPEND);
    file.print(message.c_str());
    file.close();

  }

  if (command == "reload") {    //send a reload message to the clients
    state->reload(true);
    notifyClients();
    state->reload(false);
  }
}

void BcbAws::checkForIndex() {  // check for and optionally create index.htm in spiffs
  if (SPIFFS.exists("/index.htm")) return; //
  delay(50);
  File file = SPIFFS.open("/index.htm", FILE_WRITE);
  file.print(htmlCode);
  file.close();
}
