# Telemetry and Sensor Monitoring Simulator

A C++17 console application that simulates sensor measurements, validates data, and records results in CSV format.

## Features

- Simulates temperature, speed, and altitude sensors.
- Generates random changes in sensor measurements.
- Validates sensor values against minimum and maximum limits.
- Rejects invalid sensor configurations using exceptions.
- Handles CSV file opening failures.
- Records measurements and validation statuses in CSV format.
- Configures the simulation step count through `config.txt`.
- Includes automated tests for data validation and CSV logging.

## Technologies

- C++17
- Object-Oriented Programming (OOP)
- Standard Template Library (STL)
- CMake
- CTest
- GCC / MinGW

## Project Structure

```text
telemetry-simulator/
|-- include/
|   |-- Sensor.h
|   |-- DataValidator.h
|   |-- DataLogger.h
|-- src/
|   |-- main.cpp
|   |-- Sensor.cpp
|   |-- DataValidator.cpp
|   |-- DataLogger.cpp
|-- tests/
|   |-- test_validator.cpp
|   |-- test_logger.cpp
|-- data/
|   |-- telemetry.csv
|-- config.txt
|-- CMakeLists.txt
|-- README.md
|-- .gitignore
```

## Configuration

The `config.txt` file controls the number of simulation steps.

Example:

```text
simulation_steps=5
```

The value must be greater than zero. Sensor limits are currently defined in the source code.

## Build

Configure the project:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

Build the application and tests:

```powershell
cmake --build build
```

## Run

Run the application from the project root directory:

```powershell
.\build\telemetry.exe
```

The application reads `config.txt` and writes measurements and validation statuses to `data/telemetry.csv`. The CSV output may change each time the simulation runs.

The application reports an error if the configuration file is missing or invalid, or if the CSV file cannot be opened.

## Run Tests

Run all registered tests:

```powershell
ctest --test-dir build --output-on-failure
```

The tests cover normal values, boundary conditions, invalid sensor configurations, CSV headers, and measurement formatting.

## Project Purpose

This project was developed to practice C++ object-oriented programming, encapsulation, separation of responsibilities, data validation, exception handling, file handling, automated testing, and build configuration.