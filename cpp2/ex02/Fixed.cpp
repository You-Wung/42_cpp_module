
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(int const value)
{
	this->value = (value << Fixed::bits);
}

Fixed::Fixed(float const value)
{
	//std::cout << "1. value : " << (value * (1 << Fixed::bits)) << std::endl;
	this->value = roundf(value * (1 << Fixed::bits));
	//std::cout << "2. value : " << this->value << std::endl;
}

Fixed::Fixed(Fixed const &other)//복사 생성자
{
	*this = other;
}

Fixed::~Fixed()//소멸자
{
}

Fixed &Fixed::operator=(Fixed const &other)//=연산자 오버로딩
{
	this->value = other.value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::bits));
}

int	Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

bool		Fixed::operator>(const Fixed& f)
{
	return (value > f.getRawBits());
}

bool		Fixed::operator<(const Fixed& f)
{
	return (value < f.getRawBits());
}

bool		Fixed::operator>=(const Fixed& f)
{
	return (value >= f.getRawBits());
}

bool		Fixed::operator<=(const Fixed& f)
{
	return (value <= f.getRawBits());
}

bool		Fixed::operator==(const Fixed& f)
{
	return (value == f.getRawBits());
}

bool		Fixed::operator!=(const Fixed& f)
{
	return (value == f.getRawBits());
}

Fixed		Fixed::operator+(const Fixed& f)
{
	Fixed	tmp(this->toFloat() + f.toFloat());
	return (tmp);
}

Fixed		Fixed::operator-(const Fixed& f)
{
	Fixed	tmp(this->toFloat() - f.toFloat());
	return (tmp);
}

Fixed		Fixed::operator/(const Fixed& f)
{
	Fixed	tmp(this->toFloat() / f.toFloat());
	return (tmp);
}

Fixed		Fixed::operator*(const Fixed& f)
{
	Fixed	tmp(this->toFloat() * f.toFloat());
	return (tmp);
}

Fixed		Fixed::operator++(void)
{
	value++;
	return (*this);
}

Fixed		Fixed::operator--(void)
{
	value--;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	tmp = *this;

	value++;
	return (tmp);
}

Fixed		Fixed::operator--(int)
{
	Fixed	tmp = *this;

	value--;
	return (tmp);
}

Fixed		Fixed::max(const Fixed& left, const Fixed& right)
{
	if (left.getRawBits() > right.getRawBits())
		return (left);
	return (right);
}

Fixed		Fixed::min(const Fixed& left, const Fixed& right)
{
	if (left.getRawBits() < right.getRawBits())
		return (left);
	return (right);
}