#include "ClapTrap.hpp"

int main()
{
	ClapTrap	a;
	ClapTrap	b("Bob");
	ClapTrap	c;
	c = b;

	std::cout << "[ Default attack John ] " << std::endl;
	a.attack("John");
	std::cout << "[ Default repaired ] " << std::endl;
	a.beRepaired(10);
	std::cout << "[ Default damaged ] " << std::endl;
	a.takeDamage(10);
	std::cout << "[ Bob damaged ] " << std::endl;
	b.takeDamage(25);
	std::cout << "[ Bob damaged ] " << std::endl;
	b.takeDamage(25);
	for (int i = 0; i<12; i++) {
		std::cout << i << " : ";
		c.beRepaired(1);
	}
	return (0);
}