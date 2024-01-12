#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
};

Dog::Dog(const Dog& obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
};

Dog& Dog::operator=(const Dog& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*(obj.getBrain()));
	return (*this);
};

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
};

void		Dog::makeSound(void) const{
	std::cout << "Bow-wow" << std::endl;
};

Brain		*Dog::getBrain(void) const {
	return (this->brain);
};