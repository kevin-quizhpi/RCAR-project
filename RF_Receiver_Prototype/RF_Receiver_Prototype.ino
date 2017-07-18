


/*
  Simple example for receiving
  
  http://code.google.com/p/rc-switch/
  
  Need help? http://forum.ardumote.com
*/

#include "RCSwitch.h"
#include "DRV8835DualMotorDriver.h"

#define mode 13
#define aPH 6
#define aEN 10
#define bPH 7
#define bEN 11

DRV8835DualMotorDriver motors(aPH, aEN, bPH, bEN, mode);


RCSwitch mySwitch = RCSwitch();
int spd = 50;

void setup() {
  Serial.begin(9600);
  motors.SetPinMode();
  mySwitch.enableReceive(0);  // Receiver on inerrupt 0 => that is pin #2
  motors.setSpeedBoth(spd);
//  motors.stopBoth();
  Serial.println("Leaving setup.");
  motors.setAClockwise();
}

void loop() {
  motors.setForwards();
 
  //Serial.println("In loop!");
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {

      Serial.print("Received ");
      Serial.print( value );
      Serial.print(" / ");
      Serial.print( mySwitch.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.print( mySwitch.getReceivedProtocol() );
      Serial.print(" / Delay: ");
      Serial.print(mySwitch.getReceivedDelay());
    }
//
//    if( value == -29676)
//    { 
//                     motors.setForwards();
//
//                     Serial.println("Case 1 !");
//                     digitalWrite(12,HIGH);
//                     
//    }
//    if(value == -32748)
//    {
//                     motors.setBackwards();
//
//                     digitalWrite(12,LOW);
//                     Serial.println("Case 2 !");
//    }
      switch (value)
      {
        case (1):   spd = (spd - 10);
                    Serial.print("Speed: ");
                    Serial.println(spd);

        case (2):   spd = (spd + 10);
                    Serial.print("Speed: ");
                    Serial.println(spd);

        case (3):   spd = (spd + 10);
                    Serial.print("Speed: ");
                    Serial.println(spd);
                    
        case (4):   spd = (spd -10);
                    Serial.print("Speed: ");
                    Serial.println(spd);
      }
      if(value == 1 || value == 2)
        motors.setSpeedB(spd);
      else 
        motors.setSpeedA(spd);
                
           

 
    

    mySwitch.resetAvailable();
  }
}





















