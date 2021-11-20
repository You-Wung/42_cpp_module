#include "Animal.hpp"

void							Animal::makeSound(void) const
{
	std::cout << "CAN NOT MAKE SOUND\n";
}

Animal&							Animal::operator=(const Animal& a)
{
	if (this != &a)
		this->_type = a._type;
	return (*this);
}

std::string Animal::getType(void) const
{
	return (_type);
}

Animal::Animal(void)
	:	_type(A_DEFAULT)
{
	std::cout << "[Animal] Default Constructor\n";
}

Animal::Animal(const Animal& a)
	:	_type(a._type)
{
	std::cout << "[Animal] Copy Constructor\n";
}

Animal::~Animal(void)
{
	std::cout << "[Animal] Destructor\n";
}

