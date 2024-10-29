#include "Scheduleable.h"

Scheduleable::Scheduleable() {
  exited = false;
  ready = false;
  paused = false;
}

bool Scheduleable::is_ready() {
  return this->ready;
}

bool Scheduleable::is_exited() {
  return this->exited;
}

bool Scheduleable::is_paused() {
  return this->paused;
}

Scheduleable* Scheduleable::get_next_p() {
  return this->next_p;
}

void Scheduleable::call() {
  this->exited = true;
  this->ready = false;
  this->next_p = nullptr;
}

void Scheduleable::call_bg() {}

void Scheduleable::reset() {
  this->exited = false;
}

void Scheduleable::_exit() {
  this->exited = true;
}

void Scheduleable::_ready() {
  this->ready = true;
}

void Scheduleable::pause() {
  this->paused = true;
}

void Scheduleable::resume() {
  this->paused = false;
}