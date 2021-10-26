#include "HumanB.hpp"

void HumanB::attack(void)
{
	std::cout << name << " attacks with his " << w->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &w)
{
	this->w = &w;
}

HumanB::HumanB(std::string name)
: w(NULL), name(name)
{

}

HumanB::~HumanB()
{
}