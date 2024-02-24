#include "Bureaucrat.hpp"

#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
  this->_grade = grade;
  if (grade < 0)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
    : _name(obj.getName()), _grade(obj.getGrade()){};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
  if (this == &obj) return (*this);
  this->_grade = obj.getGrade();
  return (*this);
};

Bureaucrat::~Bureaucrat(){};

const std::string Bureaucrat::getName() const { return (this->_name); };

int Bureaucrat::getGrade() const { return (this->_grade); };

void Bureaucrat::increaseGrade() {
  if (this->_grade == 1)
    throw GradeTooHighException();
  else
    this->_grade--;
  std::cout << "Promotion complete!" << std::endl;
};

void Bureaucrat::decreaseGrade() {
  if (this->_grade == 150)
    throw GradeTooLowException();
  else
    this->_grade++;
  std::cout << "You were demoted..." << std::endl;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj) {
  out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
  return (out);
};

// ex01
void Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
    form.setIsSigned(true);
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
};
