#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define A_size 10
int main()
{
	
	{
		for (int i = 0; i < A_size; i++)
		{
			if (i % 2 != 0)
				a[i] = new Dog();
			else
				a[i] = new Cat();
		}
		for (int i = 0; i < A_size; i++)
			delete a[i];
	}
	Dog basic;
	{
		Dog tmp = basic;
	}
	
}