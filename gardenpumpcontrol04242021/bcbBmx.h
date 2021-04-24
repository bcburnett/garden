#pragma once
#include "State.h"
#include <Wire.h>
#include <BMx280I2C.h>
#define BMX_ADDRESS 0x76
class BcbBmx {
  public:
    BMx280I2C bmx280 = BMx280I2C(BMX_ADDRESS);
    BcbBmx();
    void bmxInit(State * istate);

    void doSensorMeasurement();

  private:
    State * state;


};
