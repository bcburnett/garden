#pragma once
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "State.h"
#include "defaulthtml.h"

class BcbAws {
  public:
    BcbAws();
    AsyncWebSocket ws = AsyncWebSocket("/ws");
    void BcbAwsInit(State*istate);
    void notifyClients();

  private:
    AsyncWebServer server = AsyncWebServer(80);
    void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);
    void parseCommand(String command);
    void checkForIndex();
    State* state;
};
