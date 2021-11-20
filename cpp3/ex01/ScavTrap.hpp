#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	void guardGate(void);
	void attack(std::string const & target);//오버라이딩
	//int attack(int a);//오버로딩
	ScavTrap &operator=(const ScavTrap &c);
	ScavTrap(void);
	ScavTrap(const std::string s);
	ScavTrap(const ScavTrap &s);
	~ScavTrap();
};



#endif