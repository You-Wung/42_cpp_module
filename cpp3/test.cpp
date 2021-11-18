#include <iostream>
using namespace std;
class classA
{
public:
  classA();
    virtual ~classA();
	virtual void at() {cout << "hi A\n"; }
};
class classB : public classA
{
public:
  classB();
   ~classB();
	virtual void at() {cout << "hi B\n"; }
};
class classC : public classB
{
public:
  classC() {cout << "C" << endl; }
  ~classC() {cout << "~C" << endl;}
	 void at() {cout << "hi C\n"; }
};
classA::classA()
{
  cout << "A" << endl;
}
classA::~classA()
{
  cout << "~A" << endl;
}
classB::classB()
{
  cout << "B"<< endl;
}
classB::~classB()
{
  cout << "~B" << endl;
}
int main()
{
  cout << "START" << endl;
  classB *B = new classB;
  classA *A = B;
  A->at();
  delete A;
  return 0;
}