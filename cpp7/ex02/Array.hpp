#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int					_size;
		T*								_data;

	public:
		class ex : public std::exception
		{
			public:
				const char* what(void) const throw() { return ("ERROR_[tyou_cpp07_ex02]"); }
		};
		unsigned int			size(void) const { return (_size); }

		T&						operator[](unsigned int i) const
		{
			if (i >= _size || i < 0)
				throw (ex());
			return (_data[i]);
		}

		Array&					operator=(const Array& a)//deep copy
		{
			if (this != &a)
			{
				if (_size)
				{
					delete[] _data;
					_data = NULL;
					_size = 0;
				}
				_size = a.size();
				if (_size)
					_data = new T[_size];
				for (unsigned int i = 0 ; i < _size ; ++i)
					_data[i] = a[i];
			}
			return (*this);
		}

		Array(const Array& a)
		: _size(a.size()), _data(NULL)
		{
			if (_size)
				_data = new T[_size];
			for (unsigned int i = 0 ; i < _size ; ++i)
				_data[i] = a[i];
		}

		Array(void)
		: _size(0), _data(NULL) {}

		Array(unsigned int n)
		: _size(n), _data(NULL)
		{
			if (_size > 0)
				_data = new T[_size];
		}

		~Array(void) { if (_data) delete[] _data; }
};

#endif