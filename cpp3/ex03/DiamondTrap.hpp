#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, FragTrap
{
private:
	/* data */
public:
	DiamondTrap(void);
	DiamondTrap(const std::string s);
	DiamondTrap(const DiamondTrap &d);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &d);
};




#endif