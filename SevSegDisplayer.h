#include "Scheduleable.h"
#include <SevSeg.h>

#ifndef _SEV_SEG_DISPLAYER_H_
#define _SEV_SEG_DISPLAYER_H_

class SevSegDisplayer : public Scheduleable {
  SevSeg* sevseg;
  unsigned int number;
  unsigned int counter;
  unsigned int goal;
  public:
  SevSegDisplayer();
  SevSegDisplayer(SevSeg* ss);
  virtual void call() override;
  virtual void call_bg() override;
};

#endif