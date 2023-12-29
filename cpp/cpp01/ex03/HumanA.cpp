#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), armed(weapon) {}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->armed.getType() << std::endl;
}
