#include "Queue.h"
#include "Scheduleable.h"

template<typename T>
void Queue<T>::enqueue(T val) {
  this->arr[this->idx_e] = val;
  this->idx_e = (this->idx_e + 1) % size;
  if (this->idx_e == this->idx_f) full = true;
}

template<typename T>
void Queue<T>::dequeue() {
  this->idx_f = (this->idx_f + 1) % size;
  this->full = false;
}

template<typename T>
T Queue<T>::front() {
  return this->arr[this->idx_f];
}

template<typename T>
T Queue<T>::end() {
  if (idx_e == 0) return this->arr[size - 1];
  else return this->arr[this->idx_e - 1];
}

template<typename T>
unsigned int Queue<T>::count() {
  if (this->full) return size;
  else if (this->idx_e >= this->idx_f) return this->idx_e - this->idx_f;
  else return size - (this->idx_f - this->idx_e);
}

template<typename T>
bool Queue<T>::is_empty() {
  return idx_f == idx_e && !full;
}

template<typename T>
bool Queue<T>::is_full() {
  return full;
}

template<typename T>
Queue<T>::Queue() {
  this->idx_f = 0;
  this->idx_e = 0;
  this->size = 0;
  this->arr = new T[this->size];
  this->full = false;
}

template<typename T>
Queue<T>::Queue(unsigned int n) {
  this->idx_f = 0;
  this->idx_e = 0;
  this->size = n;
  this->arr = new T[this->size];
  this->full = false;
}

template class Queue<Scheduleable*>;