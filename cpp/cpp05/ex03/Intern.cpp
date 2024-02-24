#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){};

Intern::Intern(const Intern& obj) { (void)obj; };

Intern Intern::operator=(const Intern& obj) {
  (void)obj;
  return (*this);
};

Intern::~Intern(){};

Form* Intern::makeForm(std::string type, std::string name) {
  static std::string form_list[] = {"shrubbery creation", "robotomy request",
                                    "presidential pardon"};
  for (int i = 0; i < 3; i++) {
    if (type == form_list[i]) {
      std::cout << "Intern creates " << type << std::endl;
      switch (i) {
        case 0:
          return (new ShrubberyCreationForm(name));
        case 1:
          return (new RobotomyRequestForm(name));
        case 2:
          return (new PresidentialPardonForm(name));
      }
    }
  }
  throw CreateException();
  return 0;
};