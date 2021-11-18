#include "ScavTrap.hpp"

int main()
{
	{
		ScavTrap s1;

		s1.attack("enemy");
	}
	{
		ClapTrap c1;
		c1.attack("enemy");
	}
	{
		std::cout << std::endl;
		ScavTrap s2("MONSTER");
		s2.guardGate();
		s2.beRepaired(10);
	}
 }