#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("PresidentialPardonForm", false, 25, 5), _target("default"){};

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : Form("PresidentialPardonForm", false, 25, 5), _target(target){};

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& obj)
    : Form("PresidentialPardonForm", false, 25, 5), _target(obj.getTarget()){};

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& obj) {
  (void)obj;
  return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm(){};

const std::string PresidentialPardonForm::getTarget() const {
  return (this->_target);
};

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > this->getExecGrade()) throw GradeTooLowException();
  if (!this->getIsSigned()) throw NotsignedException();
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
};