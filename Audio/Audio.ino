#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup(){
tmrpcm.speakerPin = 9;
Serial.begin(9600);


}

void loop(){
play1();
 }

void play1(){
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }  

  Serial.println("SD card initialized.");
  if (SD.exists("j.wav")) {
    Serial.println("File exists.");
  } else {
    Serial.println("File does not exist.");
  }

Serial.print("Playing");
    tmrpcm.setVolume(5);
      
    tmrpcm.play("pano.wav");  

}