#include "Karen.hpp"

int main()
{
	Karen k;

	k.complain("debug");
	k.complain("info");
	k.complain("warning");
	k.complain("error");
	std::cout << "\n";
	k.complain("error");
	k.complain("warning");
	k.complain("info");
	k.complain("debug");
}