#include "HumanA.hpp"

void HumanA::attack(void)
{
	std::cout << name << " attacks with his " << w.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &w)
: w(w), name(name)
{
}

HumanA::~HumanA()
{
}