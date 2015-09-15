// Increase LED Brightnesss on each switch toggle and then reset to zero.
// Author: Tarun Kumar

int switch_pin = 8;
int led_pin = 3;
boolean last_state = LOW; // Tracks last state of switch
boolean current_state; // Tracks current state of switch
int led_on = 0; 

void setup()
{
  pinMode(switch_pin, INPUT);
  pinMode(led_pin, OUTPUT);

}

boolean debounce(boolean last_state)
{
  // To avoid debounce.
  // If current state remains change from last state after 5 ms 
  // then state is indeed changed.
  current_state = digitalRead(switch_pin);
  if (current_state != last_state)
  {
    delay(5);
    current_state = digitalRead(switch_pin);
  }
  return current_state;
}

void loop()
{
  current_state = debounce(last_state); // Get real current state.
  if (current_state == HIGH && last_state == LOW) // When switch is pressed brightness is changed.
  {
    led_on += 51;
    analogWrite(led_pin, led_on);
    last_state = HIGH;
  }
  else if (last_state == HIGH && current_state == LOW) // On release reset last switch state to low.
  {
    last_state = LOW;
  }
}
