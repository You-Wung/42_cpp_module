#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
	Zombie buf;

	buf.name = name;
	buf.announce();
}
