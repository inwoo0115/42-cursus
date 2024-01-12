#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; i++) {
		this->slot[i] = NULL;
	}
	for (int i = 0; i < 100; i++) {
		this->floor[i] = NULL;
	}
	this->name = "default";
};

Character::Character(const std::string name) {
	for (int i = 0; i < 4; i++) {
		this->slot[i] = NULL;
	}
	for (int i = 0; i < 100; i++) {
		this->floor[i] = NULL;
	}
	this->name = name;
};

Character::Character(const Character& obj) {
	*this = obj;
};

Character& Character::operator=(const Character & obj) {
	if (this == &obj)
		return (*this);
	this->name = obj.getName();
	for (int i = 0; i < 4; i++) {
		if (this->slot[i] != NULL)
			delete this->slot[i];
		this->slot[i] = obj.slot[i]->clone();
	}
	for (int i = 0; i < 100; i++) {
		if (this->floor[i] != NULL)
			delete this->floor[i];
		this->floor[i] = obj.floor[i]->clone();
	}
	return (*this);
};

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (this->slot[i] != NULL)
			delete this->slot[i];
	}
	for (int i = 0; i < 100; i++) {
		if (this->floor[i] != NULL)
			delete this->floor[i];
	}
};

std::string const&	Character::getName() const {
	return (this->name);
};

void				Character::equip(AMateria *m) {
	if (m == NULL || (m->getType() != "cure" && m->getType() != "ice")) {
		std::cout << "Cannot equip this materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (m == this->slot[i]){
			std::cout << "Already equip" << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (this->slot[i] == NULL || this->slot[i]->getType() == "NULL") {
			this->slot[i] = m;
			//std::cout << "Equip complete" << std::endl;
			return ;
		}
	}
	std::cout << "Slot is full" << std::endl;
	if (m != NULL)
		delete m;
};

void				Character::unequip(int idx) {
	if (this->slot[idx]->getType() == "NULL") {
		std::cout << "Nothing happen..." << std::endl;
		return ;
	}
	for (int i = 0; i < 100; i++) {
		if (this->floor[i] == NULL) {
			this->floor[i] = this->slot[idx];
			this->slot[idx] = NULL;
		}
	}
};

void				Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 4) {
		std::cout << "Wrong index" << std::endl;
		return ;
	}
	if (this->slot[idx] == NULL || this->slot[idx]->getType() == "NULL") {
		std::cout << "Nothing happen..." << std::endl;
		return ;
	}
	this->slot[idx]->use(target);
	this->unequip(idx);
};