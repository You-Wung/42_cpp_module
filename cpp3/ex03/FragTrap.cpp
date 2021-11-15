#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW << "[  FragTrap   ] hi fives\n" << OG;
}

FragTrap::FragTrap(void)
{
	std::cout << YELLOW << "    FragTrap construction called" << OG << std::endl;
	_name = "default";
	_hitPoint = 100;
	_energyPoint = 100;
	_attackPoint = 30;
}

FragTrap::FragTrap(const FragTrap &f)
{
	std::cout << YELLOW << "    FragTrap construction called" << OG << std::endl;
	_name = f._name;
	_hitPoint = f._hitPoint;
	_energyPoint = f._energyPoint;
	_attackPoint = f._attackPoint;
}


FragTrap::FragTrap(std::string s)
{
	std::cout << YELLOW << "    FragTrap construction called" << OG << std::endl;
	_name = s;
	_hitPoint = 100;
	_energyPoint = 100;
	_attackPoint = 30;
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "    FragTrap destruction called" << OG << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &c)
{
	return (*this);
}
