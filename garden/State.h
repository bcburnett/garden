#ifndef STATE
#define STATE

#include "ArduinoJson.h"
#include "AsyncJson.h"
//set initial state

class State {  
   public:
      
     int moisture(){
      int avg = 0;
      for(int num=0; num <=9; num++){
        avg += analogRead(32);
      }
      return avg/10;
     }
     String filename(){return mfilename;};
     String filename(String value){mfilename = value; return mfilename;};
    
     String json(){return mjson;};
     String json(String value){mjson = value; return mjson;};
    
     bool setOta (bool value){ ota = value;return ota;};
     bool getOta (){return ota;};
    
     bool reload(){return mreload;};
     bool reload(bool value){mreload=value;return mreload;};
    
     bool relay(){return mrelay;};
     bool relay(bool value){mrelay=value;return mrelay;};
     
    private:

     bool ota = false;
     bool mreload = false;
     bool mrelay = false;
     String mjson = "";
     String mfilename= "index.htm";
     
  } state;
#endif 
