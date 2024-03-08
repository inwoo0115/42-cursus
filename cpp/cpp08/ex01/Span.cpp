#include "Span.hpp"

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span& obj) { *this = obj; }

Span& Span::operator=(const Span& obj) {
  if (this != &obj) {
    this->size = obj.size;
    this->v = obj.v;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int n) {
  if (v.size() == size) {
    throw std::runtime_error("Cannot store more value");
  }
  v.push_back(n);
}

void Span::addNumberRange(std::vector<int>::iterator begin,
                          std::vector<int>::iterator end) {
  if (v.size() + (end - begin) > size) {
    throw std::runtime_error("Cannot store more values");
  }
  v.insert(v.end(), begin, end);
}

unsigned int Span::shortestSpan() {
  if (v.size() < 2) throw std::runtime_error("Size is too small");
  std::vector<int> tmp = v;
  std::sort(tmp.begin(), tmp.end());
  unsigned int result = *(tmp.begin() + 1) - *tmp.begin();
  for (std::vector<int>::iterator it = tmp.begin(); it < tmp.end() - 1; it++) {
    if (result > static_cast<unsigned int>(*(it + 1) - *it))
      result = static_cast<unsigned int>(*(it + 1) - *it);
  }
  return (result);
}

unsigned int Span::longestSpan() {
  if (v.size() < 2) throw std::runtime_error("Size is too small");
  int max = *std::max_element(v.begin(), v.end());
  int min = *std::min_element(v.begin(), v.end());
  return (max - min);
}
