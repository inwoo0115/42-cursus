#include "RobotomyRequestForm.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", false, 72, 45), _target("default"){};

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", false, 72, 45), _target(target){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
    : AForm("RobotomyRequestForm", false, 72, 45), _target(obj.getTarget()){};

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& obj) {
  (void)obj;
  return (*this);
};

RobotomyRequestForm::~RobotomyRequestForm(){};

const std::string RobotomyRequestForm::getTarget() const {
  return (this->_target);
};

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > this->getExecGrade()) throw GradeTooLowException();
  if (!this->getIsSigned()) throw NotsignedException();
  if (std::rand() % 2 == 0)
    std::cout << this->_target << " has become a robot!" << std::endl;
  else
    std::cout << this->_target << " has not become a robot..." << std::endl;
};