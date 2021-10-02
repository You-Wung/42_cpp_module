#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP
# include <iostream>
# include <iomanip>
# include <string>
# include <stdlib.h>

class PhoneBook {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	PhoneBook(void) { }
	~PhoneBook(void) { }
	void add_index(void);
	void search(int index);
	void print(int index);
};

#endif