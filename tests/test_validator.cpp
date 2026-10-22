
#include <iostream>

#include "Sensor.h"
#include "DataValidator.h"

int main() {
    DataValidator validator;

    Sensor normalSensor(
        "NormalSpeed", "km/h", 100.0, -2.0, 2.0, 0.0, 300.0
    );

    Sensor minimumSensor(
        "MinimumSpeed", "km/h", 0.0, -2.0, 2.0, 0.0, 300.0
    );

    Sensor maximumSensor(
        "MaximumSpeed", "km/h", 300.0, -2.0, 2.0, 0.0, 300.0
    );

    Sensor belowMinimumSensor(
        "BelowMinimum", "km/h", -1.0, -2.0, 2.0, 0.0, 300.0
    );

    Sensor aboveMaximumSensor(
        "AboveMaximum", "km/h", 301.0, -2.0, 2.0, 0.0, 300.0
    );

    if (!validator.isValid(normalSensor)) {
        std::cerr << "FAIL: Normal value rejected.\n";
        return 1;
    }

    if (!validator.isValid(minimumSensor)) {
        std::cerr << "FAIL: Minimum boundary rejected.\n";
        return 1;
    }

    if (!validator.isValid(maximumSensor)) {
        std::cerr << "FAIL: Maximum boundary rejected.\n";
        return 1;
    }

    if (validator.isValid(belowMinimumSensor)) {
        std::cerr << "FAIL: Below-minimum value accepted.\n";
        return 1;
    }

    if (validator.isValid(aboveMaximumSensor)) {
        std::cerr << "FAIL: Above-maximum value accepted.\n";
        return 1;
    }

    std::cout << "All 5 DataValidator tests passed.\n";
    return 0;
}
