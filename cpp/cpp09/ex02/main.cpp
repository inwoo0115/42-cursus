#include "Pmerge.hpp"

int main(int ac, char **av) {
  Pmerge p(ac, av);
  p.sortVector(ac - 1, 1);
  p.sortDeque(ac - 1, 1);
  p.printResult();
  return 0;
}