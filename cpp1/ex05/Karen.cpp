#include "Karen.hpp"

void Karen::debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double\
-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}
void Karen::info(void)
{
	std::cout << "I cannot believe adding extra bacon \
cost more money. You don’t put enough! If you did I would \
not have to ask for it!\n";
}
void Karen::error(void)
{
	std::cout << "I think I deserve to have some extra bacon \
for free. I’ve been coming here for years and you just \
started working here last month.\n";
}
void Karen::warning(void)
{
	std::cout <<  "This is unacceptable, I want to speak to \
the manager now.\n";
}
void Karen::init_cmd(t_list lst[])
{
	lst[0].name = "debug";
	lst[0].ptr = &Karen::debug;
	lst[1].name = "info";
	lst[1].ptr = &Karen::info;
	lst[2].name = "error";
	lst[2].ptr = &Karen::error;
	lst[3].name = "warning";
	lst[3].ptr = &Karen::warning;
}
void Karen::complain(std::string level)
{
	int i;
	t_list lst[4];

	i = 0;
	init_cmd(lst);
	for(i = 0; i < 4 && level != lst[i].name; i++)
	{
		;
	}
	for(; i < 4;)
	{
		(this->*(lst[i].ptr))();//아래두줄 축약
		//void(Karen::*p)(void) = lst[i].ptr;
		//(this->*p)();
		return ;
	}
}
