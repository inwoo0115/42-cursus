#include "Bureaucrat.hpp"

// void	leak(void) {
// 	system("leaks ex00");
// }

int main() {
  //   atexit(leak);
  Bureaucrat a = Bureaucrat("Lee", 2);
  Bureaucrat b = Bureaucrat("Kim", 148);
  std::cout << "[Overloading insertion operator]" << std::endl;
  std::cout << a << b;
  std::cout << "\n[Increasing and decreasing Bureaucrat's grade]" << std::endl;
  try {
    a.increaseGrade();
    std::cout << "Grade of Lee : " << a.getGrade() << std::endl;
    a.increaseGrade();
    std::cout << "Grade of Lee : " << a.getGrade() << std::endl;
    a.increaseGrade();
    std::cout << "Grade of Lee : " << a.getGrade() << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    b.decreaseGrade();
    std::cout << "Grade of Kim : " << b.getGrade() << std::endl;
    b.decreaseGrade();
    std::cout << "Grade of Kim : " << b.getGrade() << std::endl;
    b.decreaseGrade();
    std::cout << "Grade of Kim : " << b.getGrade() << std::endl;
    b.decreaseGrade();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n[Bureaucrat constructor with wrong grade]" << std::endl;
  try {
    Bureaucrat c = Bureaucrat("Bob", 200);
    //Bureaucrat d = Bureaucrat("John", -5);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}