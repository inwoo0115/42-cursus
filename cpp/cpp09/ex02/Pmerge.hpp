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
  time_t vtime;
  time_t dtime;

  Pmerge();
  Pmerge(const Pmerge &obj);
  Pmerge operator=(const Pmerge &obj);

 public:
  Pmerge(int ac, char **av);
  ~Pmerge();
  void printResult();
  void sortVector(int size, int gap);
  void sortDeque(int size, int gap);
  void insertSort(int size, int gap);
  void binaryInsert(int range, int num, int gap, int bIndex,
                    std::vector<int> b);
};

#endif