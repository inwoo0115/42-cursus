#include <string>

#include "iter.hpp"

int main() {
  std::string str[] = {"a", "b", "c"};
  int num[] = {1, 2, 3, 4, 5};
  //   const char *strs[2] = {"hello", "nice too meet you"};
  //   iter(strs, 2, strlen);
  std::cout << "----- Print str -----" << std::endl;
  iter(str, 3, print<std::string>);
  std::cout << "---------------------" << std::endl;
  std::cout << "----- Print num -----" << std::endl;
  iter(num, 5, print<int>);
  std::cout << "----- Add one to num -----" << std::endl;
  iter(num, 5, addOne<int>);
  std::cout << "----- Print num -----" << std::endl;
  iter(num, 5, print<int>);
  std::cout << "---------------------" << std::endl;
  return 0;
}