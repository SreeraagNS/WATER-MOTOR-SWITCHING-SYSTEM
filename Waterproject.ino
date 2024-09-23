
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


