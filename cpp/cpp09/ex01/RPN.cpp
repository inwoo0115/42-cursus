#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void RPN::rpn(std::string av) {
  int value;
  std::stringstream ss(av);
  std::string token;
  while (std::getline(ss, token, ' ')) {
    if (token == "+" || token == "-" || token == "*" || token == "/")
      operation(token);
    else {
      std::istringstream(token) >> value;
      _stack.push(value);
    }
  }
  if (_stack.size() != 1) throw std::runtime_error("Error");
  std::cout << _stack.top() << std::endl;
}

void RPN::operation(std::string token) {
  if (_stack.size() < 2) throw std::runtime_error("Error");
  int value1 = _stack.top();
  _stack.pop();
  int value2 = _stack.top();
  _stack.pop();
  if (token == "+") {
    _stack.push(value1 + value2);
  } else if (token == "-") {
    _stack.push(value2 - value1);
  } else if (token == "*") {
    _stack.push(value1 * value2);
  } else if (token == "/") {
    _stack.push(value2 / value1);
  } else
    throw std::runtime_error("Error");
}