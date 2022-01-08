// C++ code
//

int LEDPIN=12;
unsigned long lastTimeLedBlinked = millis();
unsigned long delayBetweenBlink = 500;
int ledState=LOW;

void setup()
{
  pinMode(LEDPIN, OUTPUT);
}

void loop()
{
  unsigned long CurrentTime = millis();
  if (CurrentTime - lastTimeLedBlinked > delayBetweenBlink)
  {
    if(ledState==LOW)
    {
      ledState=HIGH;
    }
    else
    {
      ledState=LOW;
    }
  digitalWrite(LEDPIN,ledState);
  lastTimeLedBlinked=CurrentTime;
  }
}