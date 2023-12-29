#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string phone_num;
		std::string dark_secret;
	public:
		bool	AddContact();
		bool	CheckContact();
		void	DisplayContact(int index);
		void	SearchContact(std::string index);
};

#endif
