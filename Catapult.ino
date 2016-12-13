
#include <Servo.h>

const int LeverPin = 9;
const int TriggerPin = 10;

const int leverLoose = 180;
const int leverTight = 35;

const int triggerClosed = 133;
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


