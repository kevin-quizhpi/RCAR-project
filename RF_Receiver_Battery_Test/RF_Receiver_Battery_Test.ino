#include "RCSwitch.h"

#define rLED 8
#define yLED 9

RCSwitch receiver = RCSwitch();


void setup() {
  Serial.begin(9600);
  pinMode(rLED,OUTPUT);
  pinMode(yLED,OUTPUT);
  receiver.enableReceive(0);
  // put your setup code here, to run once:

}

void loop() {
  if(receiver.available())
  {
    int msg = receiver.getReceivedValue();

    Serial.print("Message: ");
    Serial.println(msg);

    if(msg == 1)
      digitalWrite(rLED,HIGH);
    if(msg == 2)
      digitalWrite(rLED,LOW);
    if(msg == 3)
      digitalWrite(yLED,HIGH);
    if(msg == 4)
      digitalWrite(yLED,LOW);
    


    
    receiver.resetAvailable();
  }
  // put your main code here, to run repeatedly:

}



