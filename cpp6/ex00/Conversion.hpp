#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <cmath>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>

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