#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# define D_NAME			"Dog"

class Dog : public Animal
{
	private:
		Brain *_b;
	public:
		void					makeSound(void) const;
		void					print(unsigned int i);

		Dog&					operator=(const Dog& c);
		Dog(void);
		Dog(const Dog& c);
		virtual ~Dog(void);
};

#endif