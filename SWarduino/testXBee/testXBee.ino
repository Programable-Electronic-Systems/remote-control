#include <SoftwareSerial.h>

#define XBEE_RX  8
#define XBEE_TX  9

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
