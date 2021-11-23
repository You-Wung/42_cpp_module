#include "Ice.hpp"

AMateria*							Ice::clone(void) const
{
	return (new Ice());
}
void								Ice::use(ICharacter& ic)
{
	std::cout << "* shoots an ice bolt at " << ic.getName() << "*\n";
}
Ice&								Ice::operator=(const Ice& i)
{
	if (this != &i)
		_type = i._type;
	return (*this);
}
Ice::Ice(void) : AMateria(I_NAME)
{	
}
Ice::Ice(const std::string& type) : AMateria(type)
{
}
Ice::Ice(const Ice& i) : AMateria(i._type)
{
}
Ice::~Ice(void)
{
}