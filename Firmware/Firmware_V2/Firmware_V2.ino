/*
 Remote Control Firmware V1
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created October 2014
 by Jonathan Ruiz de Garibay
 
 */

#include <SoftwareSerial.h>

#define PULSE_A          2
#define PULSE_B          3
#define PULSE_C          4
#define LED_GREEN        11
#define LED_RED          10
#define XBEE_RX          7
#define XBEE_TX          8
#define BATTERY_SENSOR   A0

#define MIN_BATTERY      425

#define GROUP    "00"

//#define DEBUG

SoftwareSerial xbee(XBEE_RX, XBEE_TX);

int state = 0;

void setup() {

#ifdef DEBUG
  Serial.begin(9600);
#endif
  pinMode(PULSE_A, INPUT_PULLUP);
  pinMode(PULSE_B, INPUT_PULLUP);
  pinMode(PULSE_C, INPUT_PULLUP);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  xbee.begin(9600);
#ifdef DEBUG
  Serial.println("Start Remote Control Application");
#endif
}

void loop() {

  int batteryLevel = analogRead(BATTERY_SENSOR);
#ifdef DEBUG
  Serial.print("BatteryLevel: ");
  Serial.println(batteryLevel, DEC);
#endif
  if (batteryLevel > MIN_BATTERY)
  {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  }
  else
  {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
  }
  if (digitalRead(PULSE_A) ==  LOW) {
    if (state != 1) {
      state = 1;
      xbee.print(';');
      xbee.print(GROUP);
      xbee.print('A');
      xbee.println('?');
#ifdef DEBUG
      Serial.println("Pulse A activated. Sended rensponse to master.");
#endif
    }
#ifdef DEBUG
    else
      Serial.println("Pulse A activated. Didn't send rensponse to master.");
#endif
  }
  else if (digitalRead(PULSE_B) ==  LOW) {
    if (state != 2) {
      state = 2;
      xbee.print(';');
      xbee.print(GROUP);
      xbee.print('B');
      xbee.println('?');
#ifdef DEBUG
      Serial.println("Pulse B activated. Sended rensponse to master.");
#endif
    }
#ifdef DEBUG
    else
      Serial.println("Pulse B activated. Didn't send rensponse to master.");
#endif
  }
  else if (digitalRead(PULSE_C) ==  LOW) {
    if (state != 3) {
      state = 3;
      xbee.print(';');
      xbee.print(GROUP);
      xbee.print('C');
      xbee.println('?');
#ifdef DEBUG
      Serial.println("Pulse C activated. Sended rensponse to master.");
#endif
    }
#ifdef DEBUG
    else
      Serial.println("Pulse C activated. Didn't send rensponse to master.");
#endif
  }
  else {
    state = 0;
#ifdef DEBUG
    Serial.println("Any pulse activated");
#endif
  }
  delay(20);  
#ifdef DEBUG
  delay(1000);
#endif
}


