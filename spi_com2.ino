//MASTER CODE
#include <SPI.h>
#define push 2
#define LED 7

int x;
int value;
 
void setup()
{
  Serial.begin(115200);
  
  pinMode(push,INPUT);
  pinMode(LED,OUTPUT);
  
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  digitalWrite(SS,HIGH);
 
}

void loop(void)
{
  byte m_send,m_receiver;
  
  value=digitalRead(push);
  
  if(value==HIGH)
  {
    x=1;
  }
  else
  {
    x = 0;
  }
  digitalWrite(SS,LOW);
  
  m_send=x;
  m_receiver=SPI.transfer(m_send);
  
  if(m_receiver == 1)
  {
    digitalWrite(LED,HIGH);
  }
  else
  {
    digitalWrite(LED,LOW);
  }
  delay(100);
}