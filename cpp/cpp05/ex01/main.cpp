#include "Bureaucrat.hpp"
#include "Form.hpp"
// void	leak(void) {
// 	system("leaks ex01");
// }

int main() {
  // atexit(leak);
  Bureaucrat a = Bureaucrat("Lee", 2);
  Bureaucrat b = Bureaucrat("Kim", 148);
  Form f1 = Form("form1", false, 5, 10);
  Form f2 = Form("form2", true, 149, 149);
  Form f3 = Form();
  std::cout << "[Information of Forms]" << std::endl;
  std::cout << f1;
  std::cout << f2;
  std::cout << f3;
  std::cout << std::endl;
  std::cout << "[Signed / Non signed]" << std::endl;
  std::cout << "F1 Is signed? : " << f1.getIsSigned() << std::endl;
  std::cout << "F2 Is signed? : " << f2.getIsSigned() << std::endl;
  std::cout << "F3 Is signed? : " << f3.getIsSigned() << std::endl;
  b.signForm(f1); //cannot sign f1
  a.signForm(f1); //can sign f1
  a.signForm(f2); //can sign but already signed
  b.signForm(f3); //can sign f3
  std::cout << std::endl;
  std::cout << "F1 Is signed? : " << f1.getIsSigned() << std::endl;
  std::cout << "F2 Is signed? : " << f2.getIsSigned() << std::endl;
  std::cout << "F3 Is signed? : " << f3.getIsSigned() << std::endl;
  return 0;
}