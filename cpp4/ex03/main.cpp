#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* m =  new MateriaSource();
	m->learnMateria(new Ice());
	m->learnMateria(new Cure());

	ICharacter* person_A = new Character("person_A");

	AMateria* tmp;
	tmp = m->createMateria("ice");
	person_A->equip(tmp);
	delete tmp;
	tmp = m->createMateria("cure");
	person_A->equip(tmp);

	ICharacter* person_B = new Character("person_A");
	person_B->use(0, *person_A);
	person_B->use(1, *person_B);

	person_A->unequip(3);
	person_A->unequip(2);
	person_A->unequip(1);
	person_A->unequip(0);

	delete m;
	delete person_A;
	delete person_B;
	delete tmp;
}