#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "wrong argument\n";
		return (0);
	}
	std::string line;
	std::string filename = av[1];
	std::ifstream fin(filename);
	std::ofstream fout(filename + ".replace");
	if (fin.fail())
	{
		std::cout << "failed to open\n";
		return (0);
	}
	while (!fin.eof())
	{
		fin >> line;
		size_t t = line.find(av[2]);
		if (t != std::string::npos)
			line.replace(t, strlen(av[2]), av[3]);
		fout << line;
		if (!fin.eof())
			fout.put('\n');
	}
	fin.close();
	fout.close();
}