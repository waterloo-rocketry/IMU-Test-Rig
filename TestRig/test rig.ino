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

int commandedAngle = 0;

int servPos = 0;

int pulseCount = 0;
float rpm = 0;
unsigned long lastTime = 0;
long previousPosition = 0;

void setup() {
  Serial.begin(9600);

  //Serial.println("Calibrating potentiometer...");
  //delay(5000);  // Give time to move the potentiometer manually
  //potMin = analogRead(potPin);  // Set minimum value
  //delay(5000);
  //potMax = analogRead(potPin);  // Set maximum value
  //Serial.println("Calibration complete.");


  pinMode(encoderPin, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void countPulse() {
  pulseCount++;
}

void loop() {
  unsigned long currentTime = millis();

  if (Serial.available() > 0) {     // Check if data is available
    int angle = Serial.parseInt();  // Read integer from Serial

    if (angle >= 0 && angle <= 180) {  // Validate range
      myservo.write(angle);            // Set servo position
      commandedAngle = angle;
    } else {
      Serial.println("Invalid input! Enter a number between 0 and 180.");
    }

    // Clear Serial buffer
    while (Serial.available() > 0) {
      Serial.read();
    }
  }




  if (currentTime - lastTime >= 1000) {
    // Serial.print("Pulse Count: ");
    // Serial.print(pulseCount);
    Serial.print("RPM: ");
    Serial.print((pulseCount / pulsesPerRevolution) * 60.0);


    potAngle = analogRead(potPin);

    // potAngle /= 1023.0;

    // potAngle *= 270;

    // potAngle /= -2;

    // potAngle -= 100;

    Serial.print(", Pitch Angle: ");
    Serial.print(potAngle);
    Serial.print(", Commanded Angle: ");
    Serial.println(commandedAngle);
    
    pulseCount = 0;
    lastTime = currentTime;

    //delay(500);
  }




  // in case the sensor value is outside the range seen during calibration
  //potAngle = constrain(potAngle, potMin, potMax);

  // apply the calibration to the sensor reading
  //potAngle = map(potAngle, potMin, potMax, -90, 90);
}
