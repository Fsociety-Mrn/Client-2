#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#define RX 10
#define TX 11

SoftwareSerial mySoftwareSerial(RX, TX); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  
  pinMode(3, INPUT_PULLUP);
  
  Serial.begin(115200);
  mySoftwareSerial.begin(9600);
  // put your setup code here, to run once:

  while (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
}
byte volumeLevel = 0;
int currentVal = 0;
void loop() {
  // put your main code here, to run repeatedly:
  volumeLevel = map(analogRead(A0), 0, 1023, 0, 30); 

  myDFPlayer.volume(volumeLevel);
// myDFPlayer.randomAll();
//  Serial.println();
  if (!digitalRead(3)){
    myDFPlayer.next();
  }

 
//  

  
}
