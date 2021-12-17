#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("tyou", 100);
	Bureaucrat a = b;

	std::cout << b;
	std::cout << a;
}