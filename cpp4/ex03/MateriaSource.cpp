#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *am)
{
	if (!am)
		return ;
	for (int i=0; i<ARRAY; i++)
	{
		if (!_am[i])
		{
			_am[i] = am;
			return ;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i=0; i<ARRAY; i++)
	{
		if (_am[i] && _am[i]->getType() == type)
			return (_am[i]->clone());
	}
	return (NULL);
}
MateriaSource&		MateriaSource::operator=(const MateriaSource& c)
{
	for (int i=0; i<ARRAY; i++)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		_am[i] = c._am[i]->clone();
	}
	return (*this);
}
MateriaSource::MateriaSource(void)
{
	for (int i=0; i<ARRAY; i++)
		_am[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& c)
{
	for (int i=0; i<ARRAY; i++)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		_am[i] = c._am[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i=0; i<ARRAY; i++)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
	}
}
