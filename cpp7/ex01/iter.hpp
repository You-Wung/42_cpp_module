#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <iomanip>

template <typename T>
void										iter(T* arr, std::size_t len, void (*fp)(T))
{
	for (std::size_t i = 0 ; i < len ; ++i)
		fp(arr[i]);
	std::cout << "\n\n";
}

template <typename T>
void										print(T arg)
{
	std::cout << " │" << std::fixed << std::setprecision(1) << arg << "\t";
}
#endif