#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
};

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
};

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
};

std::string	WrongAnimal::getType(void) const {
	return (this->type);
};

void		WrongAnimal::makeSound(void) const {
	std::cout << "(Can't hear anything)" << std::endl;
};