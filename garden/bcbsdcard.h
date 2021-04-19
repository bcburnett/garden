#include "FS.h"
#include "SPIFFS.h"
#include "ArduinoJson.h"
#include "State.h"

#ifndef BCBSD
#define BCBSD
#include "defaulthtml.h"


// variables
xSemaphoreHandle semFile = xSemaphoreCreateMutex(); // file operation lock
void initSDCard() {
  Serial.print("Initializing SD card...");

  if (!SPIFFS.begin(true)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

}

void appendFile(fs::FS &fs, const char * path, const char * message) {

  if (xSemaphoreTake(semFile, 500)) {
    File file = fs.open(path, FILE_APPEND);

    if (!file) {
      return;
    }
    file.print(message);
    file.close();

    xSemaphoreGive(semFile);
  }
}

void writeFile(fs::FS &fs, const char * path, const char * message) {

  if (xSemaphoreTake(semFile, 500)) {
    File file = fs.open(path, FILE_WRITE);

    if (!file) {
      return;
    }
    file.print(message);
    file.close();

    xSemaphoreGive(semFile);
  }
}
String readFile(fs::FS &fs, const char * path){
    Serial.printf("Reading file: %s\r\n", path);

    File file = fs.open(path);
    if(!file || file.isDirectory()){
        Serial.println("- failed to open file for reading");
        return "";
    }
    String result;
    Serial.println("- read from file:");
    while(file.available()){
        result += String(char(file.read()));
    }
    file.close();
    return result;
}

void renameFile(fs::FS &fs, const char * path1, const char * path2) {
  if (xSemaphoreTake(semFile, 500)) {
    fs.rename(path1, path2);
    xSemaphoreGive(semFile);
  }
}

void deleteFile(fs::FS &fs, const char * path) {
  if (xSemaphoreTake(semFile, 500)) {
    fs.remove(path);
    xSemaphoreGive(semFile);
  }
}

// write the default index.htm to SPIFFS
//  check if index exists and only update if it doesn't
void checkForIndex(){
  if(SPIFFS.exists("/data.json")) {
    state.json(readFile(SPIFFS, "/data.json"));
    Serial.println(state.json());
  }
  if(SPIFFS.exists("/index.htm")) return; // 
  deleteFile(SPIFFS,"/index.htm");
  delay(500);
  File file = SPIFFS.open("/index.htm", FILE_WRITE);
    file.print(htmlCode);
    file.close();
    }

#endif
