#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# define C_NAME			"Cat"

class Cat : public Animal
{
	public:
		void					makeSound(void) const;

		Cat&					operator=(const Cat& c);
		Cat(void);
		Cat(const Cat& c);
		virtual ~Cat(void);
};

#endif