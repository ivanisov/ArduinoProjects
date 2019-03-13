#define BUTTON_PIN 9
#define LEDS_COUNT 7

int currentValue;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);

  for (int i = 0; i < LEDS_COUNT; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    for (int i = 0; i < LEDS_COUNT; i++)
    {
      digitalWrite(i, LOW);
    }
    delay(500);
    currentValue = random(1, LEDS_COUNT);
  }

  show(currentValue);
}

void show(int value)
{
  switch (value)
  {
    case 1: // One
      digitalWrite(3, HIGH);
      break;
    case 2: // Two
      digitalWrite(0, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 3: // Three
      digitalWrite(0, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 4: // Four
      digitalWrite(0, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 5: // Five
      digitalWrite(0, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(6, HIGH);
      break;
    case 6: // Six
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;
  }
}
