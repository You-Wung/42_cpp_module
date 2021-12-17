#ifndef R_FORM
# define R_FORM

# include "Form.hpp"

# define R_NAME								"RotobomyRequestForm"
# define R_SIGN								72
# define R_EXEC								45

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm(void);

	public:
		void								execute(const Bureaucrat& b) const;

		RobotomyRequestForm&				operator=(const RobotomyRequestForm& r);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& r);
		~RobotomyRequestForm(void);
};

#endif