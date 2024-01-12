#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->_amateria[i] = NULL;
	}
};

MateriaSource::MateriaSource(const MateriaSource& obj) {
	*this = obj;
};

MateriaSource& MateriaSource::operator=(const MateriaSource& obj) {
	if (this == &obj)
		return (*this);
	for (int i = 0; i < 4; i++) {
		if (this->_amateria[i] != NULL)
			delete this->_amateria[i];
		this->_amateria[i] = obj._amateria[i]->clone();
	}
	return (*this);
};

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->_amateria[i] != NULL)
			delete this->_amateria[i];
	}
};

void		MateriaSource::learnMateria(AMateria* m) {
	if (m == NULL) {
		std::cout << "Nothing can learn" << std::endl;
		return ;
	}
	for (int i = 0; i < 4 ; i++) {
		if (this->_amateria[i] == NULL) {
			this->_amateria[i] = m;//->clone();
			return ;
		}
	}
	std::cout << "Source is full" << std::endl;
	if (m != NULL)
		delete m;
};

AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4 ; i++) {
		if (this->_amateria[i] != NULL && this->_amateria[i]->getType() == type) {
			return (this->_amateria[i]->clone());
		}
	}
	std::cout << "Unknown type" << std::endl;
	return (0);
};