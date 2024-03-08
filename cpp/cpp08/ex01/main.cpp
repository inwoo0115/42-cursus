#include <iostream>

#include "Span.hpp"

int main() {
  //   Span sp = Span(5);
  Span sp = Span(15000);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  try {
    std::vector<int> v;
    for (int i = 20; i < 11000; i++) {
      v.push_back(i);
    }
    sp.addNumberRange(v.begin(), v.end());
    std::cout << sp.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}