#include "Intern.hpp"

const char*	Intern::NoMatchingTypeException::what(void) const throw()
{
	return ("No Matching Type");
}

Form*		Intern::makeForm(const std::string& type, const std::string& name)
{
	forms[0] = new PresidentialPardonForm(name);
	forms[1] = new RobotomyRequestForm(name);
	forms[2] = new ShrubberyCreationForm(name);

	for (int i = 0 ; i < 3 ; ++i)
	{
		if ((P_FORM_NAME == type && i == 0) || (R_FORM_NAME == type && i == 1)
				|| (S_FORM_NAME == type && i == 2))
		{
			std::cout << "Intern creates <" << type << " : " << name << ">" << std::endl;
			switch (i)
			{
				case 0:
					return (new PresidentialPardonForm(name));
				case 1:
					return (new RobotomyRequestForm(name));
				case 2:
					return (new ShrubberyCreationForm(name));
			}
		}
	}
	throw (NoMatchingTypeException());
}


Intern::Intern(void)
{
	for (int z=0; z<3; z++)
		forms[z] = NULL;
}

Intern::Intern(const Intern& i)
{
	for (int z=0; z<3; z++)
			forms[z] = i.forms[z];
}

Intern&										Intern::operator=(const Intern& i)
{
	for (int z=0; z<3; z++)
			forms[z] = i.forms[z];
	return (*this);
}

Intern::~Intern(void)
{
	for (int z=0; z<3; z++)
	{
		if (forms[z])
			delete (forms[z]);
	}
}