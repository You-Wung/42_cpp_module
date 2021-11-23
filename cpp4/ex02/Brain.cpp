#include "Brain.hpp"

int Brain::c = 0;

void	Brain::print(unsigned int i)
{
	for(unsigned int z=0; z<i; z++)
		std::cout << ideas[z] << std::endl;
}


Brain&	Brain::operator=(const Brain& c)
{
	for (int i=0; i<A_SIZE; i++)
			ideas[i] = c.ideas[i];
	return (*this);
}
Brain::Brain(void)
{
	if (c == 10)
		c = 0;
	srand((unsigned int)time(NULL));
	for (int i=0; i<A_SIZE; i++)
	{
		for (int j=0; j<5; j++)
		{
			int rand2 = rand() << c;
			if (rand2 < 0)
				rand2 = -rand2;
			if (rand2 % 2 == 1)
				ideas[i] += (rand2 % 26) + 65;
			else
				ideas[i] += (rand2 % 26) + 97;
		}
	}
	c++;
}
Brain::Brain(const Brain& c)
{
	if (this != &c)
	{
		for (int i=0; i<A_SIZE; i++)
			ideas[i] = c.ideas[i];
	}
}
Brain::~Brain(void)
{

}