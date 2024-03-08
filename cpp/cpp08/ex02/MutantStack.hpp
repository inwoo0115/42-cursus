#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
 public:
  MutantStack(){};
  MutantStack(const MutantStack& obj) { *this = obj; };
  MutantStack operator=(const MutantStack& obj) {
    *this = obj;
    return (*this);
  };
  ~MutantStack(){};
};

#endif