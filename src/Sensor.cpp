
#include "Sensor.h"

#include <random>

namespace {
    double generateChange(double minimum, double maximum) {
        static std::mt19937 generator(std::random_device{}());

        std::uniform_real_distribution<double> distribution(
            minimum, maximum
        );

        return distribution(generator);
    }
}

Sensor::Sensor(const std::string& sensorName,
               const std::string& sensorUnit,
               double initialValue,
               double minimumChange,
               double maximumChange,
               double minimumValue,
               double maximumValue)
    : name(sensorName),
      unit(sensorUnit),
      value(initialValue),
      minChange(minimumChange),
      maxChange(maximumChange),
      minValue(minimumValue),
      maxValue(maximumValue) {
}

std::string Sensor::getName() const {
    return name;
}

std::string Sensor::getUnit() const {
    return unit;
}

double Sensor::getValue() const {
    return value;
}

double Sensor::getMinValue() const {
    return minValue;
}

double Sensor::getMaxValue() const {
    return maxValue;
}

void Sensor::simulateMeasurement() {
    value += generateChange(minChange, maxChange);
}
