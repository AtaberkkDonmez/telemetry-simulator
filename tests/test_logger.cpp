
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#include "Sensor.h"
#include "DataLogger.h"

int main() {
    const std::string filename = "test_telemetry.csv";

    // Remove any file left by a previous test run.
    std::remove(filename.c_str());

    Sensor sensor(
        "Temperature", "Celsius", 25.0, -0.5, 0.5, -40.0, 125.0
    );

    {
        DataLogger logger(filename);

        if (!logger.isOpen()) {
            std::cerr << "FAIL: Log file could not be opened.\n";
            return 1;
        }

        logger.logMeasurement(1, sensor, true);
    } // The logger closes the file when it goes out of scope.

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "FAIL: Log file could not be read.\n";
        return 1;
    }

    std::string header;
    std::string measurement;

    std::getline(file, header);
    std::getline(file, measurement);

    if (header != "step,sensor_name,value,unit,status") {
        std::cerr << "FAIL: CSV header is incorrect.\n";
        return 1;
    }

    if (measurement != "1,Temperature,25.00,Celsius,VALID") {
        std::cerr << "FAIL: Measurement row is incorrect: "
                  << measurement << '\n';
        return 1;
    }

    file.close();
    std::remove(filename.c_str());

    std::cout << "All DataLogger tests passed.\n";
    return 0;
}
