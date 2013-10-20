//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8,9}; 
int current;
int previous;

void setup()
{
  Serial.begin(9600);           // set up Serial library at 9600 bps
  
  Serial.println("Ready!");
 
  for(int i = 0; i < 8; i++){        
      pinMode(ledPins[i],OUTPUT);  
  }
  
 Serial.println("Enter a pin 0 - 8");
}
 
 

void loop()                     
{
  if (Serial.available())
  {
    char ch = Serial.read();
    if (ch >= '0' && ch <= '7')
     {
       current = ch - '0';
       
       digitalWrite(ledPins[previous], LOW);
       previous = current; // new previous
       digitalWrite(ledPins[current], HIGH);
     } 
     else
     {
       Serial.println("Not a valid pin");
     }
  }
}
