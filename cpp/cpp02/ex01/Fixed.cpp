#include "Fixed.hpp"

Fixed::Fixed() {
	fixed_num_value = 0;
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->fixed_num_value = i << this->fractionBits;
};

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	this->fixed_num_value = roundf(f * (1 << this->fractionBits));
};

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
};

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixed_num_value = obj.getRawBits();
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
};

int		Fixed::getRawBits(void) const {
	return this->fixed_num_value;
};

void	Fixed::setRawBits(int const raw) {
	this->fixed_num_value = raw;
};

float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->fixed_num_value) / (1 << this->fractionBits));
};

int		Fixed::toInt(void) const {
	return (this->fixed_num_value >> this->fractionBits);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	return (out << obj.toFloat());
};
