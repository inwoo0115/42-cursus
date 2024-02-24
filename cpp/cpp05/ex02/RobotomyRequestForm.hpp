#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 private:
  const std::string _target;

 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& obj);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
  virtual ~RobotomyRequestForm();

  const std::string getTarget() const;
  void execute(Bureaucrat const& executor) const;
};

#endif