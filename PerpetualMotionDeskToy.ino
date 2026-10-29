#define SENSOR_PIN  6
#define MANETIC_PIN 3
#define LED 8
#define TIME_TRIGER_ON 30 // ms

void setup() {
  pinMode(SENSOR_PIN,INPUT_PULLUP);
  pinMode(MANETIC_PIN, OUTPUT);
  pinMode(LED,OUTPUT);
  digitalWrite(MANETIC_PIN,LOW);
  digitalWrite(LED,HIGH);
}

void loop() {
  if(digitalRead(SENSOR_PIN)==0)
  {
    delayMicroseconds(6500);          // Delay after the sensor detects the ball, allowing it to move closer to the electromagnet
    digitalWrite(MANETIC_PIN,HIGH);
    digitalWrite(LED,LOW);

    delayMicroseconds(4700);
    digitalWrite(MANETIC_PIN,LOW);   // Electromagnet activation time
    digitalWrite(LED,HIGH);
    delayMicroseconds(80000);        // Wait for the capacitor to recharge before the next cycle
  }
}