#ifndef FLAG_TRAP_HPP
# define FLAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	void highFivesGuys(void);
	FragTrap(void);
	FragTrap(const std::string s);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &c);
	~FragTrap();
};




#endif