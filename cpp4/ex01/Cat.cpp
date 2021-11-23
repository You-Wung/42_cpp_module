#include "Cat.hpp"

void	Cat::print(unsigned int i)
{
	_b->print(i);
}

void							Cat::makeSound(void) const
{
	std::cout << RED << "Meow Meow" << OG << std::endl;
}

Cat&							Cat::operator=(const Cat& c)
{
	std::cout << RED << "  [Cat] Assigned\n" << OG;
	if (this != &c)
	{
		_type = c._type;
		if (_b)
		{
			delete _b;
			_b = NULL;
		}
		_b = new Brain(*c._b);
	}
	return (*this);
}

Cat::Cat(void)
	:	Animal(), _b(NULL)
{
	std::cout << RED << "  [Cat] Default Constructor\n" << OG;
	_type = C_NAME;
	_b = new Brain();
}

Cat::Cat(const Cat& c)
	:	Animal(), _b(NULL)
{
	std::cout << RED << "  [Cat] Copy constructor\n" << OG;
	if (this != &c)
	{
		_type = c._type;
		if (_b)
		{
			delete _b;
			_b = NULL;
		}
		_b = new Brain(*c._b);
	}
}

Cat::~Cat(void)
{
	std::cout << RED << "  [Cat] Destructor\n" << OG;
	delete _b;
}