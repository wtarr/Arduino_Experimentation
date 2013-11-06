int motorPin = 9;
String str;

void setup()
{
  Serial.begin(9600);
  
  Serial.println("Ready");
  
  pinMode(motorPin, OUTPUT);
  
  analogWrite(motorPin, 1);
}

void loop()                     // run over and over again
{
 if (Serial.available())
 {
   str = "";
   
   delay(100);
   while (Serial.available())
   {
     char d = Serial.read();
     str.concat(d);          
   }
   
   Serial.println("Recieved " + str);
   
   int num = str.toInt();
   
   if (num >= 0 && num <= 255)
  {
    motorSpeed(num);
  } 
  else
  {
   Serial.println("Value too high"); 
   }
   
   
   
 }
}

void motorSpeed(int speed){
  int delayTime = 50;   
  analogWrite(motorPin, speed);   //sets the new speed
  delay(delayTime);           // waits for delayTime milliseconds
}
