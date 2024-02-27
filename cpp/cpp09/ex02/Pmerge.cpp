#include "Pmerge.hpp"

Pmerge::~Pmerge(){};

Pmerge::Pmerge(int ac, char **av) : vtime(0), dtime(0) {
  for (int i = 1; i < ac; i++) {
    v.push_back(std::atoi(av[i]));
    d.push_back(std::atoi(av[i]));
  }
  std::cout << "Before (vector) : ";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << "\n" << std::endl;
  //   std::cout << "Before (deque) : ";
  //   for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
  //     std::cout << *it << " ";
  //   }
  //   std::cout << std::endl;
}

void Pmerge::printResult() {
  std::cout << "After (vector) : ";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  //   std::cout << "After (deque) : ";
  //   for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++) {
  //     std::cout << *it << " ";
  //   }
  //   std::cout << std::endl;
}

void Pmerge::sortVector(int size, int gap) {
  // merge and change index
  if (size <= 1) return;
  for (int i = 0; i < size - 1; i += 2) {
    if (v[i * gap] < v[(i + 1) * gap]) {
      std::vector<int>::iterator start = v.begin() + i * gap;
      std::vector<int>::iterator end = start + gap;
      std::swap_ranges(start, end, end);
    }
  }
  sortVector(size / 2, gap * 2);
  insertSort(size, gap);
}

void Pmerge::sortDeque(int size, int gap) {
  (void)size;
  (void)gap;
  // merge and change index
  // sortdeque (size / 2, index * 2)
  // binaryInsert
}

void Pmerge::insertSort(int size, int gap) {
  // create sub chain
  std::vector<int> b;
  std::vector<int>::iterator it = v.begin();
  for (int i = 1; i < size; i += 2) {
    it += gap;
    b.insert(b.end(), it, it + gap);
    v.erase(it, it + gap);
  }
  if (size % 2) {
    b.insert(b.end(), it, it + gap);
    v.erase(it, it + gap);
  }

  // init
  int sortedNum = 1;
  int sortedB = 1;
  int bIndex = 1;
  int count = 2;
  int startIndex = 0;
  // put b1
  v.insert(v.begin(), b.begin(), b.begin() + gap);
  while (sortedNum < static_cast<int>(b.size()) / gap) {
    if (bIndex == sortedB) {
      sortedB = startIndex;
      while (sortedNum + bIndex - 1 < std::pow(2, count) &&
             bIndex < static_cast<int>(b.size()) / gap) {
        bIndex++;
      }
      bIndex--;
      startIndex = bIndex;
      count++;
    }
    binaryInsert(startIndex + sortedB, b[bIndex * gap], gap, bIndex, b);
    bIndex--;
    sortedNum++;
  }
}

void Pmerge::binaryInsert(int range, int num, int gap, int bIndex,
                          std::vector<int> b) {
  std::vector<int> a;
  std::vector<int>::iterator it = v.begin();
  for (int i = 0; i <= range; i++) {
    a.push_back(*it);
    it += gap;
  }
  int index = std::lower_bound(a.begin(), a.end(), num) - a.begin();
  v.insert(v.begin() + index * gap, b.begin() + bIndex * gap,
           b.begin() + (bIndex + 1) * gap);
}
