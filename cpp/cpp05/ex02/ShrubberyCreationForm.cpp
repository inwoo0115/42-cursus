#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", false, 145, 137), _target("default"){};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("ShrubberyCreationForm", false, 145, 137), _target(target){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
    : AForm("ShrubberyCreationForm", false, 145, 137),
      _target(obj.getTarget()){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& obj) {
  (void)obj;
  return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm(){};

const std::string ShrubberyCreationForm::getTarget() const {
  return (this->_target);
};

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (executor.getGrade() > this->getExecGrade()) throw GradeTooLowException();
  if (!this->getIsSigned()) throw NotsignedException();
  std::string outfile = this->_target;
  outfile.append("_shrubbery");
  std::ofstream out(outfile);
  out << "   *    *  ()   *   *\n"
      << "*        * /\\         *\n"
      << "      *   /i\\\\    *  *\n"
      << "    *     o/\\\\  *      *\n"
      << " *       ///\\i\\    *\n"
      << "     *   /*/o\\\\  *    *\n"
      << "   *    /i//\\*\\      *\n"
      << "        /o/*\\\\i\\   *\n"
      << "  *    //i//o\\\\\\\\     *\n"
      << "    * /*////\\\\\\\\i\\*\n"
      << " *    //o//i\\\\*\\\\\\   *\n"
      << "   * /i///*/\\\\\\\\\\o\\   *\n"
      << "  *    *   ||     *    \n";
};