#ifndef STATE
#define STATE

#include "ArduinoJson.h"
#include "AsyncJson.h"
//set initial state

class State {  
   public:
      
     int moisture(){return analogRead(32);};
    
     String filename(){return mfilename;};
     String filename(String value){mfilename = value; return mfilename;};
    
     String json(){return mjson;};
     String json(String value){mjson = value; return mjson;};
    
     bool setOta (bool value){ ota = value;return ota;};
     bool getOta (){return ota;};
    
     bool reload(){return mreload;};
     bool reload(bool value){mreload=value;return mreload;};
    

    private:

     bool ota = false;
     bool mreload = false;
     String mjson = "";
     String mfilename= "index.htm";
     
  } state;
#endif 
