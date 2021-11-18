#include "DiamondTrap.hpp"

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << BLUE << "[  WHO AM I   ] its name: " << _name << std::endl;
	std::cout << "[  WHO AM I   ] clapTrap name: " << ClapTrap::_name << OG << std::endl;
}

DiamondTrap::DiamondTrap(void)
{
	std::cout << BLUE << "      DiamondTrap construction called" << OG << std::endl;
	ClapTrap::_name = "default_clap_name";
	_name = "default";
	_hitPoint = F_HP;
	_energyPoint = S_EP;
	_attackPoint = F_AP;
}

DiamondTrap::DiamondTrap(const std::string s)
{
	std::cout << BLUE << "      DiamondTrap construction called" << OG << std::endl;
	ClapTrap::_name = s + "_clap_name";
	_name = s;
	_hitPoint = F_HP;
	_energyPoint = S_EP;
	_attackPoint = F_AP;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
{
	std::cout << BLUE << "      DiamondTrap construction called" << OG << std::endl;
	ClapTrap::_name = d._name + "_clap_name";
	_name = d._name;
	_hitPoint = d._hitPoint;
	_energyPoint = d._energyPoint;
	_attackPoint = d._attackPoint;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << BLUE << "      DiamondTrap destruction called" << OG << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &d)
{
	if (this != &d)
	{
		_name = d._name;
		_hitPoint = d._hitPoint;
		_energyPoint = d._energyPoint;
		_attackPoint = d._attackPoint;
	}
	return (*this);
}
