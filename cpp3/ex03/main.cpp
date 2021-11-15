#include "FragTrap.hpp"

int main()
{
	{
		FragTrap f1;

		f1.attack("enemy");
	}
	std::cout << std::endl;
	FragTrap f2("MONSTER");

	f2.beRepaired(10);
 }