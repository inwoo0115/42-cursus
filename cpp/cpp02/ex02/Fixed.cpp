#include "Fixed.hpp"

Fixed::Fixed() {
	fixed_num_value = 0;
};

Fixed::Fixed(const int i) {
	this->fixed_num_value = i << this->fractionBits;
};

Fixed::Fixed(const float f) {
	this->fixed_num_value = roundf(f * (1 << this->fractionBits));
};


Fixed::Fixed(const Fixed& obj) {
	*this = obj;
};
		
Fixed& Fixed::operator=(const Fixed& obj) {
	if (this != &obj)
		this->fixed_num_value = obj.getRawBits();
	return *this;
};

Fixed::~Fixed() {};

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

//비교 연산자
bool	Fixed::operator>(const Fixed& fixed) const {
	return (this->fixed_num_value > fixed.getRawBits());
};

bool	Fixed::operator<(const Fixed& fixed) const {
	return (this->fixed_num_value < fixed.getRawBits());
};

bool	Fixed::operator>=(const Fixed& fixed) const {
	return (this->fixed_num_value >= fixed.getRawBits());
};

bool	Fixed::operator<=(const Fixed& fixed) const {
	return (this->fixed_num_value <= fixed.getRawBits());
};

bool	Fixed::operator==(const Fixed& fixed) const {
	return (this->fixed_num_value == fixed.getRawBits());
};

bool	Fixed::operator!=(const Fixed& fixed) const {
	return (this->fixed_num_value != fixed.getRawBits());
};

//산술 연산자
Fixed	Fixed::operator+(const Fixed& fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
};

Fixed	Fixed::operator-(const Fixed& fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
};

Fixed	Fixed::operator*(const Fixed& fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
};

Fixed	Fixed::operator/(const Fixed& fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
};

//전위 후위 연산자
Fixed&	Fixed::operator++(void) {
	this->fixed_num_value++;
	return (*this);
};

const Fixed	Fixed::operator++(int) {
	const Fixed	tmp(*this);
	this->fixed_num_value++;
	return (tmp);
};

Fixed&	Fixed::operator--(void) {
	this->fixed_num_value--;
	return (*this);
};

const Fixed	Fixed::operator--(int) {
	const Fixed	tmp(*this);
	this->fixed_num_value--;
	return (tmp);
};

//min max 함수
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
};

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
};

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
};

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
};
