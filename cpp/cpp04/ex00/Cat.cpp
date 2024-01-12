#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
};

Cat::Cat(const Cat& obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
};

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
};

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
};

void		Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
};