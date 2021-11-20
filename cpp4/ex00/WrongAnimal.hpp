
#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iomanip>
# include <iostream>
# include <string>

# define WA_DEFAULT	"WrongAnimal_default"

class WrongAnimal
{
	protected:
		std::string				_type;

	public:
		void			makeSound(void) const;

		WrongAnimal&					operator=(const WrongAnimal& a);
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& a);
		~WrongAnimal(void);
};

#endif