#ifndef FLAG_TRAP_HPP
# define FLAG_TRAP_HPP

# include "ClapTrap.hpp"
# define F_HP 100
# define F_EP 100
# define F_AP 30
class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	void highFivesGuys(void);
	FragTrap(void);
	FragTrap(const std::string s);
	FragTrap(const FragTrap &f);
	FragTrap &operator=(const FragTrap &c);
	virtual ~FragTrap();
};




#endif