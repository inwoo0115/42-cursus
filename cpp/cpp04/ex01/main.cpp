#include "Cat.hpp"
#include "Dog.hpp"

// void	leak(void) {
// 	system("leaks ex01");
// }

int main()
{
	//atexit(leak);
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "[ Get idea : default ]" << std::endl;
	std::cout << j->getBrain()->getIdeas(0) << std::endl;
	i->getBrain()->setIdeas("Hello", 1);
	std::cout << "[ Get idea : Hello ]" << std::endl;
	std::cout << i->getBrain()->getIdeas(1) << std::endl;
	delete j;//should not create a leak
	delete i;

	const Animal*	animal[20];

	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for (int i = 0; i < 20; i++) {
		std::cout << i << " : sound" << std::endl;
		animal[i]->makeSound();
		animal[i]->getBrain()->setIdeas("Idea", 0);
		std::cout << i << " : idea" << std::endl;
		std::cout << animal[i]->getBrain()->getIdeas(0) << std::endl;
	}
	for (int i = 0; i < 20; i++) {
		delete animal[i];
	}
	
	//test deep copy
	Dog originalDog;
	Dog copiedDog = originalDog;
	std::cout << originalDog.getBrain()->getIdeas(0) << std::endl;
	std::cout << copiedDog.getBrain()->getIdeas(0) << std::endl;
	originalDog.getBrain()->setIdeas("Hello", 0);
	std::cout << originalDog.getBrain()->getIdeas(0) << std::endl;
	std::cout << copiedDog.getBrain()->getIdeas(0) << std::endl;
	return 0;
}