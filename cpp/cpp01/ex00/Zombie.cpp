#include "Zombie.hpp"

Zombie::Zombie()
{
	this->name = "Random zombie";
	std::cout << this->name << " has been created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
