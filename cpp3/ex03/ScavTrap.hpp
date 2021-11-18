#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"
# define S_HP 100
# define S_EP 50
# define S_AP 20
class ScavTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	void guardGate(void);
	ScavTrap &operator=(const ScavTrap &c);
	ScavTrap(void);
	ScavTrap(const std::string s);
	ScavTrap(const ScavTrap &s);
	virtual ~ScavTrap();
};



#endif