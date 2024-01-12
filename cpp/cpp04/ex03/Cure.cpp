#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {};

Cure::Cure(const Cure& obj) : AMateria(obj) {};

Cure::~Cure() {};

Cure& Cure::operator=(const Cure& obj) {
	(void)obj;
	return (*this);
};

AMateria*	Cure::clone() const {
	return (new Cure());
};

void		Cure::use(ICharacter& target) { 
	std::cout << "* heals " << target.getName() << " ’s wounds *" << std::endl;
};