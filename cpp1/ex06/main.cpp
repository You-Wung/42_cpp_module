#include "Karen.hpp"

static int	find_index(char *str)
{
	int ret;

	if (!strcmp(str, "debug"))
		ret = 1;
	else if (!strcmp(str, "info"))
		ret = 2;
	else if (!strcmp(str, "warning"))
		ret = 3;
	else if (!strcmp(str, "error"))
		ret = 4;
	else
	 	ret = 0;
	return (ret);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "wrong arguments!\n";
		return (0);
	}
	Karen k;
	int i;

	i = find_index(av[1]);
	switch (i)
	{
	case 1:
		k.complain("debug");
	case 2:
		k.complain("info");
	case 3:
		k.complain("warning");
	case 4:
 		k.complain("error");
		break;
	default:
		std::cout << "[ Probably complaining about \
insignificant problems ]\n\n";
	}
}