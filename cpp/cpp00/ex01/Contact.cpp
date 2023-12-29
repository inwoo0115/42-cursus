#include "Contact.hpp"

bool	Contact::AddContact()
{
	std::cout << "First name (In English)?" << std::endl;
	if (!getline(std::cin, this->first_name)) {return false;}
	std::cout << "Last name? (In English)" << std::endl;
	if (!getline(std::cin, this->last_name)) {return false;}
	std::cout << "Nick name? (In English)" << std::endl;
	if (!getline(std::cin, this->nick_name)) {return false;}
	std::cout << "Phone number? (Only number without space)" << std::endl;
	if (!getline(std::cin, this->phone_num)) {return false;}
	std::cout << "Darkest secret? (In English)" << std::endl;
	if (!getline(std::cin, this->dark_secret)) {return false;}
	return (true);
}

void	display_str(std::string str) 
{
	if (std::strlen(str.c_str()) < 10)
  		std::cout << std::setw(9) << str << ".|";
	else {
		for (std::string::size_type i = 0; i < str.size() && i < 9; ++i)
    	    std::cout << str[i];
		std::cout << ".|";
	}
}

void	Contact::DisplayContact(int index) 
{
    std::cout << std::setw(9) << index << ".|";
	display_str(this->first_name);
	display_str(this->last_name);
	display_str(this->nick_name);
	std::cout << std::endl;
}

bool check_digit(const std::string& str) {
	if (std::strlen(str.c_str()) == 0) {return (false);}
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

bool check_alpha(const std::string& str) {
	if (std::strlen(str.c_str()) == 0) {return (false);}
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isalpha(*it))
        	return false;
    }
    return true;
}

bool	Contact::CheckContact()
{
	if (!check_alpha(this->first_name)) {return (0);}
	if (!check_alpha(this->last_name)) {return (0);}
	if (!check_alpha(this->nick_name)) {return (0);}
	if (!check_alpha(this->dark_secret)) {return (0);}
	if (!check_digit(this->phone_num)) {return (0);}
	return (1);	
}

void	Contact::SearchContact(std::string index)
{
	std::cout << "Index : " << index << std::endl;
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: "<< this->last_name << std::endl;
	std::cout << "Nick name: "<< this->nick_name << std::endl;
	std::cout << "Phone number: "<< this->phone_num << std::endl;
	std::cout << "Darkest secret: "<< this->dark_secret << std::endl;
}