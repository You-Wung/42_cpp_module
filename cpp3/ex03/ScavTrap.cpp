#include "ScavTrap.hpp"

void ScavTrap::guardGate(void)
{
	std::cout << GREEN << "  ScavTrap have enterred in Gate keeper mode.\n" << OG;
}

ScavTrap::ScavTrap(void)
{
	std::cout << GREEN << "  ScavTrap construction called" << OG << std::endl;
	_name = "default";
	_hitPoint = 100;
	_energyPoint = 50;
	_attackPoint = 20;
}

ScavTrap::ScavTrap(std::string s)
{
	std::cout << GREEN << "  ScavTrap construction called" << OG << std::endl;
	_name = s;
	_hitPoint = 100;
	_energyPoint = 50;
	_attackPoint = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	std::cout << GREEN << "  ScavTrap destruction called" << OG << std::endl;
	_name = s._name;
	_hitPoint = s._hitPoint;
	_energyPoint = s._energyPoint;
	_attackPoint = s._attackPoint;
}


ScavTrap::~ScavTrap(void)
{
	std::cout << GREEN << "  ScavTrap destruction called" << OG << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &c)
{
	return (*this);
}