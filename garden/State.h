#pragma once
#include<Arduino.h>
#include<map>
//set initial state

class State {
  public:

    int moisture();

    int threshold();
    int threshold(int value);


    String filename();
    String filename(String value);


    bool setOta (bool value);
    bool getOta ();

    bool reload();
    bool reload(bool value);

    bool relay();
    bool relay(bool value);

    String getJSON();

  private:
    std::map<String, String> jsonMap;
    bool ota = false;
};
