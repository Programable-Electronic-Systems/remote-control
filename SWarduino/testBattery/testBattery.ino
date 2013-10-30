#define LED_GREEN        6
#define LED_RED          7
#define BATTERY_SENSOR   A0

#define MIN_BATTERY      200

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
