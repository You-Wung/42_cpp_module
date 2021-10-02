#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
	Zombie* copy = new Zombie();

	copy->name = name;
	return (copy);
}