#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
 private:
  unsigned int len;
  T* arr;

 public:
  Array(void) {
    arr = new T[0];
    len = 0;
  }

  Array(unsigned int n) {
    arr = new T[n];
    len = n;
  }

  Array(const Array& obj) {
    len = obj.size();
    arr = new T[len];
    for (unsigned int i = 0; i < len; i++) {
      arr[i] = obj[i];
    }
  }

  Array& operator=(const Array& obj) {
    if (this != &obj) {
      delete[] arr;
      len = obj.size();
      T* tmp = new T[len];
      for (unsigned int i = 0; i < len; i++) {
        tmp[i] = obj[i];
      }
      arr = tmp;
    }
    return (*this);
  }

  T& operator[](const int index) {
    if (index < 0 || index >= static_cast<int>(len))
      throw IndexOutOfRangeException();
    return (arr[index]);
  }

  const T& operator[](const int index) const {
    if (index < 0 || index >= static_cast<int>(len))
      throw IndexOutOfRangeException();
    return (arr[index]);
  }

  ~Array(void) { delete[] arr; }

  unsigned int size() const { return len; }

  class IndexOutOfRangeException : public std::exception {
   public:
    const char* what() const throw() { return "Index is out of range"; };
  };
};

#endif