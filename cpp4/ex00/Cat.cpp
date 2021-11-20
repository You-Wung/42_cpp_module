#include "Cat.hpp"

void							Cat::makeSound(void) const
{
	std::cout << RED << "Meow Meow" << OG << std::endl;
}

Cat&							Cat::operator=(const Cat& c)
{
	if (this != &c)
		_type = c._type;
	std::cout << RED << "  [Cat] Assigned\n" << OG;
	return (*this);
}

Cat::Cat(void)
	:	Animal()
{
	_type = C_NAME;
	std::cout << RED << "  [Cat] Default Constructor\n" << OG;
}

Cat::Cat(const Cat& c)
	:	Animal()
{
	_type = c._type;
	std::cout << RED << "  [Cat] Copy constructed\n" << OG;
}

Cat::~Cat(void)
{
	std::cout << RED << "  [Cat] Destructed\n" << OG;
}