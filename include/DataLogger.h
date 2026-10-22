
#pragma once

#include <fstream>
#include <string>

#include "Sensor.h"

class DataLogger {
private:
    std::ofstream file;

public:
    explicit DataLogger(const std::string& filename);

    bool isOpen() const;

    void logMeasurement(
        int step,
        const Sensor& sensor,
        bool valid
    );
};
