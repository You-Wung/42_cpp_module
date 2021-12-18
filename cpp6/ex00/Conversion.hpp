#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <cmath>//isnan isinf
# include <limits>
# include <iomanip>//setprecision
# include <iostream>
# include <string>

# define NP " Non displayable\n"
# define IP "impossible\n"
# define NANF "nanf\n"
# define NA "nan\n"

class Conversion
{
	private:
		bool								_e;
		const std::string					_input;
		const double						_value;

		Conversion(void);

	public:
		char								toChar(void) const;
		int									toInt(void) const;
		float								toFloat(void) const;
		double								toDouble(void) const;

		bool								getError(void) const;
		const double&						getValue(void) const;
		const std::string&					getInput(void) const;

		Conversion&							operator=(const Conversion& c);
		Conversion(const std::string& input);
		Conversion(const Conversion& c);
		~Conversion(void);
};

std::ostream&								operator<<(std::ostream& o, const Conversion& c);

#endif