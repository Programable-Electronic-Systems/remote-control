/*
 Buttons test program for hardware V1 and V2
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created November 2013
 by Jonathan Ruiz de Garibay

 */
 
#define BUTTON_A  2
#define BUTTON_B  3
#define BUTTON_C  4

void setup() {

  Serial.begin(9600);
  pinMode(BUTTON_A, INPUT);
  pinMode(BUTTON_B, INPUT);
  pinMode(BUTTON_C, INPUT);
  Serial.println("Start Button Test Program");
}

void loop() {

  if (digitalRead(BUTTON_A) ==  LOW)
      Serial.println("Button A activated.");
  if (digitalRead(BUTTON_B) ==  LOW)
      Serial.println("Button B activated.");
  if (digitalRead(BUTTON_C) ==  LOW)
      Serial.println("Button C activated.");
  delay(100);
}
