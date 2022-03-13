// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_TASK2_HPP_
#define INCLUDE_TASK2_HPP_

#include <utility>
#include "Node.h"
#include <iostream>

template <typename T>
class Stack2 {
 protected:
  Node<T>* head_stack = nullptr; //
 public:
  Stack2() = default;
  Stack2(const Stack2& s) = delete;       // некопируемый стек
  Stack2(Stack2&& s) noexcept = default;  //
  ~Stack2();
  auto operator=(const Stack2& s) -> Stack2& = delete;  // некопируемый стек
  auto operator=(Stack2&& s) noexcept -> Stack2& = default;

  template <typename ... Args>
  void push_emplace(Args&&... value);
  void push(T&& value);
  const T& head() const;
  T pop();

  size_t stack_size() const;
};

  template<typename T>
  Stack2<T>::~Stack2() {
    while (head_stack != nullptr) {
      Node<T>* current_node = head_stack;
      head_stack = head_stack->p;
      delete current_node;
    }
  }

  template <typename T>
  template <typename... Args>
  void Stack2<T>::push_emplace(Args&&... value) {
    if ((std::is_copy_constructible<T>::value) ||
      (std::is_copy_assignable<T>::value)) {
      throw std::exception();
    }
    head_stack =
      new Node<T>{{std::forward<Args>(value)...}, head_stack};
  }

  template <typename T>
  void Stack2<T>::push(T&& value) {
    if ((std::is_copy_constructible<T>::value) ||
      (std::is_copy_assignable<T>::value)) {
      throw std::exception();
    }
    head_stack =
      new Node<T>{std::forward<T>(value), head_stack};
}

  template <typename T>
  const T& Stack2<T>::head() const {
    if (head_stack == nullptr) throw std::exception();
    return head_stack->value;
  }

  template <typename T>
  T Stack2<T>::pop() {
    if (Stack2<T>::head_stack == nullptr) {
      throw std::exception();
    }
    auto* current_node = head_stack;
    T value = std::move(head_stack->value);
    head_stack = head_stack->p;
    delete current_node;
    return value;
 }

  template <typename T>
  size_t Stack2<T>::stack_size() const {
    size_t s = 0;
    Node<T>* current_node = head_stack;
    while (current_node != nullptr) {
      s++;
      current_node = current_node->p;
    }
    return s;
  }
#endif  // INCLUDE_TASK2_HPP_
