#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	PresidentialPardonForm a("a");
	RobotomyRequestForm b("b");
	ShrubberyCreationForm c("c");

	Bureaucrat human("human", 5);
	human.signForm(a);
	human.executeForm(a);
	human.signForm(c);
	human.executeForm(c);

}