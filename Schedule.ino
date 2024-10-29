#include "SevSeg.h"
#include <DFMiniMp3.h>
#include "Mp3Notify.h"
#include "SevSegDisplayer.h"
#include "Stack.h"
#include "Scheduler.h"

SevSeg sevseg;
DfMp3 dfmp3(Serial1);
Stack<Scheduleable*> p_stack(1);
SevSegDisplayer ssd(&sevseg);
Scheduler s(1);

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));

  byte numDigits = 4;
  byte digitPins[] = {33, 25, 23, 22}; //0-numDigits
  byte segmentPins[] = {31, 27, 26, 30, 32, 29, 24, 26}; //a-h
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
  sevseg.setNumber(0);
  sevseg.refreshDisplay();
  
  dfmp3.begin();
  dfmp3.reset();
  dfmp3.setVolume(10);
  dfmp3.playGlobalTrack(1);

  s.add(&ssd);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  s.call();
}
