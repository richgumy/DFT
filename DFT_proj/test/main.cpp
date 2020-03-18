#include <Arduino.h>
#include <Servo.h>

#define ElbowPin 13
#define buf_size 200

Servo Elbow;
int analogPin = A0;


long val[buf_size];

void setup() {
  Serial.begin(9600);
  Elbow.attach(ElbowPin);
}

void loop() {
  for (int i = 0; i < buf_size; i++) {
    val[i] = analogRead(analogPin);
    Serial.println(val[i]);
    // delay(10);
  }
  long total = 0;
  int elbow_pos = 0;
  for (int i = 0; i < buf_size; i++) {
     total += val[i];
  }
  elbow_pos = total/buf_size;
  // Serial.print("_MAF_");
  // Serial.println(elbow_pos);
  Elbow.write(elbow_pos);
  // delay(100);
}
