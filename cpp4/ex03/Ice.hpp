
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

# define I_NAME								"ice"

class Ice : public AMateria
{
	public:
		AMateria*							clone(void) const;
		void								use(ICharacter& ic);

		Ice&								operator=(const Ice& i);

		Ice(void);
		Ice(const std::string& type);
		Ice(const Ice& i);
		virtual ~Ice(void);
};

#endif
