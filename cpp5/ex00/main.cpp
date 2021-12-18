#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("tyou", 100);
	Bureaucrat a = b;
	//Bureaucrat c("test", -100);

	std::cout << b;
	std::cout << a;
}