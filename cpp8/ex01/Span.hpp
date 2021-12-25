#ifndef SPAN_HPP
# define SPAN_HPP

# include <array>
# include <algorithm>
# include <exception>
# include <numeric>
# include <iterator>
# include <iostream>
# include <vector>


# define RED						"\033[0;31m"
# define GREEN						"\033[0;32m"
# define YELLOW						"\033[1;33m"
# define OG							"\033[0;0m"
# define ERR						std::cerr << RED
class Span
{
	private:
		std::vector<unsigned int>				_data;

		Span(void);

	public:
		const std::vector<unsigned int>&	getData(void) const { return (_data); }

		void								addNumber(unsigned int value);

		unsigned int						shortestSpan(void);
		unsigned int						longestSpan(void);

		Span&								operator=(const Span& s);
		Span(unsigned int n);
		Span(const Span& s);
		~Span(void);
};

#endif