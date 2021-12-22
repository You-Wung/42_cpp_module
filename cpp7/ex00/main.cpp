#include "whatever.hpp"
#include <typeinfo>

template <typename T>
static void test(T a, T b)
{
	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << min(a, b) << std::endl;
	std::cout << "max(a, b) = " << max(a, b) << std::endl;
	std::cout << "\n\n";
}

class Awesome
{
private:
	int _n;

public:
	Awesome(void) : _n(0) {}
	Awesome(int n) : _n(n) {}
	Awesome &operator=(Awesome &a) { _n = a._n; return *this; }
	bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
	bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
	bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
	bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
	bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
	bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
};
std::ostream &operator<<(std::ostream &o, const Awesome &a)
{
	o << a.get_n();
	return (o);
}

int main()
{
	{
		int a = 123, b = 256;
		test(a, b);
	}
	{
		char a = 53, b = 75;
		test(a, b);
	}
	{
		std::string a = "TEST", b = "T";
		test(a, b);
	}
	{
		double a = 5.1233, b = 5.562343245;
		test(a, b);
	}
	{
		bool a = true, b = false;
		test(a, b);
	}
	{
		Awesome a(2), b(4);
		test(a, b);
	}
}