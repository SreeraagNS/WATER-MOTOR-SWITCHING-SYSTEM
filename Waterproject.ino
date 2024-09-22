/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// the setup function runs once when you press reset or power the board
#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLS    16
#define LCD_ROWS    2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

const int TriggerPin = 11;
const int EchoPin = 12;
const int MotorPin = 3;

NewPing sonar(TriggerPin, EchoPin, 100);

void setup() {
    Serial.begin(9600);
    pinMode(MotorPin, OUTPUT);

    lcd.init();
    lcd.backlight();
}

void loop() {
    int distance = sonar.ping_cm();
    lcd.clear();

    if (distance >= 0) {
        if (distance > 2) {
            lcd.print("Water Level: Above 2cm");
            digitalWrite(MotorPin, HIGH); // Turn on the motor
        
        }
        else if(distance<6){
          lcd.print("Water Level: Above 2cm");
          digitalWrite(MotorPin, HIGH); // Turn on the motor

        } else if(distance<2.2) {
            lcd.print("Water Level: Below 2cm");
            digitalWrite(MotorPin, LOW); // Turn off the motor
        }
    }

    delay(50); // 50 ms delay is sufficient
}


