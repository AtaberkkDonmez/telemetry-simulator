
#pragma once

#include <string>

class Sensor {
private:
    std::string name;
    std::string unit;
    double value;

    double minChange;
    double maxChange;

    double minValue;
    double maxValue;

public:
    Sensor(const std::string& sensorName,
           const std::string& sensorUnit,
           double initialValue,
           double minimumChange,
           double maximumChange,
           double minimumValue,
           double maximumValue);

    std::string getName() const;
    std::string getUnit() const;
    double getValue() const;

    double getMinValue() const;
    double getMaxValue() const;

    void simulateMeasurement();
};
