#include "Stack.h"
#include "Queue.h"
#include "Scheduleable.h"

#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

class Scheduler : Scheduleable {
  private:
  Stack<Scheduleable*>* p_stack;
  Queue<Scheduleable*>* p_queue;
  public:
  Scheduler();
  Scheduler(unsigned int n);
  void call() override;
  void call_bg() override;
  void add(Scheduleable* s);
};

#endif