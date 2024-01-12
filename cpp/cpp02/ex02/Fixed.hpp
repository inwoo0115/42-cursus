#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixed_num_value;
		static const int	fractionBits = 8;
	public: //orthodox canonical form
		Fixed();								//기본 생성자
		Fixed(const Fixed& obj);				//복사 생성자
		Fixed& operator=(const Fixed& obj);	//복사 연산자 오버로딩
		~Fixed();								//소멸자

		Fixed(const int i);
		Fixed(const float f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
		//비교 연산자
		bool	operator>(const Fixed& fixed) const;
		bool	operator<(const Fixed& fixed) const;
		bool	operator>=(const Fixed& fixed) const;
		bool	operator<=(const Fixed& fixed) const;
		bool	operator==(const Fixed& fixed) const;
		bool	operator!=(const Fixed& fixed) const;
		//산술 연산자
		Fixed	operator+(const Fixed& fixed) const;
		Fixed	operator-(const Fixed& fixed) const;
		Fixed	operator*(const Fixed& fixed) const;
		Fixed	operator/(const Fixed& fixed) const;
		//전위 후위 연산자 (소수점 최솟값을 +-1)
		Fixed&	operator++(void);
		const Fixed	operator++(int);
		Fixed&	operator--(void);
		const Fixed	operator--(int);
		//min max 함수
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
