#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define OG			"\033[0;0m"
# define GRADE_MIN	1
# define GRADE_MAX	150

class Bureaucrat
{
	private:
		const std::string					name;
		int									grade;
		Bureaucrat(void);
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

		const std::string&					getName(void) const;
		const int&							getGrade(void) const;

		int&								incrementGrade(void);
		int&								decrementGrade(void);

		Bureaucrat&							operator=(const Bureaucrat& b);
		Bureaucrat(const Bureaucrat& b);
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat(void);
};

std::ostream&								operator<<(std::ostream& o, const Bureaucrat& b);

#endif