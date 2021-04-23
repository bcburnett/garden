/*
* Garden sensor sketch
* File: bcbaws.h
* Author: Brian C. Burnett
* GitHub repo: https://github.com/bcburnett/garden
* Directory: https://github.com/bcburnett/garden/tree/master/garden
* Questions: https://github.com/bcburnett/garden/discussions/1
* 
* The relay for the water solenoid is connected to pin 2 of the esp32 
*   to give a visual indicator .
*   
* The capacitive moisture sensor analog output is connected to pin 32.
* 
* This application is in the Public Domain.
* All information is provided in good faith, however I make no representation 
* or warranty of any kind, express or implied, regarding the accuracy, adequacy, 
* validity, reliability, availability or completeness of this application.
 */
 
#pragma once
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "State.h"
#include "defaulthtml.h"

class BcbAws {
  public:
    BcbAws(); // blank constructor
    AsyncWebSocket ws = AsyncWebSocket("/ws"); // websocket server
    void BcbAwsInit(State*istate); // class initialization with refrence to state
    void notifyClients(); // notify clients with a json representation of state

  private:
    AsyncWebServer server = AsyncWebServer(80); // web server
    void handleWebSocketMessage(void *arg, uint8_t *data, size_t len); // invoked on websocket message received
    void parseCommand(String command); // parse received commands from websockets
    void checkForIndex(); // check if index.htm exists, if not, create it and populate with the contents of defaulthtml.h
    State* state;
};
