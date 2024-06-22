# SmartGardenMonitorAr

SmartGardenMonitor is an Arduino-based project designed to monitor soil moisture, temperature, and humidity. Sensors are connected to the Arduino, and data is periodically read and output in JSON format via Serial.

## Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Connections](#connections)
- [Contact](#contact)

## Requirements

- Arduino board (e.g., Arduino Uno)
- Soil moisture sensor
- DHT11 temperature and humidity sensor
- Wires for connections

## Installation

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Clone or download this repository.
3. Install the necessary libraries in the Arduino IDE:
   - [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
   - [TaskScheduler](https://github.com/arkhipenko/TaskScheduler)
   - [DHT sensor library](https://github.com/adafruit/DHT-sensor-library)

## Usage

1. Open the `main.ino` file in the Arduino IDE.
2. Connect the Arduino board to your computer.
3. Upload the sketch to the board.
4. Open the Serial Monitor in the Arduino IDE to view the data.

## Project Structure

- `main.ino` - Main project file where tasks are created.
- `SoilMoistureSensor.h` - File for reading data from the soil moisture sensor.
- `TempHumiditySensor.h` - File for reading data from the temperature and humidity sensor.

