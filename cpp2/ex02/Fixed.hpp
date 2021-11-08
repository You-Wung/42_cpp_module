#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <tgmath.h>

class Fixed
{
private:
	int					value;
	static const int	bits = 8;
public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &other);
	~Fixed();

	Fixed		&operator=(Fixed const &other);
	
	bool		operator>(const Fixed& f);
	bool		operator<(const Fixed& f);
	bool		operator>=(const Fixed& f);
	bool		operator<=(const Fixed& f);
	bool		operator==(const Fixed& f);
	bool		operator!=(const Fixed& f);

	Fixed		operator+(const Fixed& f);
	Fixed		operator-(const Fixed& f);
	Fixed		operator/(const Fixed& f);
	Fixed		operator*(const Fixed& f);

	Fixed		operator++(void);
	Fixed		operator--(void);
	Fixed		operator++(int);
	Fixed		operator--(int);

	static Fixed		min(const Fixed& left, const Fixed& right);
	static Fixed		max(const Fixed& left, const Fixed& right);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif