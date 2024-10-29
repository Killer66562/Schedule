#include "HardwareSerial.h"
#include "Arduino.h"
#include "Scheduler.h"
#include "Scheduleable.h"

void Scheduler::add(Scheduleable *s) {
  this->p_queue->enqueue(s);
}

Scheduler::Scheduler(){
  this->p_stack = new Stack<Scheduleable*>(0);
  this->p_queue = new Queue<Scheduleable*>(0);
}

Scheduler::Scheduler(unsigned int n) {
  this->p_stack = new Stack<Scheduleable*>(n);
  this->p_queue = new Queue<Scheduleable*>(n);
}

void Scheduler::call() {
  if (!p_stack->is_empty()) {
    Scheduleable* top = p_stack->top();
    top->call();
    if (top->is_exited()) p_stack->pop();
    else if (top->is_paused()) {
      Scheduleable* next_p = top->get_next_p();
      if (next_p != nullptr) {
        p_stack->push(next_p);
        top = p_stack->top();
      }
      else if (!p_stack->is_empty()) top->resume();
    }
    else {}
  }

  if (!p_queue->is_empty()) {
    Scheduleable* current = p_queue->front();
    current->call_bg();
    p_queue->dequeue();
    if (current->is_ready() && !p_stack->exists(current))
      p_stack->push(current);
    p_queue->enqueue(current);
  }

  return;
}

void Scheduler::call_bg() {}