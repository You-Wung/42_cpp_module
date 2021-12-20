#include "Conversion.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error\n";
		return (0);
	}
	Conversion c(argv[1]);
	std::cout << c;
}