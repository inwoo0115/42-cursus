#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0;i < 100;i++) {
		this->ideas[i] = "default";
	}
};

Brain::Brain(const Brain& obj) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
};

Brain& Brain::operator=(const Brain& obj) {
	if (this == &obj)
		return (*this);
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &obj) {
		for (int i = 0;i < 100;i++) {
			this->ideas[i] = obj.ideas[i];
		}
	}
	return (*this);
};

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
};

std::string	Brain::getIdeas(int i) const {
	return (this->ideas[i]);
};

void		Brain::setIdeas(std::string idea, int i) {
	this->ideas[i] = idea;
};