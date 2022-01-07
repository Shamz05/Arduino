// C++ code
//
int ledState = 0;
int ledPin = 8;
int buttonPin = 2;
int buttonStateNew;
int buttonStateOld = 1;

void setup()
{
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT);
}

void loop ()
{
  buttonStateNew = digitalRead(buttonPin);

  if (buttonStateOld == 0 && buttonStateNew == 1)
  {
    if (ledState == 0) {
      digitalWrite (ledPin, HIGH);
      ledState = 1;
    }
    else
    {
      digitalWrite(ledPin, LOW);
      ledState = 0;
    }
  }
  buttonStateOld = buttonStateNew;
}