#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# define D_NAME			"Dog"

class Dog : public Animal
{
	public:
		void					makeSound(void) const;

		Dog&					operator=(const Dog& c);
		Dog(void);
		Dog(const Dog& c);
		virtual ~Dog(void);
};

#endif