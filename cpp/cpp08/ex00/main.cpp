#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::list<int> l;
  std::vector<int> v;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  try {
    std::list<int>::iterator it1 = easyfind(l, 3);
    std::cout << *it1 << std::endl;
    // std::list<int>::iterator it = easyfind(l, 4);
    // std::cout << *it << std::endl;
    std::vector<int>::iterator it2 = easyfind(v, 2);
    std::cout << *it2 << std::endl;
    // std::list<int>::iterator it = easyfind(v, 0);
    // std::cout << *it << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error : " << e.what() << std::endl;
  }
  return 0;
}
