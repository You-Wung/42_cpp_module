#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Form* rrf1, *rrf2, *rrf3;
	rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf2 = someRandomIntern.makeForm("presidential pardon", "tyou");
	rrf3 = someRandomIntern.makeForm("shrubbery creation", "tyou2");

	delete (rrf1);
	delete (rrf2);
	delete (rrf3);
}