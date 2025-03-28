#include <Servo.h>

#define CONTROL_PIN 4  // Pin receiving signal from ESP32
#define SERVO_PIN 8    // Servo control pin

Servo myServo;

void setup() {
  pinMode(CONTROL_PIN, INPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);  // Start at 0°
  Serial.begin(115200);
}

void loop() {
  int signal = digitalRead(CONTROL_PIN);  // Read signal from ESP32

  if (signal == HIGH) {
    myServo.write(180);  // Move servo to 180° when the signal is HIGH
    Serial.println("Servo ON (180°)");
  } else {
    myServo.write(0);  // Move servo to 0° when the signal is LOW
    Serial.println("Servo OFF (0°)");
  }

  delay(100);  // Delay to prevent too rapid signal checking
}
