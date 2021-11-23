#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iomanip>
# include <iostream>
# include <string>

# define A_DEFAULT	"Animal_default"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define OG			"\033[0;0m"


class Animal
{
	protected:
		std::string				_type;

	public:
		virtual void			makeSound(void) const = 0;
		std::string				getType(void) const;
		Animal&					operator=(const Animal& a);
		Animal(void);
		Animal(const Animal& a);
		virtual ~Animal(void);
};

#endif