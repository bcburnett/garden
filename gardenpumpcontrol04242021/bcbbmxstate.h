#pragma once

class BcbBmxState {
  public:
    // setter and getter for humidity
    virtual float humidity();
    virtual float humidity(float value);

    // setter and getter for pressure
    virtual float pressure();
    virtual float pressure(float value);

    // setter and getter for pressure64
    virtual double pressure64();
    virtual double pressure64(double value);

    // setter and getter for temperature
    virtual float temperature();
    virtual float temperature(float value);

};
