#include <Servo.h>
#define PIN_TRIG 12
#define PIN_ECHO 11

long duration, cm;
int ledPin = 10;
int ledPin2 = 4;
int ledPin1 = 7;
Servo servo1;

void setup(){


  Serial.begin (9600);
  servo1.attach(2);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  
}

void loop() {


  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  duration = pulseIn(PIN_ECHO, HIGH);

  cm = (duration / 2) / 29.1;

  Serial.print("Расстояние до объекта: ");
  Serial.print(cm);
  Serial.println(" см.");

  if(cm <= 30){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  if(cm <= 40){
    digitalWrite(ledPin1, HIGH);
  }
  else{
    digitalWrite(ledPin1, LOW);
  }
  if(cm >= 10){
    digitalWrite(ledPin2, HIGH);
  }
  else{
    digitalWrite(ledPin2, LOW);
  }

  
  if (cm <= 30 and cm <= 40 and cm >= 10){
    servo1.write(360);
    delay(200);
  }
  else{
    servo1.write(-360);
  }
  
  

  delay(250);
}
