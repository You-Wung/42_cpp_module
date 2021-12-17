#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	//PresidentialPardonForm a("a");
	//RobotomyRequestForm b("b");
	//ShrubberyCreationForm c("c");

	//Bureaucrat human("human", 5);
	//human.signForm(a);
	//human.executeForm(a);
	//human.signForm(c);
	//human.executeForm(c);

	Intern someRandomIntern;
	Form* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}