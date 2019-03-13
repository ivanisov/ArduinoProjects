#include <Servo.h>

#define SERVO_PIN 9

#define OPEN_ANGLE 60
#define CLOSE_ANGLE 180


Servo myServo;
String message;

void setup()
{
  myServo.attach(SERVO_PIN);
  myServo.write(CLOSE_ANGLE);
  delay(1000);
  myServo.detach();
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()) {
    char incomingChar = Serial.read();
    if (incomingChar >= '0' && incomingChar <= '9') {
      message += incomingChar;
    } else if (incomingChar == '\n') {
      message = "";

      myServo.attach(SERVO_PIN);
      myServo.write(OPEN_ANGLE);
      delay(575);
      myServo.write(CLOSE_ANGLE);
      delay(1500);
      myServo.detach();
      delay(5000);

    }
  }
  delay(13);
}
