#include "ScavTrap.hpp"

void ScavTrap::attack(std::string const & target)
{
	std::cout << GREEN << "[   ATTACK    ]\t";
	if (!_hitPoint)
		std::cout << "ScavTrap " << _name << " dead\n";
	else if (!_energyPoint)
		std::cout << "ScavTrap " << _name << " has no energy\n";
	else
	{
		_energyPoint--;
		std::cout << "ScavTrap " << _name << " attacks " << target;
		std::cout <<  ", causing " << _attackPoint << " points of damage!";
		std::cout << " energy : " << _energyPoint << std::endl;
	}
	std::cout << OG;
}


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

//https://pony11.tistory.com/26
ScavTrap &ScavTrap::operator=(const ScavTrap &c)//뒤에 나온 연산자 = 
{
	if (this != &c)
	{
		_name = c._name;
		_hitPoint = c._hitPoint;
		_energyPoint = c._energyPoint;
		_attackPoint = c._attackPoint;
	}
	return (*this);
}