#ifndef SHRUBBERYCREATION_HPP
#define SHRUBBERYCREATION_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 private:
  const std::string _target;

 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm& obj);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
  virtual ~ShrubberyCreationForm();

  const std::string getTarget() const;
  void execute(Bureaucrat const& executor) const;
};

#endif