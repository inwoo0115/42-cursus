#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		virtual ~Cat();
		void	makeSound(void) const;
};

#endif