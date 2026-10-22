
#include "DataLogger.h"

#include <iomanip>

DataLogger::DataLogger(const std::string& filename)
    : file(filename) {

    if (file.is_open()) {
        file << "step,sensor_name,value,unit,status\n";
    }
}

bool DataLogger::isOpen() const {
    return file.is_open();
}

void DataLogger::logMeasurement(
    int step,
    const Sensor& sensor,
    bool valid
) {
    if (!file.is_open()) {
        return;
    }

    file << step << ","
         << sensor.getName() << ","
         << std::fixed << std::setprecision(2)
         << sensor.getValue() << ","
         << sensor.getUnit() << ","
         << (valid ? "VALID" : "INVALID")
         << '\n';
}
