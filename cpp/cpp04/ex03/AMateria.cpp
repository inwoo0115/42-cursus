#include "AMateria.hpp"

AMateria::AMateria() : _type(NULL) {};

AMateria::AMateria(std::string const& type) : _type(type) {};

AMateria::AMateria(const AMateria& obj) : _type(obj.getType()) {};

//have to declare operator?
AMateria& AMateria::operator=(const AMateria& obj) { 
	(void)obj;
	return (*this);
};

AMateria::~AMateria() {};

std::string const& AMateria::getType() const {
	return (this->_type);
};

void		AMateria::use(ICharacter& target) { 
	(void)target;
	std::cout << "Nothing happen..." << std::endl; 
};