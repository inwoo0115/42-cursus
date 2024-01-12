#include "ScavTrap.hpp"

int main()
{
	ClapTrap	a("Bob");
	ScavTrap	b("John");
	ClapTrap	*c = new ScavTrap();

	std::cout << "[ Attack ]" << std::endl;
	a.attack("A");
	b.attack("B");
	c->attack("A");
	std::cout << "[ Guardgate mode ]"<< std::endl;
	b.guardGate();
	//c.guardGate(); error
	std::cout << "[ Delete ]" << std::endl;
	delete c;
	return (0);
}