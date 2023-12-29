#include "PhoneBook.hpp"

int main(void)
{
	Phonebook	book;
	std::string	str;
	while (1)
	{
		std::cout << "Input command: ";
		if (std::getline(std::cin, str))
		{
			if (str == "ADD")
				book.Add();
			else if (str == "SEARCH")
				book.Search();
			else if (str == "EXIT"){
				std::cout << "Exit phonebook" << std::endl;
				break;
			}
			else
				std::cout << "Command not found" << std::endl;
		}
		else
			break;
	}
	return (0);
}