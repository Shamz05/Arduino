

////SLAVE  2////
#include <SPI.h>

int ledPin = 7;
int pushButton = 8;
volatile boolean received;
volatile byte Slavereceived, Slavesend;
int buttonValue;
int x;

void setup()
{
    Serial.begin(9600);
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
    }

    if (received)
    {
        if (Slavereceived == 2)
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
            Serial.println(Slavereceived);
        }
        else if (Slavereceived == 3)
        {
            digitalWrite(SS, LOW);
            // SPDR = 3;
            SPI.transfer(Slavereceived);
            delay(10);
            digitalWrite(SS, HIGH);
            // Serial.println(Slavereceived);
        }
        else
        {
            SPI.transfer(Slavereceived);
            delay(10);
        }
        received = false;
    }
}
