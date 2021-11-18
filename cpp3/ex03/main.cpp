#include "DiamondTrap.hpp"

int main()
{
	{
		DiamondTrap d1("monster");
		d1.beRepaired(100);
		d1.attack("enemy");
		d1.whoAmI();
	}
	{
		std::cout << std::endl;
		DiamondTrap d2;

		d2.whoAmI();
		d2.attack("Vi");
		d2.highFivesGuys();
	}
	std::cout << std::endl;
	DiamondTrap *d = new DiamondTrap();
	ClapTrap *s = d;
	delete s;
 }