#include "Serializer.hpp"

struct Data {
  std::string name;
  int i;
};

// void	leak(void) {
// 	system("leaks ex01");
// }

int main() {
  //   atexit(leak);
  Data* a = new Data;
  a->name = "hello";
  a->i = 123;
  uintptr_t b = Serializer::serialize(a);
  Data* c = Serializer::deserialize(b);
  std::cout << "Data of [a]" << std::endl;
  std::cout << a->name << std::endl;
  std::cout << a->i << std::endl;
  std::cout << "Data of [c]" << std::endl;
  std::cout << c->name << std::endl;
  std::cout << c->i << std::endl;

  delete a;
  return 0;
}