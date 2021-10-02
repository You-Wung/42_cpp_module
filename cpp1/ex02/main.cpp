#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = new std::string;
	*stringPTR = str;

	std::string *stringREF;
	stringREF = stringPTR;
	std::cout << "address of string   : " << &str << std::endl;
	std::cout << "address of stringPTR: " << stringPTR << std::endl;
	std::cout << "address of stringREF: " << stringREF << std::endl << std::endl;

	std::cout << "1. " << *stringREF << std::endl;
	std::cout << "2. " << *stringPTR << std::endl;
	delete stringPTR;
}