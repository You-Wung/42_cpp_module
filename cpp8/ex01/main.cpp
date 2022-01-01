#include "Span.hpp"

//int main()
//{
//	Span sp = Span(5);
//	sp.addNumber(5);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//	std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//}
#include <random>
int main()
{
	std::random_device rd;// 시드값을 얻기 위함
	std::mt19937 gen(rd());// random_device 를 통해 난수 생성 엔진을 초기화
	std::uniform_int_distribution<unsigned int> dis(0, UINT32_MAX);// 난수열 균등 분포

	Span sp(UINT32_MAX);
	for (unsigned int i=0; i<10000; i++)
	{
		unsigned int z = dis(gen);
		sp.addNumber(z);
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}