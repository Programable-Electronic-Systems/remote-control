/*
 Remote Control Firmware V1
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created November 2013
 by Jonathan Ruiz de Garibay
 
 */

#define PULSE_A          2
#define PULSE_B          3
#define PULSE_C          4
#define LED_RED          10
#define LED_GREEN        11
#define BATTERY_SENSOR   A0

#define MIN_BATTERY      425

#define GROUP    "00"

int state = 0;

void setup() {

  Serial.begin(9600);
  pinMode(PULSE_A, INPUT);
  pinMode(PULSE_B, INPUT);
  pinMode(PULSE_C, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.println("Start Remote Control Application");
}

void loop() {

  int batteryLevel = analogRead(BATTERY_SENSOR);
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
      Serial.print(';');
      Serial.print(GROUP);
      Serial.print('A');
      Serial.println('?');
    }
  }
  else if (digitalRead(PULSE_B) ==  LOW) {
    if (state != 2) {
      state = 2;
      Serial.print(';');
      Serial.print(GROUP);
      Serial.print('B');
      Serial.println('?');
    }
  }
  else if (digitalRead(PULSE_C) ==  LOW) {
    if (state != 3) {
      state = 3;
      Serial.print(';');
      Serial.print(GROUP);
      Serial.print('C');
      Serial.println('?');
    }
  }
  else
    state = 0;
  delay(20);  
}

