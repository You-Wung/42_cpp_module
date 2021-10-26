#include "Zombie.hpp"

int main()
{
	int number;
	number = 4;

	Zombie test;
	Zombie* zb = test.zombieHorde(number, "Test Zombie");

	for(int i = 0; i < number; i++)
		zb[i].announce();
	delete [] zb;
}