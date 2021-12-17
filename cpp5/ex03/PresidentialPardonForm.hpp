#ifndef P_FORM
# define P_FORM

# include "Form.hpp"

# define P_NAME								"PresidentialPardonForm"
# define P_FORM_NAME						"presidential pardon"
# define P_SIGN								25
# define P_EXEC								5

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm(void);

	public:
		void								execute(const Bureaucrat& b) const;

		PresidentialPardonForm&				operator=(const PresidentialPardonForm& p);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& p);
		~PresidentialPardonForm(void);
};

#endif