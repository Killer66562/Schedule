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
  this->goal = 100;
  this->number = 0;
  this->sevseg = ss;
}

void SevSegDisplayer::call() {
  if (is_paused()) return;

  counter = counter + 1;
  if (counter >= 10000) {
    counter = 0;
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
  sevseg->refreshDisplay();
}