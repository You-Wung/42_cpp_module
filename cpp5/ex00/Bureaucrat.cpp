#include "Bureaucrat.hpp"

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat Grade Too Low");
}

const std::string&		Bureaucrat::getName(void) const
{
	return (name);
}
const int&				Bureaucrat::getGrade(void) const
{
	return (grade);
}
int&					Bureaucrat::incrementGrade(void)
{
	if (grade - 1 < GRADE_MIN)
		throw GradeTooHighException();
	return (--grade);
}
int&					Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > GRADE_MAX)
		throw GradeTooLowException();
	return (++grade);
}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& b)
{
	if (this != &b)
	{
		*(const_cast<std::string*>(&name)) = b.getName();
		grade = b.getGrade();
	}
	return (*this);
}
Bureaucrat::Bureaucrat(const Bureaucrat& b)
: name(b.getName()), grade(b.getGrade())
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade)
: name(name), grade(grade)
{
	if (this->grade > GRADE_MAX)
		throw GradeTooHighException();
	else if (this->grade < GRADE_MIN)
		throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat(void) { }

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& b)
{
	return (o << b.getName() << ", bureaucrat " << b.getGrade() << std::endl);
}
