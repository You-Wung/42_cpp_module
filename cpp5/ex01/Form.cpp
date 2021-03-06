#include "Form.hpp"

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade Too High");
}
const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade Too Low");
}
const std::string&	Form::getName(void) const
{
	return (_name);
}
const int&	Form::getSignGrade(void) const
{
	return (_sign_grade);
}
const int&	Form::getExecGrade(void) const
{
	return (_exec_grade);
}
const bool&	Form::getSigned(void) const
{
	return (_signed);
}
void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= _sign_grade)
		_signed = true;
	else
		throw Form::GradeTooLowException();
}
Form&	Form::operator=(const Form& f)
{
	if (this != &f)
	{
		*(const_cast<std::string *>(&_name)) = f.getName();
		*(const_cast<int *>(&_sign_grade)) = f.getSignGrade();
		*(const_cast<int *>(&_exec_grade)) = f.getExecGrade();
		_signed = f.getSigned();
	}
	return (*this);
}
Form::Form(void)
: _sign_grade(0), _exec_grade(0) { }

Form::Form(const Form& f)
: _name(f.getName()), _sign_grade(f.getSignGrade()), _exec_grade(f.getExecGrade()), _signed(false)
{
	if (_sign_grade < GRADE_MAX || _exec_grade < GRADE_MAX)
		throw GradeTooHighException();
	if (_sign_grade > GRADE_MIN || _exec_grade > GRADE_MIN)
		throw GradeTooLowException();
}
Form::Form(const std::string& name, const int& sign_grade, const int& exec_grade)
: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (_sign_grade > GRADE_MAX || _exec_grade > GRADE_MAX)
		throw GradeTooHighException();
	if (_sign_grade < GRADE_MIN || _exec_grade < GRADE_MIN)
		throw GradeTooLowException();
}
Form::~Form(void)
{
}
std::ostream&	operator<<(std::ostream& o, const Form& f)
{
	if (f.getSigned())
		return (o << "<" << f.getName() << ">, sign grade <" << f.getSignGrade() << ">, exec grade <" << f.getExecGrade() << ">, signed");
	else
		return (o << "<" << f.getName() << ">, sign grade <" << f.getSignGrade() << ">, exec grade <" << f.getExecGrade() << ">, unsigned");
}
