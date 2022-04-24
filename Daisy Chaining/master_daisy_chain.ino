#include<SPI.h>
#define LED 7
#define button1 6
#define button2 5

int LEDState;
int buttonState1;
int buttonState2;
int slave = 0 ;
volatile boolean received;
volatile byte SlaveReceived;
int itr;
char masterSend, masterReceive;
void setup()

{
  Serial.begin(9600);

  pinMode(LED,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  SPCR =(1<<SPE)|(1<<MSTR);
  received = false;

  SPI.attachInterrupt();

}

void loop(void)
{
  

  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);

  if (buttonState1 == HIGH)
  {
    digitalWrite(SS, LOW);
    masterSend = '0';
    Serial.println((String)"Data sent:" + masterSend);

  }
  if (buttonState2 == HIGH)
  { masterSend = '1';
    Serial.println((String)"Data sent:" + masterSend);
    digitalWrite(SS, LOW);
  }
}


void blink(void)
{
  for(itr = 0; itr <= 2; itr ++)
  {
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    delay(100);
  }
}


ISR (SPI_STC_vect)
{
  SlaveReceived = SPDR;
  received = true;
}

void loop1()
{
  if(received)
  {
    if(SlaveReceived == "0")
    {
      blink();
    }
    if(SlaveReceived == "1")
    {
      SPI.transfer(SlaveReceived);
      delay(100);
    }
  }
  masterSend ="1";
  Serial.println((String)"Data sent:"+masterReceive);
  SPI.transfer(masterSend);
  Serial.println((String)"Data sent:"+masterSend);
  delay(200);
  
}



  
