#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

class Pmerge {
 private:
  std::vector<int> v;
  std::deque<int> d;
  clock_t vtime;
  clock_t dtime;

  Pmerge();
  Pmerge(const Pmerge &obj);
  Pmerge operator=(const Pmerge &obj);

 public:
  Pmerge(int ac, char **av);
  ~Pmerge();
  void sortPmerge(int ac);
  void printResult();

  void sortVector(int size, int gap);
  void insertSortVector(int size, int gap);
  void binaryInsertVector(int range, int num, int gap, int bIndex,
                          std::vector<int> b);

  void sortDeque(int size, int gap);
  void insertSortDeque(int size, int gap);
  void binaryInsertDeque(int range, int num, int gap, int bIndex,
                         std::deque<int> b);
};

#endif