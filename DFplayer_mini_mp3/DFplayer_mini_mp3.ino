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
  myDFPlayer.volume(30);
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);


  

}
byte volumeLevel = 0;
int currentVal = 0;
void loop() {
  // put your main code here, to run repeatedly:
//  volumeLevel = map(analogRead(A0), 0, 1023, 0, 30); 

  

//  myDFPlayer.randomAll();

  myDFPlayer.playMp3Folder(1); //8am
  delay(6000);

    myDFPlayer.playMp3Folder(2); //9am
  delay(6000);
  
    myDFPlayer.playMp3Folder(3); //10am
  delay(6000);
  
    myDFPlayer.playMp3Folder(4); //11am
  delay(6000);
  
    myDFPlayer.playMp3Folder(5); //12pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(6); //1pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(7); //2pm
  delay(6000);  
  
  myDFPlayer.playMp3Folder(8); //3pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(9); //4pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(10); //5pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(11); //6pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(12); //7pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(13); //8pm
  delay(6000);
  
    myDFPlayer.playMp3Folder(14); //9pm
  delay(6000);

myDFPlayer.play(1); //Daymode is selected
delay(6000);
 
myDFPlayer.play(2);  //Nightmode is selected
delay(6000);

myDFPlayer.play(3);  //Rainmode is selected
delay(6000);
 
myDFPlayer.play(4);  //SOS is selected
delay(6000);
  
myDFPlayer.play(5);  //Obstacle is detected
delay(6000);
  
myDFPlayer.play(6);  //Timecheck is detected
delay(6000);
  
myDFPlayer.play(7);  //Light place
delay(6000);
  
myDFPlayer.play(8);  //Darkplace place
  delay(6000); 
  
  myDFPlayer.play(9);  //No mode is seleted
  delay(6000);

  
//// myDFPlayer.randomAll();
////  Serial.println();
//  if (!digitalRead(3)){
//    myDFPlayer.next();
//  }

 
//  

  
}