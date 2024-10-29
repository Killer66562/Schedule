#include "Stack.h"
#include "Scheduleable.h"

template<typename T>
Stack<T>::Stack() {
  this->size = 0;
  this->idx = 0;
  this->arr = new T[this->size];
}

template<typename T>
Stack<T>::Stack(unsigned int n) {
  this->size = n;
  this->idx = 0;
  this->arr = new T[this->size];
}

template<typename T>
T Stack<T>::top() {
  return *(this->arr + (idx - 1));
}

template<typename T>
void Stack<T>::push(T val) {
  *(this->arr + idx) = val;
  ++idx;
}

template<typename T>
void Stack<T>::pop() {
  --idx;
}

template<typename T>
bool Stack<T>::is_empty() {
  return this->idx == 0;
}

template<typename T>
bool Stack<T>::is_full() {
  return this->idx >= this->size;
}

template<typename T>
void Stack<T>::clear() {
  this->idx = 0;
}

template<typename T>
unsigned int Stack<T>::count() {
  return this->idx;
}

template<typename T>
bool Stack<T>::exists(T val) {
  bool exist = false;
  for (unsigned int i = 0; i < idx; ++i) {
    if (arr[i] == val) {
      exist = true;
    }
  }
  return exist;
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<bool>;
template class Stack<Scheduleable*>;