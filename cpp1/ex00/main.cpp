#include "Zombie.hpp"

int main()
{
	Zombie z;

	Zombie *z1 = z.newZombie("Zombie1");
	z1->announce();
	z1->randomChump("Zombie2");
	delete z1;
}