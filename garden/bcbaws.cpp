#include"bcbaws.h"

BcbAws::BcbAws() {}

void BcbAws::BcbAwsInit(State* istate) {
  state = istate;
  SPIFFS.begin(true);
  delay(50);
  checkForIndex();
  delay(50);
  server.on("/", HTTP_GET, [ = ](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.htm", "text/html");
  });

  server.on("/config", HTTP_GET, [ = ](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/config.htm", "text/html");
  });

  server.on("/json", HTTP_GET, [ = ](AsyncWebServerRequest * request) {
    request->send(200, "application/json", state->getJSON());
  });
  // start the web server
  server.begin();
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


void BcbAws::parseCommand(String command) {

  if (command == "relay") {
    digitalWrite(2, state->relay(!state->relay()));
    notifyClients();
  }
  // file upload handler

  if (command.substring(0, 4) == "upld") {
    state->filename(command.substring(5));
    SPIFFS.remove("/temp.txt");
  }

  if (command.substring(0, 4) == "comp") {
    SPIFFS.remove(("/" + state->filename()).c_str());
    SPIFFS.rename("/temp.txt", ("/" + state->filename()).c_str());
    state->filename("");
  }

  if (command.substring(0, 4) == "file") {
    String message = command.substring(5);
    File file = SPIFFS.open("/temp.txt", FILE_APPEND);
    file.print(message.c_str());
    file.close();

  }

  if (command == "reload") {
    state->reload(true);
    notifyClients();
    state->reload(false);
  }
}

void BcbAws::checkForIndex() {
  if (SPIFFS.exists("/index.htm")) return; //
  delay(50);
  File file = SPIFFS.open("/index.htm", FILE_WRITE);
  file.print(htmlCode);
  file.close();
}
