#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T* arr, size_t length, F func) {
  for (size_t i = 0; i < length; i++) {
    // std::cout << func(arr[i]) << std::endl;
    func(arr[i]);
  }
}

template <typename T>
void print(T str) {
  std::cout << str << std::endl;
}

template <typename T>
void addOne(T& i) {
  i = i + 1;
}

#endif