#include "HumanA.hpp"

void HumanA::attack(void)
{
	//const std::string *buf = w.getType();
	//std::cout << name << " attacks with his" << *buf << std::endl;
	std::cout << name << " attacks with his" << w.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &w)
: w(w), name(name)
{
}

HumanA::~HumanA()
{
}