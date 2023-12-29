#include "PhoneBook.hpp"

void	Phonebook::Add()
{
	if (this->contacts[index % 8].AddContact()) {
		if (!this->contacts[index % 8].CheckContact()) {
			std::cout << "Wrong argument" << std::endl;
		}
		else
			index++;
	}
	if (std::cin.eof()) {
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();


		//clearerr(stdin);
	}
	std::cout << std::cin << std::endl;
}

void	Phonebook::Search()
{
	std::string	str;
	if (index == 0) {
		std::cout << "No contact saved" << std::endl;
		return ;
	}
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < index && i < 8; i++)
		this->contacts[i].DisplayContact(i + 1);
	std::cout << "Input index of contact" << std::endl;
	std::getline(std::cin, str);
	if (std::cin.eof()) {
		clearerr(stdin);
		std::cin.clear();
		return ;
	}
	if (str[0] > '0' && str[0] < '9' && str.length() == 1 && str[0] < '0' + index + 1)
		this->contacts[str[0] - '0' - 1].SearchContact(str);
	else
		std::cout << "Wrong index" << std::endl;
}
