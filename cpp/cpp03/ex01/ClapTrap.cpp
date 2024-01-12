#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  hp(10), ep(10), damage(0) {
	this->name = "default";
	std::cout << "ClapTrap default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& obj) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
};

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->name = obj.name;
	this->hp = obj.hp;
	this->ep = obj.ep;
	this->damage = obj.damage;
	return (*this);
};

ClapTrap::~ClapTrap() {
	std::cout << this->name << " ClapTrap destructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : hp(10), ep(10), damage(0) {
	this->name = name;
	std::cout << this->name << " ClapTrap constructor called" << std::endl;
};

void	ClapTrap::attack(const std::string& target) {
	if (!this->hp || !this->ep)
		std::cout << this->name << " cannot move...." << std::endl;
	else {
		std::cout << "ClapTrap [" << this->name << "] attacks [" << target << "], causing [" <<\
		this->damage << "] points of damage!" << std::endl;
		this->ep--;
	}
};

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->hp || !this->ep) {
		std::cout << this->name << " cannot move...." << std::endl;
	}
	else {
		std::cout << this->name << " gets " << amount << " damage!" << std::endl;
		if (this->hp < amount)
			this->hp = 0;
		else
			this->hp -= amount;
		this->ep--;
	}
};

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->hp || !this->ep) {
		std::cout << this->name << " cannot move...." << std::endl;
	}
	else {
		std::cout << this->name << " restores " << amount << " hp!" << std::endl;
		this->hp += amount;
		this->ep--;
	}
};
