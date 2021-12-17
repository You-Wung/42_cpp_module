#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <fstream>
# include <random>
# include "Bureaucrat.hpp"

# define NAME "Default"

class Bureaucrat;

class Form
{
	private:
		const std::string					_type;
		const std::string					_name;
		const int							_sign_grade;//승인가능 등급
		const int							_exec_grade;//실행가능 등급
		bool								_signed;//승인된

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		
		void								setType(const std::string& type);
		const std::string&					getType(void) const;

		const std::string&					getName(void) const;
		const int&							getSignGrade(void) const;
		const int&							getExecGrade(void) const;
		const bool&							getSigned(void) const;

		void								beSigned(const Bureaucrat& b);

		Form&								operator=(const Form& f);
		Form(void);
		Form(const Form& f);
		Form(const std::string& name, const int& sign_grade, const int& exec_grade);
		virtual ~Form(void);

		class DoesNotSignedException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		void								executable(const Bureaucrat& b) const;
		virtual void						execute(const Bureaucrat& b) const = 0;
};

std::ostream&								operator<<(std::ostream& o, const Form& f);

#endif