#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
  std::srand(time(NULL));
  int i = std::rand();
  if (i % 3 == 0)
    return (new A);
  else if (i % 3 == 1)
    return (new B);
  return (new C);
};

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "It is A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "It is B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "It is C" << std::endl;
  else
    std::cout << "Wrong base" << std::endl;
};

void identify(Base& p) {
  try {
    A& a = dynamic_cast<A&>(p);
    std::cout << "It is A" << std::endl;
    (void)a;
  } catch (std::exception& e) {
  }
  try {
    B& a = dynamic_cast<B&>(p);
    std::cout << "It is B" << std::endl;
    (void)a;
  } catch (std::exception& e) {
  }
  try {
    C& a = dynamic_cast<C&>(p);
    std::cout << "It is C" << std::endl;
    (void)a;
  } catch (std::exception& e) {
  }
};

// void	leak(void) {
// 	system("leaks ex02");
// }

int main() {
  //   atexit(leak);
  Base* base = generate();
  identify(base);
  identify(*base);
  delete base;
  return 0;
}