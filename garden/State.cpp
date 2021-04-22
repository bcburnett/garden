#include"State.h"

int State::moisture() {
      int avg = 0;
      for (int num = 0; num <= 9; num++) {
        avg += analogRead(32);
      }
      jsonMap["moisture"] = String(avg / 10);
      return avg / 10;
    }


    int State::threshold() {
      return jsonMap["threshold"].toInt();
    };
    
    int State::threshold(int value) {
      jsonMap["threshold"] = String(value);
      return jsonMap["threshold"].toInt();
    };
    

    String State::filename() {
      return jsonMap["filename"];
    };
    
    String State::filename(String value) {
      jsonMap["filename"] = value;
      return jsonMap["filename"];
    };


    bool State::setOta (bool value) {
      ota = value;
      return ota;
    };
    
    bool State::getOta () {
      return ota;
    };


    bool State::reload() {
      return (jsonMap["reload"] == "true");
    };
    
    bool State::reload(bool value) {
      jsonMap["reload"] = value ? "true" : "false";
      return (jsonMap["reload"] == "true");
    };


    bool State::relay() {
      return (jsonMap["relay"] == "true");
    };
    
    bool State::relay(bool value) {
      jsonMap["relay"] = value ? "true" : "false";
      return (jsonMap["relay"] == "true");
    };


    String State::getJSON() {
      moisture();
      String json = "{";
      String quote = "\"";
      for (auto const x : jsonMap) {
        if (json.length() > 3) json += ",";
        json += quote + x.first + quote + ":" + quote + x.second + quote;
      };
      json += "}";
      Serial.println(json);
      return json;
    }
