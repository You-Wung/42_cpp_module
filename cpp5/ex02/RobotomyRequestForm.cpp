#include "RobotomyRequestForm.hpp"

void										RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	executable(b);
	std::random_device rd;// 시드값을 얻기 위한 random_device 생성.
	std::mt19937 gen(rd());// random_device 를 통해 난수 생성 엔진을 초기화 한다., mt19937 난수생성기
	std::uniform_int_distribution<int> dis(0, 1);

	if (dis(gen) ==  0)
	{
		std::cout << "drrrrrrrrrrrrrrr..." << std::endl;
		std::cout << getName() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "br br br..." << std::endl;
	 	std::cout << getName() << " failed to be robotomized" << std::endl;
	}
}

RobotomyRequestForm&						RobotomyRequestForm::operator=(const RobotomyRequestForm& r)
{
	return (*(dynamic_cast<RobotomyRequestForm*>(&(Form::operator=(r)))));
}

RobotomyRequestForm::RobotomyRequestForm(void)
: Form()
{
	setType(R_NAME);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: Form(target, R_SIGN, R_EXEC)
{
	setType(R_NAME);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& r)
: Form(r)
{
	setType(R_NAME);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}