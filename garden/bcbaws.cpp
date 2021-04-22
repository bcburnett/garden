#include"bcbaws.h"
#include<FS.h>
#include<SPIFFS.h>
BcbAws::BcbAws() {}
void BcbAws::BcbAwsInit(State* istate) {
  state = istate;
  SPIFFS.begin(true);
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
  ws.textAll(state->getJSON());  // send non-slider updating data
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
    state->relay(!state->relay());
    digitalWrite(2, state->relay());
    notifyClients();
  }
  // file upload handler

  if (command.substring(0, 4) == "upld") {
    state->filename(command.substring(5));
    deleteFile(SPIFFS, "/temp.txt");
  }

  if (command.substring(0, 4) == "comp") {
    deleteFile(SPIFFS, ("/" + state->filename()).c_str());
    renameFile(SPIFFS, "/temp.txt", ("/" + state->filename()).c_str());
    state->filename("");
  }

  if (command.substring(0, 4) == "file") {
    String message = command.substring(5);
    appendFile(SPIFFS, "/temp.txt", message.c_str());
  }

  if (command == "reload") {
    state->reload(true);
    notifyClients();
    state->reload(false);
  }
}

void BcbAws::appendFile(fs::FS &fs, const char * path, const char * message) {

  File file = fs.open(path, FILE_APPEND);

  if (!file) {
    return;
  }
  file.print(message);
  file.close();


}

void BcbAws::writeFile(fs::FS &fs, const char * path, const char * message) {

  File file = fs.open(path, FILE_WRITE);

  if (!file) {
    return;
  }
  file.print(message);
  file.close();


}
String BcbAws::readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return "";
  }
  String result;
  Serial.println("- read from file:");
  while (file.available()) {
    result += String(char(file.read()));
  }
  file.close();
  return result;
}

void BcbAws::renameFile(fs::FS &fs, const char * path1, const char * path2) {

  fs.rename(path1, path2);
}

void BcbAws::deleteFile(fs::FS &fs, const char * path) {

  fs.remove(path);

}
