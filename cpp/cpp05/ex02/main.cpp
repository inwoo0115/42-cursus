#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
// void	leak(void) {
// 	system("leaks ex02");
// }

int main() {
  // atexit(leak);
  Bureaucrat a = Bureaucrat("Lee", 2);
  Bureaucrat b = Bureaucrat("Kim", 145);
  AForm *f1 = new ShrubberyCreationForm("aaa");
  AForm *f2 = new PresidentialPardonForm("bbb");
  AForm *f3 = new RobotomyRequestForm("ccc");

  std::cout << "[Information of Forms]" << std::endl;
  std::cout << *f1;
  std::cout << *f2;
  std::cout << *f3;
  std::cout << std::endl;
  std::cout << "[Signing forms]" << std::endl;
  a.signForm(*f1);
  //a.signForm(*f2);
  a.signForm(*f3);
  b.signForm(*f1);
  b.signForm(*f2);
  b.signForm(*f3);
  std::cout << std::endl;
  std::cout << "[Executing forms]" << std::endl;
  a.executeForm(*f1);
  a.executeForm(*f2); //cannot execute because not signed
  a.executeForm(*f3);
  b.executeForm(*f1);
  b.executeForm(*f2); //cannot execute because not signed
  b.executeForm(*f3);
  // std::cout << std::endl;
  // std::cout << "[Random Robot]" << std::endl;
  // for (int i = 0; i < 20; i++) {
  // 	a.executeForm(*f3);
  // }

  delete f1;
  delete f2;
  delete f3;
  return 0;
}