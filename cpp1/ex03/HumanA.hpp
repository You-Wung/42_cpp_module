#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
private:
	Weapon &w;
	std::string name;
public:
	HumanA(std::string name, Weapon &w);
	~HumanA();
	void attack(void);
};




#endif