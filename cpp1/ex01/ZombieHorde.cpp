#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie* zb = new Zombie[N];
	for(int i = 0; i < N; i++)
		zb[i].name = name;
	return (&zb[0]);
}