#ifndef DATA_HPP
# define DATA_HPP

# include <cstdint>
# include <string>
# include <iostream>

class Data
{
	private:
		std::string						_name;
		unsigned int					_price;

		Data(void);

	public:
		const std::string&				getName(void) const;
		const unsigned int&				getPrice(void) const;

		Data&							operator=(const Data& d);
		Data(const std::string& name, unsigned int price);
		Data(const Data& d);
		~Data(void);
};

uintptr_t								serialize(Data* ptr);
Data*									deserialize(uintptr_t raw);
std::ostream&							operator<<(std::ostream& o, const Data& ptr);
void									print(uintptr_t raw);

#endif