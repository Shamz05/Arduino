// C++ code
//
void setup()
{
  pinMode(2, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  if (digitalRead(2) == 1)
  {
    digitalWrite(9, HIGH);
    delay(100);
    digitalWrite(9, LOW);
    delay(100);
  }
}