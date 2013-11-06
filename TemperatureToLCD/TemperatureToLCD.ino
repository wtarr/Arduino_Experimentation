int tempPin = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float temp = getVoltage(tempPin);
  
  temp = (temp - .5) * 100;
  
  Serial.println(temp);
  delay(100);
}

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
