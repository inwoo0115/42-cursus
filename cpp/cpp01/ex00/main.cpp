#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie1;
	Zombie* zombie2 = newZombie("aaa");

	delete zombie2;
	randomChump("bbb");
	return (0);
}
