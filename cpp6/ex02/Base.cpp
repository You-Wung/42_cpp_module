#include "Base.hpp"

Base*										generate(void)
{
	std::random_device rd;// 시드값을 얻기 위함
	std::mt19937 gen(rd());// random_device 를 통해 난수 생성 엔진을 초기화
	std::uniform_int_distribution<int> dis(0, 2);// 난수열 균등 분포

	int i = dis(gen);
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
}

void										identify(Base* p)
{
	std::cout << "1: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

static void									goeasy(Base& p, int i)
{
	std::string s;
	try
	{
		if (i == 0)
		{
			(void)dynamic_cast<A&>(p);
			s = "A";
		}
		else if (i == 1)
		{
			(void)dynamic_cast<B&>(p);
			s = "B";
		}
		else if (i == 2)
		{
			(void)dynamic_cast<C&>(p);
			s = "C";
		}
		std::cout << s << "\n";
	}
	catch (std::exception&) { }
}

void										identify(Base& p)
{
	std::cout << "2: ";
	for (int i=0; i<3; i++)
		goeasy(p, i);
}
