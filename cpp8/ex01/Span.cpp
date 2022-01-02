
#include "Span.hpp"

void										Span::addNumber(unsigned int value)
{
	try
	{
		if (_data.size() == _data.capacity())
			throw (std::exception());
	}
	catch (std::exception)
	{
		ERR << "data is fully packed\n" << OG;
	}
	for (auto it = _data.begin(); it != _data.end(); it++)
	{
		if (value == static_cast<unsigned int>(*it))
			throw (std::exception());
	}
	_data.push_back(value);
}

unsigned int								Span::shortestSpan(void)
{
	try
	{
		if (_data.size() < 2)
			throw (std::exception());
	}
	catch (std::exception)
	{
		ERR << "Size is not big enough\n" << OG;
	}
	std::vector<unsigned int> diff(_data);
	std::sort(std::begin(diff), std::end(diff));// 오름차순
	std::adjacent_difference(std::begin(diff), std::end(diff), std::begin(diff));
	int (*abs)(int) = &std::abs; 
	std::transform(std::begin(diff), std::end(diff), std::begin(diff), abs);// 함수포인터 int, 매개변수가 int인
	return ((*std::min_element(std::begin(diff), std::end(diff))));
}

unsigned int								Span::longestSpan(void)
{
	try
	{
		if (_data.size() < 2)
			throw (std::exception());
	}
	catch (std::exception)
	{
		ERR << "Size is not big enough\n" << OG;
	}
	auto p_iter = std::minmax_element(std::begin(_data), std::end(_data));
	return (*(p_iter.second) - *(p_iter.first));
}


Span&										Span::operator=(const Span& s)
{
	if (_data.capacity() != s.getData().capacity())
		return (*this);
	if (this != &s)
	{
		_data.clear();
		_data.reserve(s.getData().capacity());
		std::copy(std::begin(s.getData()), std::end(s.getData()), std::back_inserter(_data));
	}
	return (*this);
}

Span::Span(void)
	:_data(0, 0)
{
	_data.reserve(0);
}

Span::Span(unsigned int n)
	:	_data(0, 0)
{
	_data.reserve(n);
}

Span::Span(const Span& s)
	:	_data(0, 0)
{
	_data.reserve(s.getData().capacity());
	std::copy(std::begin(s.getData()), std::end(s.getData()), std::back_inserter(_data));
}

Span::~Span(void) {}