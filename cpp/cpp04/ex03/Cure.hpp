#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		Cure& operator=(const Cure& obj);
	public:
		Cure();
		Cure(const Cure& obj);
		~Cure();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif