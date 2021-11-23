#include "Dog.hpp"
void	Dog::print(unsigned int i)
{
	_b->print(i);
}

void							Dog::makeSound(void) const
{
	std::cout << GREEN << "Bow Bow" << OG << std::endl;
}

Dog&							Dog::operator=(const Dog& c)
{
	std::cout << GREEN << "  [Dog] Assigned\n" << OG;
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

Dog::Dog(void)
	:	Animal(), _b(NULL)
{
	std::cout << GREEN << "  [Dog] Default Constructor\n" << OG;
	_type = D_NAME;
	_b = new Brain();
}

Dog::Dog(const Dog& c)
	:	Animal(), _b(NULL)
{
	std::cout << GREEN << "  [Dog] Copy constructor\n" << OG;
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

Dog::~Dog(void)
{
	std::cout << GREEN << "  [Dog] Destructor\n" << OG;
	delete _b;
}