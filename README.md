
# IMU Test Rig

## Overview

This repository contains the code for a rig designed to test and calibrate the Polulu & Movella IMUs for the 2025 Aurora Canards. The 3D printed test rig utilizes an Arduino board to control a servo motor and read data from a potentiometer and an encoder.

## Hardware Setup

### Components

- Arduino UNO R3
- Servo motor (pitch Axis)
- DC motor (roll axis)
- Linear potentiometer, does not work with a logarithmic potentiometer
- Rotary Encoder (512 cycles per revolution)
- Polulu and Movella IMUs
- Processor board
- 3D PLA printed frame (0.16mm strength setting)

### Wiring

1. Connect the servo to pin 9 (or pin 3 for the alternative sketch).
2. Attach the potentiometer to analog pin A0.
3. Connect the encoder to digital pin 2.

## Software

### Dependencies

- `Servo.h`: Arduino library for controlling servo motors.

### Calibration

The potentiometer needs to be calibrated to determine the minimum and maximum values manually.

### Usage

1. Upload the Arduino sketche to the Arduino board.
2. Open the Serial Monitor to view the output.
3. Connect the roll motor to a DC power supply that provides large enough voltage and current.
4. Download the serial data for analysis.
