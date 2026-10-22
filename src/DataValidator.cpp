
#include "DataValidator.h"

bool DataValidator::isValid(const Sensor& sensor) const {
    return sensor.getValue() >= sensor.getMinValue()
        && sensor.getValue() <= sensor.getMaxValue();
}
