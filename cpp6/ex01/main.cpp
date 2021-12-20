#include "Data.hpp"

int main()
{
	Data d1("p1", 100);
	uintptr_t a = serialize(&d1);

	Data d2 = *(deserialize(a));
	std::cout << "\nA_Address: 0x" << std::hex << a << "\n\n" << d1 << "\n\n" << d2 << "\n";
}