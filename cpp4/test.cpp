# include <iomanip>
# include <iostream>
# include <string>

void check(int *a)
{
	std::cout << "2: " << a << "\n";
}

int main()
{
	int *a = new int();
	std::cout << "1: " << a << "\n";
	check(a);
}