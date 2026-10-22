
cmake_minimum_required(VERSION 3.20)

project(TelemetrySimulator
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(telemetry
    src/main.cpp
    src/Sensor.cpp
    src/DataValidator.cpp
    src/DataLogger.cpp
)

target_include_directories(telemetry PRIVATE include)

if(MSVC)
    target_compile_options(telemetry PRIVATE /W4)
else()
    target_compile_options(telemetry PRIVATE
        -Wall -Wextra -pedantic
    )
endif()

add_executable(test_validator
    tests/test_validator.cpp
    src/Sensor.cpp
    src/DataValidator.cpp
)

target_include_directories(test_validator PRIVATE include)

if(MSVC)
    target_compile_options(test_validator PRIVATE /W4)
else()
    target_compile_options(test_validator PRIVATE
        -Wall -Wextra -pedantic
    )
endif()

enable_testing()

add_test(
    NAME DataValidatorTest
    COMMAND test_validator
)
