int buttonPin = 2;    
int ledPin =  13;    
int buttonPress=0;

void setup()
{  
 pinMode (ledPin, OUTPUT);
 pinMode (buttonPin, INPUT);
 Serial.begin(9600);
}

void loop()
{
  buttonPress=digitalRead(buttonPin);
  if(buttonPress==1){
    digitalWrite(ledPin,HIGH);
    Serial.println(buttonPress);
    delay(500);
    buttonPress=digitalRead(buttonPin);
    if(buttonPress == 0){
      digitalWrite(ledPin,LOW);
      Serial.println(buttonPress);
      
    }
  }
  else{
    delay(100);
  }
    
}


