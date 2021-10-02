#include "Weapon.hpp"

const std::string& Weapon::getType(void) 
{
	return (str);
}

void Weapon::setType(std::string str)
{
	this->str = str;
}

Weapon::Weapon(void)
{
	this->str = "";
}

Weapon::Weapon(std::string str)
{
	this->str = str;
}

Weapon::~Weapon()
{
}