/*
* Garden sensor sketch
* File: State.h
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
#include<Arduino.h>
#include<map>
//set initial state

class State {
  public:

    int moisture(); // reads and returns moisture reading

    // setter and getter for the threshold TODO
    int threshold();  
    int threshold(int value);

    // setter and getter for the uploading filename
    String filename();
    String filename(String value);


    // is an OTA update in progress
    bool setOta (bool value);
    bool getOta ();


    // should the browser reload the website
    bool reload();
    bool reload(bool value);


    // relay state
    bool relay();
    bool relay(bool value);

    // return a stringifyed json representation of the state
    String getJSON();

  private:
    // container for the state
    std::map<String, String> jsonMap;
    //OTA is handeled seperately
    bool ota = false;
};
