
#include <iostream>
#include <stdexcept>

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

   
    // Test 4: Invalid initial value
    bool invalidInitialValueCaught = false;

    try {
        Sensor sensor(
            "InvalidSpeed", "km/h", 350.0, -2.0, 2.0, 0.0, 300.0
        );
    }
    catch (const std::invalid_argument&) {
        invalidInitialValueCaught = true;
    }

    if (!invalidInitialValueCaught) {
        std::cerr << "FAIL: Invalid initial value was accepted.\n";
        return 1;
    }

    // Test 5: Empty sensor name
    bool emptyNameCaught = false;

    try {
        Sensor sensor(
            "", "km/h", 100.0, -2.0, 2.0, 0.0, 300.0
        );
    }
    catch (const std::invalid_argument&) {
        emptyNameCaught = true;
    }

    if (!emptyNameCaught) {
        std::cerr << "FAIL: Empty sensor name was accepted.\n";
        return 1;
    }

    // Test 6: Minimum change greater than maximum change
    bool invalidChangeRangeCaught = false;

    try {
        Sensor sensor(
            "Speed", "km/h", 100.0, 5.0, -5.0, 0.0, 300.0
        );
    }
    catch (const std::invalid_argument&) {
        invalidChangeRangeCaught = true;
    }

    if (!invalidChangeRangeCaught) {
        std::cerr << "FAIL: Invalid change range was accepted.\n";
        return 1;
    }

    std::cout << "All 6 tests passed.\n";
    return 0;
}
