#include "AForm.hpp"

AForm::AForm()
    : _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150){};

AForm::AForm(const std::string name, bool is_signed, const int sign_grade,
             const int exec_grade)
    : _name(name),
      _is_signed(is_signed),
      _sign_grade(sign_grade),
      _exec_grade(exec_grade){};

AForm::AForm(const AForm& obj)
    : _name(obj.getName()),
      _is_signed(obj.getIsSigned()),
      _sign_grade(obj.getSignGrade()),
      _exec_grade(obj.getExecGrade()){};

AForm& AForm::operator=(const AForm& obj) {
  if (this == &obj) return (*this);
  this->_is_signed = obj.getIsSigned();
  return (*this);
};

AForm::~AForm(){};

const std::string AForm::getName() const { return (this->_name); };

int AForm::getSignGrade() const { return (this->_sign_grade); };

int AForm::getExecGrade() const { return (this->_exec_grade); };

bool AForm::getIsSigned() const { return (this->_is_signed); };

void AForm::setIsSigned(bool sign) { this->_is_signed = sign; };

void AForm::beSigned(const Bureaucrat& obj) {
  if (obj.getGrade() > this->getSignGrade()) throw GradeTooLowException();
};

std::ostream& operator<<(std::ostream& out, const AForm& obj) {
  out << "Form : " << obj.getName() << "\nSign grade : " << obj.getSignGrade()
      << "\nExecute grade : " << obj.getExecGrade()
      << "\nSigned/Non signed : " << std::boolalpha << obj.getIsSigned()
      << std::endl;
  return (out);
};