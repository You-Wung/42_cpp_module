#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	PresidentialPardonForm a("a");
	RobotomyRequestForm b("b");
	ShrubberyCreationForm c("tyou");

	Bureaucrat human("human", 50);
	human.signForm(a);
	human.executeForm(a);
	human.signForm(b);
	human.executeForm(b);
	human.signForm(c);
	human.executeForm(c);

}