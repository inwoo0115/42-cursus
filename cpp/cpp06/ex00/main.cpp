#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Wrong argument" << std::endl;
    return (0);
  }
  try {
    ScalarConverter::convert(av[1]);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}