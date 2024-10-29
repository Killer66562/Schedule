#include "Arduino.h"
#include "HardwareSerial.h"
#include "SevSegDisplayer.h"

SevSegDisplayer::SevSegDisplayer() : Scheduleable() {
  this->counter = 0;
  this->goal = 100;
  this->number = 0;
  this->sevseg = nullptr;
}

SevSegDisplayer::SevSegDisplayer(SevSeg* ss) : Scheduleable() {
  this->counter = 0;
  this->goal = 1000;
  this->number = 0;
  this->sevseg = ss;
}

void SevSegDisplayer::call() {
  static unsigned long prevTime = millis();

  sevseg->refreshDisplay();
  if (is_paused()) return;

  unsigned long currentTime = millis();
  if (currentTime - prevTime >= 1000) {
    prevTime = currentTime;
    number = number + 1;
    if (number >= goal) {
      sevseg->blank();
      _exit();
    }
    else sevseg->setNumber(number);
  }
}

void SevSegDisplayer::call_bg() {
  _ready();
}