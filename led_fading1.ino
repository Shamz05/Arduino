// C++ code
//
int ledPin = 9;

void setup()
{
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  for(int ledVal=0; ledVal<=225;ledVal+=1){ 
    analogWrite(ledPin,ledVal);
    delay(15);
  }
  for(int ledVal=255; ledVal>=0; ledVal-=1){
    analogWrite(ledPin,ledVal);
    delay(15);
  }
  delay(1000);
} 
    