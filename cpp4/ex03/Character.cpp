#include "Character.hpp"

const std::string& 			Character::getName(void) const
{
	return (_name);
}
void						Character::equip(AMateria* am)
{
	for (int i=0; i<ARRAY; i++)
	{
		if (!_am[i])
		{
			_am[i] = am;
			std::cout << "Successfully equipped at [ " << i << " ]\n";
			return ;
		}
	}
	std::cout << "equip failed\n";
}
void						Character::unequip(int idx)
{
	if (idx >= 0 && idx < ARRAY && _am[idx])
	{
		_am[idx] = NULL;
		std::cout << "Successfully unequipped at [ " << idx << " ]\n";
		return ;
	}
	std::cout << "unequip failed\n";
}
void						Character::use(int idx, ICharacter& ic)
{
	if (idx >= 0 && idx < ARRAY && _am[idx])
		_am[idx]->use(ic);
}
Character&					Character::operator=(const Character& c)
{
	_name = c._name;
	for (int i=0; i<ARRAY; i++)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		if (c._am[i])
			_am[i] = c._am[i]->clone();
	}
	return (*this);
}
Character::Character(void)
{
	_name = "";
	for (int i=0; i<ARRAY; i++)
		_am[i] = NULL;
}
Character::Character(const std::string& name)
{
	_name = name;
	for (int i=0; i<ARRAY; i++)
		_am[i] = NULL;
}
Character::Character(const Character& c)
{
	_name = c._name;
	for (int i=0; i<ARRAY; i++)
	{
		if (_am[i])
		{
			delete _am[i];
			_am[i] = NULL;
		}
		if (c._am[i])
			_am[i] = c._am[i]->clone();
	}
}
Character::~Character(void)
{
	for (int i=0; i<ARRAY; i++)
		delete _am[i];
}