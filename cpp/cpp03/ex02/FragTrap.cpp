#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "default";
	std::cout << "FragTrap default constructor called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->damage = 30;
};

FragTrap::FragTrap(std::string name) {
	this->name = name;
	std::cout << "FragTrap "<< name << " constructor called" << std::endl;
	this->hp = 100;
	this->ep = 100;
	this->damage = 30;
};

FragTrap::FragTrap(const FragTrap& obj) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = obj;
};

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "Fragtrap copy assignment operator called" << std::endl;
	this->name = obj.name;
	this->hp = obj.hp;
	this->ep = obj.ep;
	this->damage = obj.damage;
	return (*this);
};

FragTrap::~FragTrap() {
	std::cout << this->name << " FragTrap destructor called" << std::endl;
};

void	FragTrap::attack(const std::string& target) {
	if (!this->ep || !this->hp)
		std::cout << this->name << " cannot move...." << std::endl;
	else {
		std::cout << "Fragtrap [" << this->name << "] attacks [" << target << "], causing [" <<\
		this->damage << "] points of damage!" << std::endl;
		this->ep--;
	}
};

void	FragTrap::highFiveGuys(void) {
	if (!this->hp || !this->ep) {
		std::cout << this->name << " cannot move...." << std::endl;
	}
	else {
		std::cout << this->name << " gives you great high five!" << std::endl;
		this->ep--;
	}
};