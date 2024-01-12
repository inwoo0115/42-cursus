#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif