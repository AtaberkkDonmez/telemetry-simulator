
#include <iostream>
#include <iomanip>
#include <vector>

#include "Sensor.h"
#include "DataValidator.h"
#include "DataLogger.h"

int main() {
    std::vector<Sensor> sensors;

    sensors.emplace_back(
        "Temperature", "Celsius", 24.5, -0.3, 0.3, -40.0, 125.0
    );

    sensors.emplace_back(
        "Speed", "km/h", 80.0, -2.0, 2.0, 0.0, 300.0
    );

    sensors.emplace_back(
        "Altitude", "m", 120.0, -1.0, 1.0, 0.0, 10000.0
    );

    DataValidator validator;

    DataLogger logger("data/telemetry.csv");


if (!logger.isOpen()) {
    std::cerr << "Error: Could not open CSV file.\n";
    return 1;
}

    for (int step = 1; step <= 5; ++step) {
        std::cout << "\n--- Simulation Step "
                  << step << " ---\n";

    

        for (Sensor& sensor : sensors) {
            sensor.simulateMeasurement();

            bool valid = validator.isValid(sensor);
            logger.logMeasurement(step, sensor, valid);

            std::cout << std::fixed << std::setprecision(2)
                      << sensor.getName() << ": "
                      << sensor.getValue() << " "
                      << sensor.getUnit()
                      << " | Status: "
                      << (valid ? "VALID" : "INVALID")
                      << '\n';
        }
    }


    std::cout << "\n--- Validation Test ---\n";

Sensor testSensor(
    "TestSpeed", "km/h", 350.0, -2.0, 2.0, 0.0, 300.0
);

std::cout << testSensor.getName() << ": "
          << (validator.isValid(testSensor) ? "VALID" : "INVALID")
          << '\n';
    return 0;
}
