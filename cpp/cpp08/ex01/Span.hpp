#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span {
 private:
  unsigned int size;
  std::vector<int> v;
  Span();

 public:
  Span(unsigned int n);
  Span(const Span& obj);
  Span& operator=(const Span& obj);
  ~Span();
  void addNumber(int n);
  unsigned int shortestSpan();
  unsigned int longestSpan();
};

#endif