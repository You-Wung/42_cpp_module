#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << BLUE << "    FragTrap construction called" << OG << std::endl;

}

DiamondTrap::DiamondTrap(const std::string s)
{
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
{
	
}

DiamondTrap::~DiamondTrap()
{

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &d)
{
	return (*this);
}
