#ifndef S_FORM
# define S_FORM

# include "Form.hpp"

# define S_NAME								"ShrubberyCreationForm"
# define S_SIGN								145
# define S_EXEC								137

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm(void);

	public:
		void								execute(const Bureaucrat& b) const;

		ShrubberyCreationForm&				operator=(const ShrubberyCreationForm& s);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& s);
		~ShrubberyCreationForm(void);
};


#endif