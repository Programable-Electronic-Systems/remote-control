/*
 Xbee communication test program only for hardware V2
 
 License: CC BY-SA 3.0: Creative Commons Share-alike 3.0. Feel free 
 to use and abuse this code however you'd like. If you find it useful
 please attribute, and SHARE-ALIKE!
 
 Created October 2014
 by Jonathan Ruiz de Garibay

 */
 
#include <SoftwareSerial.h>

#define XBEE_RX  7
#define XBEE_TX  8

SoftwareSerial xbee(XBEE_RX, XBEE_TX);

void setup() {

  Serial.begin(9600);
  xbee.begin(9600);
  Serial.println("Start XBee Test Program");
}

void loop() {

  xbee.println(millis() / 1000, DEC);
  delay(1000);
}
