#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
	private:
		AMateria& operator=(const AMateria& obj); //copying the type doesn’t make sense
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& obj);
		virtual ~AMateria();

		std::string const&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);

};

#endif