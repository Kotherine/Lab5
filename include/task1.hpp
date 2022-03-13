// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_TASK1_HPP_
#define INCLUDE_TASK1_HPP_

#include <utility>
#include "Node.h"
#include <iostream>

template <typename T>
class Stack1 {
 protected:
  Node<T>* head_stack = nullptr;  //
 public:
  Stack1() = default;
  Stack1(const Stack1& s) = delete;       // некопируемый стек
  Stack1(Stack1&& s) noexcept = default;  //
  ~Stack1();
  auto operator=(const Stack1& s) -> Stack1& = delete;  // некопируемый стек
  auto operator=(Stack1&& s) noexcept -> Stack1& = default;

  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;

  size_t stack_size() const;
};

  template<typename T>
  Stack1<T>::~Stack1() {
    while (head_stack != nullptr) {
      Node<T>* current_node = head_stack;
      head_stack = head_stack->p;
      delete current_node;
    }
  }

  template <typename T>
  void Stack1<T>::push(T&& value) {
    auto* new_node = new Node<T>{std::forward<T>(value), head_stack};
    head_stack = new_node;
  }

  template <typename T>
  void Stack1<T>::push(const T& value) {
    auto* new_node = new Node<T>{value, head_stack};
    head_stack = new_node;
  }

  template <typename T>
  void Stack1<T>::pop() {
    if (head_stack == nullptr) throw std::exception();
    Node<T>* current_node = head_stack;
    head_stack = head_stack->p;
    delete current_node;
  }

  template <typename T>
  const T& Stack1<T>::head() const {
    if (head_stack == nullptr) throw std::exception();
    return head_stack->value;
  }

  template <typename T>
  size_t Stack1<T>::stack_size() const {
    size_t s = 0;
    Node<T>* current_node = head_stack;
    while (current_node != nullptr) {
      s++;
      current_node = current_node->p;
    }
    return s;
  }

#endif // INCLUDE_TASK1_HPP_
