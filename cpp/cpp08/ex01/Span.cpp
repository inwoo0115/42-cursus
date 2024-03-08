#include "Span.hpp"

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span& obj) {}

Span& Span::operator=(const Span& obj) {}

Span::~Span() {}

void Span::addNumber(int n) {
  if (v.size() == n) {
    throw std::runtime_error("Cannot store more value");
  }
  v.push_back(n);
}

unsigned int Span::shortestSpan() {}

unsigned int Span::longestSpan() {}
