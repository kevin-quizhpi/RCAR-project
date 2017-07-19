
#include "RCSwitch.h"
#define rLED 12
#define yLED 5
#define ptmeter A0
#define rUP 11
#define rDW 12
#define lUP 8
#define lDW 9
#define turn


RCSwitch mySwitch = RCSwitch();
int LEDinput[] = {1,2,3,4,255};
int counter = 0;

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(10);  // Using Pin #10
  pinMode(rLED,OUTPUT);
  pinMode(yLED,OUTPUT);
  pinMode(ptmeter,INPUT);
  pinMode(rUP,INPUT);
  pinMode(rDW,INPUT);
  pinMode(lUP,INPUT);
  pinMode(lDW,INPUT);
  pinMode(turn,INPUT);
}

void loop() {
//  mySwitch.send("00000100011000000000010100");
//  digitalWrite(12,HIGH);
//  delay(1000);
//  digitalWrite(12,LOW);
//  mySwitch.send("00000100011000110000010100");  
//  delay(1000);

    Serial.print("button pressed: ");
    Serial.print(digitalRead(lDW));
        Serial.print(" button pressed: ");
    Serial.print(digitalRead(lUP));
        Serial.print(" button pressed: ");
    Serial.print(digitalRead(rUP));
        Serial.print(" button pressed: ");
    Serial.print(digitalRead(rDW));
        Seria.print(" Turn pressed: ");
    Serial.println(digitalRead(turn);

    if(digitalRead(lDW) == LOW)
    {
      mySwitch.send(1,24);
    }
    if(digitalRead(lUP) == LOW)
    {
      mySwitch.send(2,24);
    }
    if(digitalRead(rUP) == LOW)
    {
      mySwitch.send(3,24);
    }
    if(digitalRead(rDW) == LOW)
    {
      mySwitch.send(4,24);
    }
    if(digitalRead(turn == LOW)
    {
      mySwitch.send(5,24);
    }
    else
      mySwitch.send(35,24);

   

  
//    int reading = analogRead(ptmeter);
//    Serial.print("Ptmeter value being sent: ");
//    Serial.println(reading);
//    mySwitch.send( reading,24);
    
 
  //mySwitch.send(LEDinput[counter%5], 24);
  
//  Serial.print("\nstate: ");
//  if( counter %5 == 0)
//  {
//    digitalWrite(rLED,LOW);
//    digitalWrite(yLED,LOW);
//    Serial.print(counter%5);
//  }
//  if(counter%5 == 1)
//  {
//    digitalWrite(rLED,HIGH);
//    digitalWrite(yLED,LOW);
//    Serial.print(counter%5);
//  }
//  if(counter%5 == 2)
//  {
//    digitalWrite(rLED,LOW);
//    digitalWrite(yLED,HIGH);
//    Serial.print(counter%5);
//  }
//  if(counter%5 == 3)
//  {
//    digitalWrite(rLED, HIGH);
//    digitalWrite(yLED,HIGH);
//    
//    Serial.print(counter%5);
//  }
// delay(500);
//  counter++;
  
    

  
}
