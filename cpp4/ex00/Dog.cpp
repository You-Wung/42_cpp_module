#include "Dog.hpp"

void							Dog::makeSound(void) const
{
	std::cout << GREEN << "Bow Bow" << OG << std::endl;
}

Dog&							Dog::operator=(const Dog& c)
{
	if (this != &c)
		_type = c._type;
	std::cout << GREEN << "  [Dog] Assigned\n" << OG;
	return (*this);
}

Dog::Dog(void)
	:	Animal()
{
	_type = D_NAME;
	std::cout << GREEN << "  [Dog] Default Constructor\n" << OG;
}

Dog::Dog(const Dog& c)
	:	Animal()
{
	_type = c._type;
	std::cout << GREEN << "  [Dog] Copy constructed\n" << OG;
}

Dog::~Dog(void)
{
	std::cout << GREEN << "  [Dog] Destructed\n" << OG;
}