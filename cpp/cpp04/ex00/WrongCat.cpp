#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat& obj) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
};

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
};

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
};

void		WrongCat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
};