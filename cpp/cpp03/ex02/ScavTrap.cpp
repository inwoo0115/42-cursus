#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->name = "default";
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->damage = 20;
};

ScavTrap::ScavTrap(std::string name) {
	this->name = name;
	std::cout << "ScavTrap "<< name << " constructor called" << std::endl;
	this->hp = 100;
	this->ep = 50;
	this->damage = 20;
};

ScavTrap::ScavTrap(const ScavTrap& obj) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = obj;
};

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "Scavtrap copy assignment operator called" << std::endl;
	this->name = obj.name;
	this->hp = obj.hp;
	this->ep = obj.ep;
	this->damage = obj.damage;
	return (*this);
};

ScavTrap::~ScavTrap() {
	std::cout << this->name << " ScavTrap destructor called" << std::endl;
};

void	ScavTrap::attack(const std::string& target) {
	if (!this->ep || !this->hp)
		std::cout << this->name << " cannot move...." << std::endl;
	else {
		std::cout << "Scavtrap [" << this->name << "] attacks [" << target << "], causing [" <<\
		this->damage << "] points of damage!" << std::endl;
		this->ep--;
	}
};

void	ScavTrap::guardGate(void) {
	if (!this->hp || !this->ep) {
		std::cout << this->name << " cannot move...." << std::endl;
	}
	else {
		std::cout << this->name << " starts guardGate mode..." << std::endl;
		this->ep--;
	}
};