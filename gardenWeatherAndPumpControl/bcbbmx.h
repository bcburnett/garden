#ifndef BCBBMX
#define BCBBMX
#include <Wire.h>
#include <BMx280I2C.h>
#include "State.h"


#define BMX_ADDRESS 0x76

//create a BMx280I2C object using the I2C interface with I2C Address 0x76
BMx280I2C bmx280(BMX_ADDRESS);

void initBmx280() {
  if (!bmx280.begin())
  {
    Serial.println("begin() failed. check your BMx280 Interface and I2C Address.");
    delay(1000);
    initBmx280();
  }

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
}

void doSensorMeasurement() {
  //start a measurement
  if (!bmx280.measure())
    return ;

  do
  {
    delay(100);
  } while (!bmx280.hasValue());

  state.pressure = bmx280.getPressure() * 0.0002953;
  state.pressure64 = bmx280.getPressure64() * 0.0002953;
  state.temp = bmx280.getTemperature() * 1.8 + 32;

  if (bmx280.isBME280())
    state.humidity = bmx280.getHumidity();

}
#endif
