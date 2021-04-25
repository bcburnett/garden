/*
* Garden sensor sketch
* File: State.cpp
* Author: Brian C. Burnett
* GitHub repo: https://github.com/bcburnett/garden
* Directory: https://github.com/bcburnett/garden/tree/master/garden
* Questions: https://github.com/bcburnett/garden/discussions/1
* 
* 
* This application is in the Public Domain.
* All information is provided in good faith, however I make no representation 
* or warranty of any kind, express or implied, regarding the accuracy, adequacy, 
* validity, reliability, availability or completeness of this application.
 */

#include"State.h"


float State::humidity(){
  return jsonMap["humidity"].toFloat();
  };
  
float State::humidity(float value){
  jsonMap["humidity"] = String(value,2);
  return jsonMap["humidity"].toFloat();
  };

float State::pressure(){
  return jsonMap["pressure"].toFloat();
  };
  
float State::pressure(float value){
  jsonMap["pressure"] = String(value,2);
  return jsonMap["pressure"].toFloat();
  };

double State::pressure64(){
  return jsonMap["pressure64"].toDouble();
  };
  
double State::pressure64(double value){
  jsonMap["pressure64"] = String(value,2);
  return jsonMap["pressure64"].toDouble();
  };

float State::temperature(){
  return jsonMap["temperature"].toFloat();
  };;
float State::temperature(float value){
  jsonMap["temperature"] = String(value,2);
  dew();
  return jsonMap["temperature"].toFloat();
  };;


String State::filename() {  // filename getter
  return jsonMap["filename"];
};

String State::filename(String value) {  // filename setter
  jsonMap["filename"] = value;
  return jsonMap["filename"];
};


bool State::setOta (bool value) {  // ota setter
  ota = value;
  return ota;
};

bool State::getOta () {  // ota getter
  return ota;
};


bool State::reload() {  // reload getter
  return (jsonMap["reload"] == "true");
};

bool State::reload(bool value) {  // reload setter
  jsonMap["reload"] = value ? "true" : "false";
  return (jsonMap["reload"] == "true");
};


bool State::relay() {  // relay getter
  return (jsonMap["relay"] == "true");
};

bool State::relay(bool value) {  // relay setter
  jsonMap["relay"] = value ? "true" : "false";
  return (jsonMap["relay"] == "true");
};

void State::dew(){
  
      jsonMap["dew"] = temperature() - ((100 - humidity()) / 5.);
    }


String State::getJSON() { //convert the state map to json
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
