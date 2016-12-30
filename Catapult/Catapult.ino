
#include <Servo.h>

const int LeverPin = 10;
const int TriggerPin = 13;

const int leverLoose = 130;
const int leverTight = 20;

const int triggerClosed = 10;
const int triggerOpen = 90;

Servo leverServo;
Servo triggerServo;

void setup() {
  Serial.begin(9600);
  leverServo.attach(LeverPin);
  triggerServo.attach(TriggerPin);

  prepare();  
}

int times = 0;
void loop() {
  if( times++ < 10) {
    fire();
    prepare();
    delay(2000);
  }
}

void prepare() {
  loosenLever();
  delay(2000);
  closeTrigger();
  delay(2000);
}

void fire() {
  armLever();
  delay(1000);
  openTrigger();
  delay(250);
}

void openTrigger() {
  triggerServo.write(triggerOpen);
}

void closeTrigger() {
  triggerServo.write(triggerClosed);
}

void armLever() {
  leverServo.write(leverTight);
}

void loosenLever() {
  leverServo.write(leverLoose);
}


