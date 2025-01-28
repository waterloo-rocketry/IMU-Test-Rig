#include <Servo.h>


// These constants won't change:
Servo myservo;  // create servo object to control a servo

const int potPin = A0;  // pin that the sensor is attached to
const int encoderPin = 2;
const float pulsesPerRevolution = 512.0;



// variables:
float potAngle = 0;  // the sensor value
int potMax = -1.6;   // minimum sensor value
int potMin = -0.14;  // maximum sensor value

int servPos = 0;

int pulseCount = 0;
float rpm = 0;
unsigned long lastTime = 0;
long previousPosition = 0;

void setup() {

  myservo.attach(9);
  Serial.begin(9600);

  //Serial.println("Calibrating potentiometer...");
  //delay(5000);  // Give time to move the potentiometer manually
  //potMin = analogRead(potPin);  // Set minimum value
  //delay(5000);
  //potMax = analogRead(potPin);  // Set maximum value
  //Serial.println("Calibration complete.");


  pinMode(encoderPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);

  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void countPulse() {
  pulseCount++;
}

void loop() {
  unsigned long currentTime = millis();


  /*
    for (servPos = 0; servPos <= 180; servPos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(servPos);              // tell servo to go to position in variable 'servPos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (servPos = 180; servPos >= 0; servPos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(servPos);              // tell servo to go to position in variable 'servPos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  */


  if (currentTime - lastTime >= 1000) {
    Serial.print("Pulse Count: ");
    Serial.print(pulseCount);
    Serial.print(", Pulse per rev: ");
    Serial.println((pulseCount / pulsesPerRevolution) * 60.0);


    potAngle = analogRead(potPin);

    potAngle /= 1023.0;

    potAngle = (log10(potAngle)) * 270;

    potAngle /= -2;

    potAngle -= 100;

    Serial.print("angle: ");
    Serial.println(potAngle);
    pulseCount = 0;
    lastTime = currentTime;

    //delay(500);
  }




  // in case the sensor value is outside the range seen during calibration
  //potAngle = constrain(potAngle, potMin, potMax);

  // apply the calibration to the sensor reading
  //potAngle = map(potAngle, potMin, potMax, -90, 90);
}
