
#include "Data.hpp"
#include <sys/types.h>

const std::string&							Data::getName(void) const
{
	return (_name);
}
const unsigned int&							Data::getPrice(void) const
{
	return (_price);
}
Data&										Data::operator=(const Data& d)
{
	if (this != &d)
	{
		_name = d.getName();
		_price = d.getPrice();
	}
	return (*this);
}

Data::Data(void)
	: _name(""), _price(0) {}

Data::Data(const std::string& name, unsigned int price)
	:	_name(name),_price(price) {}

Data::Data(const Data& d)
	:	_name(d.getName()), _price(d.getPrice()) {}

Data::~Data(void) {}

uintptr_t								serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*									deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream&							operator<<(std::ostream& o, const Data& ptr)
{
	return (o << "Address : " << &ptr << std::endl
				<< "Name : " << ptr.getName() << std::endl
				<< "Price : " << ptr.getPrice() << std::endl);
}
