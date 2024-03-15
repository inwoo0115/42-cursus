#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
 private:
  std::stack<int> _stack;
  RPN(const RPN& obj);
  RPN operator=(const RPN& obj);

 public:
  RPN();
  ~RPN();
  void rpn(std::string av);
  void operation(std::string token);
};

#endif