#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("alien1");
	ClapTrap b("alien2");

	for(int i=0; i<11; i++)
		a.attack("spaceship");
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(100);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.attack("spaceship");
}