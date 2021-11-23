#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# define C_NAME			"Cat"

class Cat : public Animal
{
	private:
		Brain *_b;
	public:
		void					makeSound(void) const;
		void					print(unsigned int i);

		Cat&					operator=(const Cat& c);
		Cat(void);
		Cat(const Cat& c);
		virtual ~Cat(void);
};

#endif