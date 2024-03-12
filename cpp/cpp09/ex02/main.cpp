#include "Pmerge.hpp"

int main(int ac, char **av) {
  Pmerge p(ac, av);
  p.sortPmerge(ac);
  p.printResult();
  return 0;
}