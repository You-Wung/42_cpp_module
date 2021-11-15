#include <iostream>
using namespace std;

class Base{
private:
	int a;
protected:
	int b;
public:
	int c;
};

class Derived : private Base //or protected Base or private Base
{

};

int main()
{
	Derived obj;

	cout << obj.c;
}
