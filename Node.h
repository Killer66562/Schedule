#ifndef _NODE_H_
#define _NODE_H_

template<typename T>
class Node {
  Node<T>* next;
  T value;
  public:
  Node<T>();
  Node<T>(T val);
  T get_value();
  void set_value(T val);
  Node<T>* get_next();
  void set_next(Node<T>* node);
};

#endif