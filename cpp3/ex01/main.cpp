#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap s1;

		s1.attack("enemy");
	}
	std::cout << std::endl;
	ScavTrap s2("MONSTER");

	s2.beRepaired(10);
 }