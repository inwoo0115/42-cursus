#ifndef INTERN_HPP
#define INTERN_HPP

#include <stdexcept>

#include "Form.hpp"

class Intern {
 private:
  Intern operator=(const Intern& obj);
  Intern(const Intern& obj);

 public:
  Intern();
  ~Intern();

  Form* makeForm(std::string type, std::string name);

  class CreateException : public std::exception {
   public:
    const char* what() const throw() { return "Cannot create a form"; };
  };
};

#endif