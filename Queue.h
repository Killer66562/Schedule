#ifndef _QUEUE_H_
#define _QUEUE_H_

template<typename T>
class Queue {
  unsigned int idx_f;
  unsigned int idx_e;
  unsigned int size;
  T* arr;
  bool full;
  public:
  Queue<T>();
  Queue<T>(unsigned int n);
  T front();
  T end();
  void enqueue(T val);
  void dequeue();
  bool is_empty();
  bool is_full();
  unsigned int count();
};

#endif