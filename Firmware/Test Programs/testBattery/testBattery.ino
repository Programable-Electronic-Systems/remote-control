/*
 Battery test program for hardware V1 and V2
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created November 2013
 by Jonathan Ruiz de Garibay

 */

#define LED_GREEN        6
#define LED_RED          7
#define BATTERY_SENSOR   A0

#define MIN_BATTERY      425

void setup() {

  Serial.begin(9600);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.println("Start Battery Test Program");
}

void loop() {

  int batteryLevel = analogRead(BATTERY_SENSOR);
  Serial.print("Battery Level: ");
  Serial.println(batteryLevel, DEC);
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
  delay(1000);
}
