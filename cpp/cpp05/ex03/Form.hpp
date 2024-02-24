#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#include "Bureaucrat.hpp"

class Form {
 private:
  const std::string _name;
  bool _is_signed;
  const int _sign_grade;
  const int _exec_grade;

 public:
  Form();
  Form(const std::string name, bool is_signed, const int sign_grade,
        const int exec_grade);
  Form(const Form& obj);
  Form& operator=(const Form& obj);
  virtual ~Form();

  const std::string getName() const;
  int getSignGrade() const;
  int getExecGrade() const;
  bool getIsSigned() const;
  void setIsSigned(bool sign);
  void beSigned(const Bureaucrat& obj);
  virtual void execute(
      Bureaucrat const& executor) const = 0;  // execute function

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw() { return "Grade is too high"; };
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw() { return "Grade is too low"; };
  };
  class NotsignedException : public std::exception {
   public:
    const char* what() const throw() { return "Form is not signed"; };
  };
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif