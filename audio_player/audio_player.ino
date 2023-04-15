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
  tmrpcm.setVolume(5);
  tmrpcm.play("1.wav");  

}
