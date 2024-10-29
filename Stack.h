#ifndef _STACK_H_
#define _STACK_H_

template<typename T>
class Stack {
  unsigned int size;
  unsigned int idx;
  T* arr;
  public:
  Stack();
  Stack(unsigned int n);
  T top();
  void push(T val);
  void pop();
  bool is_empty();
  bool is_full();
  void clear();
  unsigned int count();
  bool exists(T val);
};

#endif