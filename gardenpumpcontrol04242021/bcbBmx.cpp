/*
* Garden sensor sketch
* File: bcbBmx.cpp
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
#include "bcbBmx.h"

BcbBmx::BcbBmx(){};

void BcbBmx::bmxInit(BcbBmxState * istate){
  state = istate;
  Wire.begin();
bmx280.begin();

  if (bmx280.isBME280())
    Serial.println("sensor is a BME280");
  else
    Serial.println("sensor is a BMP280");

  //reset sensor to default parameters.
  bmx280.resetToDefaults();

  //by default sensing is disabled and must be enabled by setting a non-zero
  //oversampling setting.
  //set an oversampling setting for pressure and temperature measurements.
  bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
  bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);

  //if sensor is a BME280, set an oversampling setting for humidity measurements.
  if (bmx280.isBME280())
    bmx280.writeOversamplingHumidity(BMx280MI::OSRS_H_x16);
  };

  bool BcbBmx::doSensorMeasurement() {
  //start a measurement
  bmx280.measure();

  do
  {
    delay(100);
  } while (!bmx280.hasValue());

  state->pressure(bmx280.getPressure() * 0.0002953);
  state->pressure64(bmx280.getPressure64() * 0.0002953);
  state->temperature(bmx280.getTemperature() * 1.8 + 32);

  if (bmx280.isBME280())
    state->humidity(bmx280.getHumidity());
return true;
}
