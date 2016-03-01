// Increase Light sensitive LED using a LDR.
// Author: Tarun Kumar

int pot_pin = 0;
int led_pin = 10;
int reading = 0;
void setup()
{
  pinMode(pot_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  reading = analogRead(pot_pin);
  Serial.println(reading);
  reading = constrain(reading, 370,700); # constrain reading needs to be calibrated by experimentation.
  int led_level = map(reading, 370, 700, 255, 0); # map analog LDR inputs to outputs for LED brightness.
  analogWrite(led_pin, led_level);
  delay(50);
}

//RAndom test
// an alternate test