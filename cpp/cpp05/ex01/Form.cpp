#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
    : _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150){};

Form::Form(const std::string name, bool is_signed, const int sign_grade,
           const int exec_grade)
    : _name(name),
      _is_signed(is_signed),
      _sign_grade(sign_grade),
      _exec_grade(exec_grade){};

Form::Form(const Form& obj)
    : _name(obj.getName()),
      _is_signed(obj.getIsSigned()),
      _sign_grade(obj.getSignGrade()),
      _exec_grade(obj.getExecGrade()){};

Form& Form::operator=(const Form& obj) {
  if (this == &obj) return (*this);
  this->_is_signed = obj.getIsSigned();
  return (*this);
};

Form::~Form(){};

const std::string Form::getName() const { return (this->_name); };

int Form::getSignGrade() const { return (this->_sign_grade); };

int Form::getExecGrade() const { return (this->_exec_grade); };

bool Form::getIsSigned() const { return (this->_is_signed); };

void Form::setIsSigned(bool sign) { this->_is_signed = sign; };

void Form::beSigned(const Bureaucrat& obj) {
  if (obj.getGrade() > this->getSignGrade()) throw GradeTooLowException();
};

std::ostream& operator<<(std::ostream& out, const Form& obj) {
  out << "Form : " << obj.getName() << "\nSign grade : " << obj.getSignGrade()
      << "\nExecute grade : " << obj.getExecGrade()
      << "\nSigned/Non signed : " << std::boolalpha << obj.getIsSigned()
      << std::endl;
  return (out);
};