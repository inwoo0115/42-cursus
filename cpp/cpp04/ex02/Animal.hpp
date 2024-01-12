#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

#include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual ~Animal();

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
		virtual	Brain	*getBrain(void) const = 0;
};

#endif