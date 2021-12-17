#include "Bureaucrat.hpp"

int main()
{
	Form a("TEST_A", 1, 2);
	Form b("TEST_B", 1, 2);
	//Form c("TEST_C", -1, 200);
	Bureaucrat humanA("HUMAN", 1);

	a.beSigned(humanA);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}