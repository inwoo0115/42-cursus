#include "RPN.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Wrong argument" << std::endl;
    return 1;
  }
  RPN r;
  try {
    r.rpn(av[1]);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}