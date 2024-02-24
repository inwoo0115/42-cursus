#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
 private:
  const std::string _target;

 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& obj);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
  virtual ~PresidentialPardonForm();

  const std::string getTarget() const;
  void execute(Bureaucrat const& executor) const;
};

#endif