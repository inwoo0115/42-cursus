#include "Bureaucrat.hpp"
#include "Intern.hpp"
// void leak(void) { system("leaks ex03"); }

int main() {
  //   atexit(leak);
  std::cout << "[Subject testcase]" << std::endl;
  Intern someRandomIntern;
  Form* rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  delete rrf;
  std::cout << std::endl;
  Form* f1;
  Form* f2;
  Form* f3;
  //   Form* f4;
  try {
    std::cout << "[Intern creates forms]" << std::endl;
    f1 = someRandomIntern.makeForm("shrubbery creation", "f1");
    f2 = someRandomIntern.makeForm("robotomy request", "f2");
    f3 = someRandomIntern.makeForm("presidential pardon", "f3");
    // f4 = someRandomIntern.makeForm("wrong form", "f4");  // wrong form
    // (void)f4;
    // main.cpp in ex02
    Bureaucrat a = Bureaucrat("Lee", 2);
    Bureaucrat b = Bureaucrat("Kim", 145);
    std::cout << "[Information of Forms]" << std::endl;
    std::cout << *f1;
    std::cout << *f2;
    std::cout << *f3;
    std::cout << std::endl;
    std::cout << "[Signing forms]" << std::endl;
    a.signForm(*f1);
    // a.signForm(*f2);
    a.signForm(*f3);
    b.signForm(*f1);
    b.signForm(*f2);
    b.signForm(*f3);
    std::cout << std::endl;
    std::cout << "[Executing forms]" << std::endl;
    a.executeForm(*f1);
    a.executeForm(*f2);  // cannot execute because not signed
    a.executeForm(*f3);
    b.executeForm(*f1);
    b.executeForm(*f2);  // cannot execute because not signed
    b.executeForm(*f3);
    // std::cout << std::endl;
    // std::cout << "[Random Robot]" << std::endl;
    // for (int i = 0; i < 20; i++) {
    // 	a.executeForm(*f3);
    // }
  } catch (std::exception& e) {  // get Create Exception
    std::cout << "Got error : " << e.what() << std::endl;
  }
  delete f1;
  delete f2;
  delete f3;
  return 0;
}