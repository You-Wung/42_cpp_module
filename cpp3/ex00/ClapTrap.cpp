#include "ClapTrap.hpp"

void ClapTrap::attack(std::string const &target)
{
	std::cout << RED << "[   ATTACK    ]\t";
	if (!_hitPoint)
		std::cout << "ClapTrap " << _name << " dead\n";
	else if (!_energyPoint)
		std::cout << "ClapTrap " << _name << " has no energy\n";
	else
	{
		_energyPoint--;
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout <<  ", causing " << _attackPoint << " points of damage!";
		std::cout << " energy : " << _energyPoint << std::endl;
	}
	std::cout << OG;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int	i = _hitPoint;

	std::cout << RED << "[ TAKE DAMAGE ]\t";
	if (!_hitPoint || i - amount <= 0)
	{
		std::cout << "ClapTrap " << _name << " takes " << amount;
		std::cout << " points of damage. " << _name << " dead\n";
		_hitPoint = 0;
	}
	else
	{
		_hitPoint -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount;
		std::cout << " points of damage. HP : " << _hitPoint << std::endl;
	}
	std::cout << OG;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << RED << "[ BE REPAIRED ]\t";
	_hitPoint += amount;
	std::cout << "ClapTrap " << _name << " gets " << amount;
	std::cout << " of HP. HP : " << _hitPoint << std::endl;
	std::cout << OG;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
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

ClapTrap::ClapTrap()
: _hitPoint(10), _energyPoint(10), _attackPoint(0)
{
	this->_name = "default";
	std::cout << RED << "ClapTrap constructor called" << OG <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << RED << "ClapTrap constructor called" << OG <<std::endl;
	_name = c._name;
	_hitPoint = c._hitPoint;
	_energyPoint = c._energyPoint;
	_attackPoint = c._attackPoint;
}


ClapTrap::ClapTrap(std::string s)
: _hitPoint(10), _energyPoint(10), _attackPoint(0)
{
	this->_name = s;
	std::cout << RED << "ClapTrap constructor called" << OG <<std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor called" << OG << std::endl;
}