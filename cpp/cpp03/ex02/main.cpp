#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap	a("Bob");
	ScavTrap	b("John");
	FragTrap	c("Lee");

	std::cout << "[ Attacks ]" << std::endl;
	a.attack("1");
	b.attack("2");
	c.attack("3");
	std::cout << "[ highfive! ]" << std::endl;
	c.highFiveGuys();
	std::cout << "[ Using ep ]" << std::endl;
	for (int i = 0 ; i < 102 ; i++) {
		std::cout << i << " : ";
		c.highFiveGuys();
	}
	std::cout << std::endl;
	return (0);
}