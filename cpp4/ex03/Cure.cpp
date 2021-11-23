#include "Cure.hpp"

AMateria*							Cure::clone(void) const
{
	return (new Cure());
}
void								Cure::use(ICharacter& ic)
{
	std::cout << "* heals " << ic.getName() << "'s wounds *" << std::endl;
}
Cure&								Cure::operator=(const Cure& i)
{
	if (this != &i)
		_type = i.getType();
	return (*this);
}
Cure::Cure(void) : AMateria(C_NAME)
{
}
Cure::Cure(const std::string& type) : AMateria(type)
{
}
Cure::Cure(const Cure& i) : AMateria(i.getType())
{
}
Cure::~Cure(void)
{
}