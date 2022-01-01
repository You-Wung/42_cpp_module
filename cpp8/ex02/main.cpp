#include "mutantstack.hpp"

#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <random>
#define LINE std::cout << "――――――――――――――――――――――――――――――" << std::endl;
MutantStack<int> mstack;

void cie(void)
{
	std::cout << "Const_interator\n";
	// std::stack<int>::container_type::iterator it(mstack.cbegin());
	MutantStack<int>::const_iterator it = mstack.cbegin();
	MutantStack<int>::const_iterator ite = mstack.cend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\t";
		++it;
	}
	std::cout << "\n";
}
void rie(void)
{
	std::cout << "Reverse_iterator\n";
	MutantStack<int>::reverse_iterator it = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\t";
		++it;
	}
	std::cout << "\n";
}
void rcie(void)
{
	std::cout << "Const_reverse_iterator\n";
	MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator ite = mstack.rend();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\t";
		++it;
	}
	std::cout << "\n";
}
int main()
{
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::random_device rd;													// 시드값을 얻기 위함
	std::mt19937 gen(rd());													// random_device 를 통해 난수 생성 엔진을 초기화
	std::uniform_int_distribution<int> dis(0, 100); // 난수열 균등 분포
	for (int i = 0; i < 100; i++)
		mstack.push(dis(gen));
	for (int i = 0; i < 98; i++)
		mstack.pop();

	LINE
	cie();
	LINE
	rie();
	LINE
	rcie();
	LINE

					std::cout
			<< "Iterator\n";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << "\t";
		++it;
	}
	std::cout << "\n";
	LINE
			std::stack<int>
					s(mstack);
	std::cout << "top of s is " << s.top() << "\n";
}