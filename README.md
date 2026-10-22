# Telemetry and Sensor Monitoring Simulator

A C++17 console application that simulates sensor measurements, validates data, and records results in CSV format.

## Features

- Simulates temperature, speed, and altitude sensors.
- Generates random changes in sensor measurements.
- Validates sensor values against minimum and maximum limits.
- Records measurement data and validation statuses in a CSV file.
- Includes automated tests for normal values and boundary conditions.

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
├── include/
│   ├── Sensor.h
│   ├── DataValidator.h
│   └── DataLogger.h
├── src/
│   ├── main.cpp
│   ├── Sensor.cpp
│   ├── DataValidator.cpp
│   └── DataLogger.cpp
├── tests/
│   └── test_validator.cpp
├── data/
│   └── telemetry.csv
├── CMakeLists.txt
└── README.md
```

## Build

Configure the project:

```powershell
cmake -S . -B build -G "MinGW Makefiles"
```

Build the application and test executable:

```powershell
cmake --build build
```

## Run

Run the application from the project root directory:

```powershell
.\build\telemetry.exe
```

The application writes sensor measurements and validation statuses to `data/telemetry.csv`. The CSV file may be overwritten each time the application starts.

## Run Tests

Run the automated tests:

```powershell
ctest --test-dir build --output-on-failure
```

The tests cover normal values, minimum and maximum boundaries, and values outside the permitted range.

## Project Purpose

This project was developed to practice C++ object-oriented programming, encapsulation, separation of responsibilities, data validation, file handling, automated testing, and build configuration.