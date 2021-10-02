#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
private:
	std::string str;
public:
	Weapon(std::string str);
	Weapon(void);
	~Weapon();
	const std::string& getType();
	void setType(std::string str);
};

#endif