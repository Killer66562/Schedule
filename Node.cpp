#include "Node.h"

template<typename T>
Node<T>::Node() {
  this->next = nullptr;
}

template<typename T>
Node<T>::Node(T val) {
  this->next = nullptr;
  this->value = val;
}

template<typename T>
T Node<T>::get_value() {
  return this->value;
}

template<typename T>
void Node<T>::set_value(T val) {
  this->value = val;
}

template<typename T>
Node<T>* Node<T>::get_next() {
  return this->next;
}

template<typename T>
void Node<T>::set_next(Node<T> *node) {
  this->next = node;
}