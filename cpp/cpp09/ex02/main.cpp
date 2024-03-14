#include "Pmerge.hpp"

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "Error" << std::endl;
    return 1;
  }
  Pmerge p(ac, av);
  p.sortPmerge(ac);
  p.printResult();
  return 0;
}