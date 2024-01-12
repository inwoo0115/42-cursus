#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
};

Dog::Dog(const Dog& obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
};

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
};

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
};

void		Dog::makeSound(void) const {
	std::cout << "Bow-wow" << std::endl;
};