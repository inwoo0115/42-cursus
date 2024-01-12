#include "Cat.hpp"

//create brain
Cat::Cat() {
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
};

Cat::Cat(const Cat& obj) : brain(NULL) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
};

Cat& Cat::operator=(const Cat& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "Cat copy assignment operator called" << std::endl;
	this->type = obj.type;
	if (this->brain)
		delete this->brain;
	this->brain = new Brain(*(obj.getBrain()));
	return (*this);
};

//delete brain
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
};

void		Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
};

Brain		*Cat::getBrain(void) const {
	return (this->brain);
};