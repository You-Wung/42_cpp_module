#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
public:
	void attack(std::string const & target);
	void whoAmI(void);
	DiamondTrap(void);
	DiamondTrap(const std::string s);
	DiamondTrap(const DiamondTrap &d);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &d);
};




#endif