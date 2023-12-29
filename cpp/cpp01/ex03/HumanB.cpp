#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), armed(NULL) {}

void	HumanB::attack()
{
	if (this->armed == NULL)
		std::cout << "Nothing here" << std::endl;
	std::cout << this->name << " attacks with their " << this->armed->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->armed = &weapon;
}
