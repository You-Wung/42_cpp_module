#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <cstdlib>
# define A_SIZE 100

class Brain
{
private:
		std::string ideas[A_SIZE];
public:
		static int c;
		void	print(unsigned int i);

		Brain&	operator=(const Brain& c);
		Brain(void);
		Brain(const Brain& c);
		virtual ~Brain(void);
};

# endif