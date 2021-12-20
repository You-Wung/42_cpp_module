
#include "Conversion.hpp"
#include <cctype>

char										Conversion::toChar(void) const
{
	return (static_cast<char>(_value));
}
int											Conversion::toInt(void) const
{
	return (static_cast<int>(_value));
}
float										Conversion::toFloat(void) const
{
	return (static_cast<float>(_value));
}
double										Conversion::toDouble(void) const
{
	return (static_cast<double>(_value));
}
bool									Conversion::getBool(void) const
{
	return (_b);
}
const double& 							Conversion::getValue(void) const
{
	return (_value);
}
const std::string&							Conversion::getInput(void) const
{
	return (_input);
}

Conversion&									Conversion::operator=(const Conversion& c)
{
	if (this != &c)
	{
		_b = c.getBool();
		*(const_cast<std::string*>(&_input)) = c.getInput();
		*(const_cast<double*>(&_value)) = c.getValue();
	}
	return (*this);
}

Conversion::Conversion(void)
	:	_b(true), _input(""), _value(0.0) {}

Conversion::Conversion(const std::string& input)
	:	_b(true), _input(input), _value(0.0)
{
	char *ptr = NULL;
	*(const_cast<double *>(&_value)) = std::strtod(_input.c_str(), &ptr);
	// value가 0.0 이고, input 첫문자가 - , + 아님 에러
	if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])))
		_b = false;
	// 뒤에 문자가 있을 시, f 가 아님 에러
	if (*ptr && std::strcmp(ptr, "f"))
		_b = false;
}

Conversion::Conversion(const Conversion& c)
	:	_b(c.getBool()), _input(c.getInput()), _value(c.getValue()) {}

Conversion::~Conversion(void) {}

static void									printToChar(std::ostream& o, const Conversion& c)
{
	o << "char: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << IP;
	else if (std::isprint(c.toChar()))
		o << "'" << c.toChar() << "'" << std::endl;
	else
	 	o << NP;
}

static void									printToInt(std::ostream& o, const Conversion& c)
{
	o << "int: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << IP;
	else
		o << c.toInt() << std::endl;
}

static void									printToReal(std::ostream& o, const Conversion& c)
{
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
	{
		o << "float: " << c.toFloat() << "f" << std::endl;
		o << "double: " << c.toDouble() << std::endl;
		return ;
	}
	float f_buf;
	std::modff(c.toFloat(), &f_buf);
	if (c.toFloat() - static_cast<int>(c.toFloat()) == 0.0 || c.toFloat() == f_buf)
		o << "float: " << c.toFloat() << ".0f" << std::endl;
	else
	 	o << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << c.toFloat() << "f" << std::endl;

	double d_buf;
	std::modf(c.toDouble(), &d_buf);
	if (c.toDouble() - static_cast<int>(c.toDouble()) == 0.0 || c.toDouble() == d_buf)
		o << "double: " << c.toDouble() << ".0" << std::endl;
	else
		o << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << c.toDouble() << std::endl;
}

std::ostream&								operator<<(std::ostream& o, const Conversion& c)
{
	if (c.getBool())
	{
		printToChar(o, c);
		printToInt(o, c);
		printToReal(o, c);
	}
	else
		std::cout << "Error\n";
	return (o);
}
