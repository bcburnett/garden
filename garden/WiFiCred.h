/*
* Garden sensor sketch
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
//wifi connection credentials
const char* ssid     = "Espnet";
//const char* ssid     = "Frontier4848";
const char* password = "*********";
