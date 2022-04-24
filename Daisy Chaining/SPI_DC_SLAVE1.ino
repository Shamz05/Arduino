////SLAVE 1////
#include <SPI.h>

int ledPin = 7;
int pushButton = 2;
volatile boolean received;
volatile byte Slavereceived, Slavesend;
int buttonValue;
int x;

void setup()
{
    // Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
    pinMode(pushButton, INPUT);
    pinMode(MISO, OUTPUT);
    pinMode(MOSI, INPUT);
    SPCR |= _BV(SPE);
    received = false;
    SPI.attachInterrupt();
}

ISR(SPI_STC_vect)
{
    Slavereceived = SPDR;
    received = true;
}

void loop()
{
    buttonValue = digitalRead(pushButton);

    if (buttonValue == HIGH)
    {
        x = 3;
        digitalWrite(ledPin, HIGH);
        delay(100);
        digitalWrite(ledPin, LOW);
        delay(100);
        SPI.transfer(x);
        delay(10);
        // SPDR = 3;
        // Serial.println(buttonValue);
    }
    if (received)
    {
        if (Slavereceived == 1)
        {
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
            delay(100);
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
            delay(100);
            digitalWrite(ledPin, HIGH);
            delay(100);
            digitalWrite(ledPin, LOW);
            delay(100);
        }
        else if (Slavereceived == 2)
        {
            SPI.transfer(Slavereceived);
            delay(10);
        }
        // Serial.println(Slavereceived);
        received = false;
    }
}
