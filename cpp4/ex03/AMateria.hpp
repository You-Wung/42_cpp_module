#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include <iomanip>
# include <iostream>
# include "ICharacter.hpp"

# define ARRAY 4

class ICharacter;

class AMateria
{
	protected:
		std::string							_type;

	public:
		virtual AMateria*					clone(void) const = 0;
		virtual void						use(ICharacter& ic);
		std::string const &					 getType() const;

		AMateria&							operator=(const AMateria& a);

		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& a);
		virtual ~AMateria(void);
};

#endif