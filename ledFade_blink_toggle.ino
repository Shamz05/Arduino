int ledPin = 11;
int buttonPin=2; 
int val=0;
int ledVal=0;
int fadeam=1;
int lastVal;
int buttonNew;
int buttonOld;
int NewVal;
int LEDState=0;
int i=0;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  
}   

void delay_ms(int d)
{
  for(int j=0; j<d; j++)
  {
    delay(0.01);
    val=digitalRead(buttonPin);
    if(val)
    {
      
      i++;
      delay(500);
      }
  }
}

void blink()
{
  analogWrite(ledPin,ledVal);
  delay_ms(10000);
  analogWrite(ledPin,0);
  delay_ms(10000);
   
}

void loop()
{
 /* val=digitalRead(buttonPin);
  if(val)
  {
    delay(500);
    i++;
  }*/
int k=i%2;
Serial.println(k);
switch(k)
{
  case 0:
  {
    
    ledVal = ledVal + fadeam;
    if (ledVal <= 0 || ledVal >= 255)
    {
      fadeam = -fadeam;
    }
    analogWrite(ledPin, ledVal);
    delay_ms(100);
  
  //Serial.println(ledVal);
  break;
  }

  case 1:
  {
  //fadeam=-fadeam;
  //digitalWrite(buttonPin,HIGH);
  //Serial.println(val);
  //Serial.println(ledVal);
  blink();
  delay_ms(100);
 
  break;
    }
  
  
    
    
  default:
  {
    
    analogWrite(ledPin, ledVal);
    ledVal = ledVal + fadeam;
    if (ledVal <= 0 || ledVal >= 255)
    {
      fadeam = -fadeam;
    }
    //Serial.println(ledVal);
  }
}
}


  
  
  
  
  
  
    
    /*
    digitalWrite(buttonPin,LOW);
    for(int ledVal=0; ledVal<=255;ledVal+=1){ 
    analogWrite(ledPin,ledVal);
    delay(10);
    }
    for(int ledVal=255; ledVal>=0; ledVal-=1){
    analogWrite(ledPin,ledVal);
    delay(10);
    }*/



  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*{
  analogWrite(ledPin, ledVal);
  ledVal = ledVal + fadeam;

  
  if (ledVal <= 0 || ledVal >= 255)
  {
    fadeam = -fadeam;
  }
  delay(5);
  
 
val = digitalRead(buttonPin);
    if(val==HIGH)
    {
      fadeam=0;
      Serial.println(val);
      Serial.println(ledVal);
      blink();
    }
    
}*/

    



  
   
    
  



  
  
 






















/*  if(digitalRead(buttonPin)==1)
  {
    Serial.println(ledVal);
    Serial.println(buttonPin);
    analogWrite(ledPin,ledVal);
    delay(1000);
    analogWrite(ledPin,0);
    delay(1000);
  }
  }
  
  
}*/

  
  
  
  
  
  
  
  
  
  
  
  /*
  analogWrite(ledPin,ledVal);

  
  ledVal= ledVal + fade;

  
  if (ledVal <= 0 ||ledVal >= 255)
  {
    fade = -fade;
    delay(5);
*/

/*int ledPin = 11;
int buttonPin=2; 
int val=0;
int ledVal=0;
int fadeam=1;
int lastVal;
int buttonNew;
int buttonOld;
int NewVal;
int LEDState=0;
int i;
void setup()
{
  
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(buttonPin,INPUT);
  
}   



void blink()
{
  analogWrite(ledPin,ledVal);
  delay(500);
  analogWrite(ledPin,0);
  delay(500);
}

void loop()
{
  val=digitalRead(buttonPin);
switch(val)
{
  case 0:
  analogWrite(ledPin, ledVal);
  ledVal = ledVal + fadeam;
  if (ledVal <= 0 || ledVal >= 255)
  {
    fadeam = -fadeam;
  }
  Serial.println(ledVal);
  break;
  
  case 1:
  fadeam=0;
  digitalWrite(buttonPin,HIGH);
  Serial.println(val);
  Serial.println(ledVal);
  blink();
  break;
    
    
  default:
  {
    
    analogWrite(ledPin, ledVal);
    ledVal = ledVal + fadeam;
    if (ledVal <= 0 || ledVal >= 255)
    {
      fadeam = -fadeam;
    }
    Serial.println(ledVal);
  }
}
}*/


  
  
  
  
  
  
    
    /*
    digitalWrite(buttonPin,LOW);
    for(int ledVal=0; ledVal<=255;ledVal+=1){ 
    analogWrite(ledPin,ledVal);
    delay(10);
    }
    for(int ledVal=255; ledVal>=0; ledVal-=1){
    analogWrite(ledPin,ledVal);
    delay(10);
    }*/



  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*{
  analogWrite(ledPin, ledVal);
  ledVal = ledVal + fadeam;

  
  if (ledVal <= 0 || ledVal >= 255)
  {
    fadeam = -fadeam;
  }
  delay(5);
  
 
val = digitalRead(buttonPin);
    if(val==HIGH)
    {
      fadeam=0;
      Serial.println(val);
      Serial.println(ledVal);
      blink();
    }
    
}*/

    



  
   
    
  



  
  
 






















/*  if(digitalRead(buttonPin)==1)
  {
    Serial.println(ledVal);
    Serial.println(buttonPin);
    analogWrite(ledPin,ledVal);
    delay(1000);
    analogWrite(ledPin,0);
    delay(1000);
  }
  }
  
  
}*/

  
  
  
  
  
  
  
  
  
  
  
  /*
  analogWrite(ledPin,ledVal);

  
  ledVal= ledVal + fade;

  
  if (ledVal <= 0 ||ledVal >= 255)
  {
    fade = -fade;
    delay(5);
*/
