#define BUTTON_A  2
#define BUTTON_B  3
#define BUTTON_C  4

void setup() {

  Serial.begin(9600);
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
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
