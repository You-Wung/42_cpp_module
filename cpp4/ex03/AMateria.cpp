#include "AMateria.hpp"

void	AMateria::use(ICharacter& ic)
{
	std::cout << "A Materia by " << ic.getName() << std::endl;
}

std::string const &			AMateria::getType() const
{
	return (_type);
}


AMateria&	AMateria::operator=(const AMateria& a)
{
	if (this != &a)
		_type = a.getType();
	return (*this);
}

AMateria::AMateria(void)
{
	_type = "";
}

AMateria::AMateria(const std::string& type)
{
	_type = type;
}

AMateria::AMateria(const AMateria& a)
{
	if (this != &a)
		_type = a.getType();
}

AMateria::~AMateria(void)
{

}