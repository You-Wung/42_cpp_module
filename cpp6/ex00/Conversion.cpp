
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

bool										Conversion::getError(void) const
{
	return (_e);
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
		_e = c.getError();
		*(const_cast<std::string*>(&_input)) = c.getInput();
		*(const_cast<double*>(&_value)) = c.getValue();
	}
	return (*this);
}

Conversion::Conversion(void)
	:	_e(false), _input(""), _value(0.0) {}

Conversion::Conversion(const std::string& input)
	:	_e(false), _input(input), _value(0.0)
{
	try
	{
		char		*ptr = NULL;
		*(const_cast<double*>(&_value)) = std::strtod(_input.c_str(), &ptr);
		if (_value == 0.0 && (_input[0] != '-' && _input[0] != '+' && !std::isdigit(_input[0])))
			throw (std::exception());
		if (*ptr && std::strcmp(ptr, "f"))
			throw (std::exception());
	}
	catch (std::exception &)
	{
		_e = true;
	}
}

Conversion::Conversion(const Conversion& c)
	:	_e(false), _input(c.getInput()), _value(c.getValue()) {}

Conversion::~Conversion(void) {}

static void									printToChar(std::ostream& o, const Conversion& c)
{
	o << "char: ";
	if (std::isnan(c.getValue()) || std::isinf(c.getValue()))
		o << IP;
	else if (std::isprint(c.toChar()))
		o << "'" << c.toChar() << "'" << std::endl;
	else
	 	o << NP << std::endl;
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
	double d_buf;
	std::modf(c.toDouble(), &d_buf);
	if (d_buf == 0.0 || c.toDouble() == d_buf)
		o << "float: " << c.toFloat() << ".0f" << std::endl;
	else
	 	o << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << c.toFloat() << "f" << std::endl;

	float f_buf;
	std::modff(c.toFloat(), &f_buf);
	if (f_buf == 0.0 || c.toFloat() == f_buf)
		o << "double: " << c.toDouble() << ".0" << std::endl;
	else
		o << "double: " << std::setprecision(4) << c.toDouble() << std::endl;
	o << std::numeric_limits<int>::digits10 << "\n";
}

std::ostream&								operator<<(std::ostream& o, const Conversion& c)
{
	if (c.getError())
	{
		o << "Converting Failed (Bad Alloc)" << std::endl;
		return (o);
	}
	printToChar(o, c);
	printToInt(o, c);
	printToReal(o, c);
	return (o);
}
