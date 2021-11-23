#ifndef ATERIASOURCE_HPP
# define ATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria*				_am[ARRAY];
public:
	void learnMateria(AMateria *am);
	AMateria *createMateria(std::string const &type);

	MateriaSource&				operator=(const MateriaSource& c);
	MateriaSource(void);
	MateriaSource(const MateriaSource& c);
	~MateriaSource();
};

#endif