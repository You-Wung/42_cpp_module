#include "WrongCat.hpp"

void		WrongCat::makeSound(void) const
{
	std::cout << "Wrong Wrong" << std::endl;
}

WrongCat&		WrongCat::operator=(const WrongCat& c)
{
	if (this != &c)
		_type = c._type;
	std::cout << "  [WrongCat] Assigned\n";
	return (*this);
}

WrongCat::WrongCat(void)
	:	WrongAnimal()
{
	_type = C_NAME;
	std::cout << "  [WrongCat] Default Constructor\n";
}

WrongCat::WrongCat(const WrongCat& c)
	:	WrongAnimal()
{
	_type = c._type;
	std::cout << "  [WrongCat] Copy constructed\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "  [WrongCat] Destructed\n";
}