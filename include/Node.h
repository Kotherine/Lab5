//
// Created by ekaterina on 13.03.2022.
//

#ifndef TEMPLATE_NODE_H
#define TEMPLATE_NODE_H

template <typename T>
struct Node {
  T value; // значение
  Node<T>* p; // указатель на следующий элемент стека
};

#endif  // TEMPLATE_NODE_H
