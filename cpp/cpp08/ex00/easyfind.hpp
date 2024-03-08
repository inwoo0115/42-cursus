#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int i) {
  typename T::iterator it;
  it = std::find(container.begin(), container.end(), i);
  if (it == container.end()) throw std::runtime_error("No value in container");
  return it;
}

#endif