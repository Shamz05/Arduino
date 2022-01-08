int sensorValue = 0;
float sensor_actual ;
int LEDPIN = 11;
int value;

void setup()
{
  pinMode(A0, INPUT);
    pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  
  sensorValue = analogRead(A0);
  
 
  sensor_actual=sensorValue*(0.18);
  value = int(sensor_actual);
  analogWrite(LEDPIN,value );
   Serial.println(sensorValue);
   Serial.println(sensor_actual);
  
  Serial.println(value);
  delay(10);
}