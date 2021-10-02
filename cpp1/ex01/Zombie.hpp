#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
class Zombie
{

private:
	std::string name;
public:
	Zombie(void) { name = "Default Zombie"; }
	~Zombie(void);
	void announce( void );
	Zombie* zombieHorde( int N, std::string name );
};

#endif
