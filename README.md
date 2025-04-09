## Bosch BMP384 Pressure Sensor with Arduino

This project demonstrates how to interface the Bosch BMP384 pressure sensor with an Arduino using both SPI and I2C communication protocols. The BMP384 is a high-precision pressure sensor capable of measuring atmospheric pressure and altitude.


## Libraries Used

- Adafruit BMP3XX Library
- SparkFun BMP384 Arduino Library

## Project Structure

```bash
/src
    ├── /spi - Arduino code to read pressure data from the BMP384 via SPI
    └── /i2c - Arduino code to read pressure data from the BMP384 via I2C
```

## Tested Hardware

    - Arduino Due ( Note: The BMP384 operates at 3.3V. Ensure your Arduino board and any connected components are compatible or use appropriate level shifting. )


## Getting Started

    1. Clone or download this repository.   
    2. Open the desired example (either from src/spi or src/i2c) in the Arduino IDE.
    3. Install the required libraries via Library Manager.  
    4. Upload the sketch to your Arduino Due.   
    5. Open the Serial Monitor to view pressure readings.


## Pin Diagram and Wiring

For the pin diagram and wiring details, please refer to the official datasheet:

[BMP384 Datasheet (bst-bmp384-ds003.pdf)](datasheet/bst-bmp384-ds003.pdf)

Ensure to follow the wiring instructions for proper connectivity and configuration.
