#ifndef BCBAWS
#define BCBAWS
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "State.h"
//#include <HTTPClient.h>



class BcbAws{
  public:
BcbAws();  
void BcbAwsInit(State*istate);
AsyncWebServer server = AsyncWebServer(80);
AsyncWebSocket ws = AsyncWebSocket("/ws");

void parseCommand(String command);
void notifyClients();
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
void deleteFile(fs::FS &fs, const char * path);
void renameFile(fs::FS &fs, const char * path1, const char * path2);
String readFile(fs::FS &fs, const char * path);
void writeFile(fs::FS &fs, const char * path, const char * message);
void appendFile(fs::FS &fs, const char * path, const char * message);

  private:
  State* state;
};
#endif
