
// https://www.online-convert.com/
// SETTINGS !
// 8 BIT - Change Bit Resolution
// 11025 Hz - Change sampling rate
// MON0 - Change audio channels

/*
TMRpcm audio;
audio.play("filename");    plays a file
audio.play("filename",30); plays a file starting at 30 seconds into the track
audio.play(F("filename")); plays a file storing the string in program memory instead of RAM
audio.speakerPin = 11;     set to 5,6,11 or 46 for Mega, 9 for Uno, Nano, etc.
audio.disable();           disables the timer on output pin and stops the music
audio.stopPlayback();      stops the music, but leaves the timer running
audio.isPlaying();         returns 1 if music playing, 0 if not
audio.pause();             pauses/unpauses playback
audio.quality(1);          Set 1 for 2x oversampling
audio.volume(0);           1(up) or 0(down) to control volume
audio.setVolume(0);        0 to 7. Set volume level
audio.loop(1);             0 or 1. Can be changed during playback for full control of looping. 
*/ 
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>




#include <SD.h>

#include <SPI.h>

//#include "SD.h"
#define SD_ChipSelectPin 10
//#include "TMRpcm.h"
//#include "SPI.h"

TMRpcm tmrpcm;

int menu = 0; // the current menu

void setup(){
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
}

void loop(){

  checkSDCard();
  tmrpcm.setVolume(5);


//  night mode
  tmrpcm.play("night.wav");
  while (tmrpcm.isPlaying()); 
  
  tmrpcm.play("day.wav");
  while (tmrpcm.isPlaying()); 

  tmrpcm.play("sos.wav");
  while (tmrpcm.isPlaying()); 

  tmrpcm.play("stand.wav");
  while (tmrpcm.isPlaying()); 

  tmrpcm.play("time.wav");
  while (tmrpcm.isPlaying()); 

}

bool checkSDCard(){
  while (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  } 
  Serial.println("working");
  return true;
}
