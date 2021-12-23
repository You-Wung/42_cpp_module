#ifndef IC_CHARACTER_HPP
# define IC_CHARACTER_HPP

# include "AMateria.hpp"
# include <string>
# include <iomanip>
# include <iostream>

class AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual std::string const &getName() const = 0;
	
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

#endif