#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
};

Animal::Animal(const Animal& obj) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
};

Animal& Animal::operator=(const Animal& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
};

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
};

std::string	Animal::getType(void) const {
	return (this->type);
};

void		Animal::makeSound(void) const {
	std::cout << "(Can't hear anything)" << std::endl;
};
