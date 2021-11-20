#include "WrongAnimal.hpp"

void							WrongAnimal::makeSound(void) const
{
	std::cout << "CAN NOT MAKE SOUND\n";
}

WrongAnimal&							WrongAnimal::operator=(const WrongAnimal& a)
{
	if (this != &a)
		this->_type = a._type;
	return (*this);
}

WrongAnimal::WrongAnimal(void)
	:	_type(WA_DEFAULT)
{
	std::cout << "[WrongAnimal] Default Constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
	:	_type(a._type)
{
	std::cout << "[WrongAnimal] Copy Constructor\n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal] Destructor\n";
}

