#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <deque>
# include <list>
# include <vector>

# include <iostream>
# include <stdexcept>
# include <exception>

# define RED						"\033[0;31m"
# define GREEN						"\033[0;32m"
# define YELLOW						"\033[1;33m"
# define OG							"\033[0;0m"

template <typename T>
void								easyfind(T& container, int value)
{
	try {
		typename T::iterator iter = std::find(std::begin(container), std::end(container), value);
		if (iter == std::end(container))
			throw std::exception();
		std::cout << GREEN << "Value " << value << " found on Index " << std::distance(std::begin(container), iter) << OG << std::endl;
	} catch (std::exception) {
		std::cerr << RED << "Value " << value << " is not in the container\n" << OG;
	}
}

#endif