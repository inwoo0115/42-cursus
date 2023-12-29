#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include <iostream>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int		index;
	public:
		Phonebook(){index = 0;};
		void	Add();
		void	Search();
};

#endif