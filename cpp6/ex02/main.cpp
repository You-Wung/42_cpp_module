#include "Base.hpp"

int main()
{
	for (int i = 0 ; i < 10 ; ++i)
	{
		Base*		base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
}