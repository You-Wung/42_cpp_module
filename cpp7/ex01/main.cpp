#include "iter.hpp"

class Awesome {
	public:
		Awesome(void) : _n(42) { return ; }
		int get (void) const { return this->_n; }
	private:
		int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome &rhs)
{
	o << rhs.get();
	return o;
}
template <typename T>
void print (T const &x)
{
	std::cout << x << std::endl; return ;
}
int main()
{
	int tab[] = {0, 1, 2, 3, 4};
	Awesome tab2[5];
	iter(tab, 5, print);
	iter(tab2, 5, print);
}

//int main(void)
//{
//	std::cout << "\nString\t";
//	std::string	s[4] = {"tyou", "cpp", "mod", "07"};
//	iter(s, sizeof(s) / sizeof(*s), print);

//	std::cout << "Int\t";
//	int			i[4] = {0, 1, 2, 3};
//	iter(i, sizeof(i) / sizeof(*i), print);

//	std::cout << "Double\t";
//	double		d[5] = {0.0, 1.1, 2.2, 3.3, 4.4};
//	iter(d, sizeof(d) / sizeof(*d), print);

//	std::cout << "Char\t";
//	char		c[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
//	iter(c, sizeof(c) / sizeof(*c), print);
//}