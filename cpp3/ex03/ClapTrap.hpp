#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iomanip> 
# include <iostream>
# include <string>
# define RED						"\033[0;31m"
# define GREEN						"\033[0;32m"
# define YELLOW						"\033[1;33m"
# define BLUE						"\033[1;34m"
# define OG							"\033[0;0m"

# define C_HP 10
# define C_EP 10
# define C_AP 0

class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;//공격가능횟수
	unsigned int	_attackPoint;

public:
	virtual void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap(void);
	ClapTrap(const std::string s);
	ClapTrap(const ClapTrap &c);
	virtual ~ClapTrap();
	ClapTrap&	operator=(const ClapTrap& c);


};



#endif