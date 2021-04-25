#pragma once
class BcbAwsState{
  public:
    // setter and getter for the uploading filename
    virtual String filename();
    virtual String filename(String value);

    
    // should the browser reload the website
    virtual bool reload();
    virtual bool reload(bool value);


    // relay state
    virtual bool relay();
    virtual bool relay(bool value);

    // return a stringifyed json representation of the state
    virtual String getJSON();
};
