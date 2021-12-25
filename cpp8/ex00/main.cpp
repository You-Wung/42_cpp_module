
#include "easyfind.hpp"

int main(void)
{
	std::deque<int>		d = { 3, 4, 9, 3, 2, 0, 8 };
	std::list<int>		l = { 7, 5, 1, 3, 9, 7, 3 };
	std::vector<int>	v = { 4, 2, 3, 1, 6, 7, 2 };

	easyfind(d, 0);
	easyfind(d, 10);
	easyfind(l, 3);
	easyfind(l, 10);
	easyfind(v, 4);
	easyfind(d, 10);
	return (0);
}
