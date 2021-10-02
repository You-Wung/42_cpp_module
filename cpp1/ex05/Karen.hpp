#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	public:
		void complain(std::string level);
	private:
		typedef struct cmdlist
		{
			std::string name;
			void(Karen::*ptr)(void);
		}t_list;
		void init_cmd(t_list lst[]);
		void debug(void);
		void info(void);
		void error(void);
		void warning(void);
};

#endif