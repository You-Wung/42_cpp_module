#include "PhoneBook.hpp"

void PhoneBook::add_index(void)
{
	std::cout << "first name: ";
	std::cin  >> first_name;
	std::cout << "last name: ";
	std::cin >> last_name;
	std::cout << "nickname: ";
	std::cin >> nickname;
	std::cout << "phone number: ";
	std::cin >> phone_number;
	std::cout << "darkest secret: ";
	std::cin >> darkest_secret;
	std::cout << "\nSUCCESS\n\n";
}

void PhoneBook::search(int index)
{
	std::string str;

	std::cout << "|" << std::setw(10) << index + 1;
	str = first_name;
	if (str.length() > 9)
		std::cout << "|" << str.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << str;
	str = last_name;
	if (str.length() > 9)
		std::cout << "|" << str.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << str;
	str = nickname;
	if (str.length() > 9)
		std::cout << "|" << str.substr(0, 9) << "." << "|";
	else
		std::cout << "|" << std::setw(10) << str << "|";
	std::cout << std::endl;
}

void PhoneBook::print(int index)
{
	std::cout << "\n==DATA OF INDEX " << index + 1 << "==\n";
	std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "darkest secret: " << darkest_secret << std::endl << std::endl;
}

int main()
{
	PhoneBook pb[8];
	std::string str;
	int i = 0;
	int book = 0;
	
	for(;;)
	{
		std::cout << "======[PhoneBook]======\n\nWrite \"ADD\" or \"SEARCH\" or \"EXIT\"\n";
		std::cout << " >";
		if (i == 8)
			i = 0;
		std::cin >> str;
		if (std::cin.eof())
			return (0);
		if (str == "EXIT" && str.length() == 4)
			return (0);
		else if (str == "ADD" && ++book && str.length() == 3)
			pb[i++].add_index();
		else if (str == "SEARCH" && str.length() == 6)
		{
			if (book == 0)
				std::cout << "[ERROR]: The book is empty\n\n";
			else
			{	
				std::cout << "|" << std::setw(10) << "index" << "|" << std::setw(10) << "first name";
				std::cout << "|" << std::setw(10) << "last name" << "|" << std::setw(10);
				std::cout << "nickname" << "|" << "\n|----------|----------|----------|----------|\n";
				for(int z = 0; z < book && z < 8; z++)
					pb[z].search(z);
				std::cout << "\nwhich index do you want to see? >";
				std::cin >> str;
				if (std::cin.eof())
					return (0);
				if (atoi(str.c_str()) && book >= atoi(str.c_str()))
					pb[atoi(str.c_str()) - 1].print(atoi(str.c_str()) - 1);
				else
					std::cout << "[ERROR]: Wrong index\n\n";
			}
		}
		else
			std::cout << "[ERROR]: Write \"ADD\" or \"SEARCH\" or \"EXIT\"\n\n";
	}
}
