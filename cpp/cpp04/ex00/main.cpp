#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// void	leak(void) {
// 	system("leaks ex00");
// }

int main()
{
	//atexit(leak);
	//testcases in subject
	std::cout << "[ Animal ]" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //print cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;
	//wrong animal
	std::cout << "[ Wrong animal ]" << std::endl;
	const WrongAnimal *a = new WrongCat();
	std::cout << a->getType() << " " << std::endl;
	a->makeSound(); //print wrong sound
	delete a;
	return 0;
}