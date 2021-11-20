#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

# define C_NAME			"Cat"

class WrongCat : public WrongAnimal
{
	public:
		void					makeSound(void) const;

		WrongCat&					operator=(const WrongCat& c);
		WrongCat(void);
		WrongCat(const WrongCat& c);
		~WrongCat(void);
};

#endif