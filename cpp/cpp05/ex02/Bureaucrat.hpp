#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {
 private:
  const std::string _name;
  int _grade;

 public:
  Bureaucrat();
  Bureaucrat(const std::string name, int grade);
  Bureaucrat(const Bureaucrat& obj);
  Bureaucrat& operator=(const Bureaucrat& obj);
  virtual ~Bureaucrat();

  const std::string getName() const;
  int getGrade() const;
  void increaseGrade();
  void decreaseGrade();
  void signForm(AForm& form);
  void executeForm(AForm const& form);
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw() { return "Grade is too high"; };
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw() { return "Grade is too low"; };
  };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif