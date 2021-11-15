#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	void guardGate(void);
	ScavTrap &operator=(const ScavTrap &c);
	ScavTrap(void);
	ScavTrap(const std::string s);
	ScavTrap(const ScavTrap &s);
	~ScavTrap();
};



#endif