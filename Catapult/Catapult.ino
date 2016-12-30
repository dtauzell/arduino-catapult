
#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  8
#define ECHO_PIN     7
#define MAX_DISTANCE 200
#define FIRE_AT_MIN  65
#define FIRE_AT_MAX   80
#define BUZZER_PIN 12

const int LeverPin = 10;
const int TriggerPin = 13;

const int leverLoose = 130;
const int leverTight = 20;
const int leverTense = 100;

const int triggerClosed = 5;
const int triggerOpen = 90;




Servo leverServo;
Servo triggerServo;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  leverServo.attach(LeverPin);
  triggerServo.attach(TriggerPin);
  pinMode(BUZZER_PIN, OUTPUT);
  prepare();  
  digitalWrite(BUZZER_PIN, HIGH);
  delay(250);
  digitalWrite(BUZZER_PIN, LOW);
}

int times = 0;
void loop() {
  int cm = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(cm);
  Serial.println("cm");
  digitalWrite(BUZZER_PIN, LOW);
  if( cm >= FIRE_AT_MIN && cm <= FIRE_AT_MAX ){  
    fire();
    prepare();
    delay(2000);
  }
  else if( cm > FIRE_AT_MAX && cm < FIRE_AT_MAX+150){
    digitalWrite(BUZZER_PIN, HIGH);
  }
  delay(100);
}

void prepare() {
  loosenLever();
  delay(2000);
  closeTrigger();
  delay(2000);
  tensionLever();
  delay(1000);
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

void tensionLever() {
  leverServo.write(leverTense);
}

void loosenLever() {
  leverServo.write(leverLoose);
}


