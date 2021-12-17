#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define A_size 3
int main()
{
	//Animal a;
	//a.makeSound();

	Dog *a[A_size];
	Cat *b[A_size];
	for (int i=0; i<A_size; i++)
	{
		a[i] = new Dog();
		b[i] = new Cat();
	}
	for (int i=0; i<A_size; i++)
	{
		delete a[i];
		delete b[i];
	}
}