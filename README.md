# WATER-MOTOR-SWITCHING-SYSTEM
This project aims to automate the process of controlling a water motor based on the water level in a tank. It utilizes an ultrasonic sensor to measure the water level and an Arduino microcontroller to switch the motor on or off depending on predefined water levels. The system prevents the tank from overflowing or running dry, making it an efficient and easy-to-implement solution for home water management.

Components Required
Arduino Uno (or any compatible microcontroller)
Ultrasonic Sensor (HC-SR04) for water level measurement
Relay Module to control the motor
Water Motor (pump)
Jumper wires
Breadboard (optional)
Power supply for the motor


Working Principle
The ultrasonic sensor measures the distance between the sensor and the water surface in the tank. When the water level is lower than a set threshold (tank is low), the motor is switched on automatically to pump water. When the water reaches the desired level (tank is full), the motor is turned off. The relay module is used to control the water motor, while the Arduino handles the logic and decision-making.
