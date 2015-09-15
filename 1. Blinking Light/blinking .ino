// Blinks LED on timed intervals
// Author: Tarun Kumar

int ledPin = 13;

void setup()
{
  // init digital pins as outputs
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  digitalWrite(ledPin,HIGH);
  delay(300);
  digitalWrite(ledPin,LOW);
  delay(300);
}
