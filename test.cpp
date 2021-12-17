# include <iomanip>
# include <iostream>
# include <string>
#include <typeinfo>

const std::string r = "Hello_World";

const std::string &check()
{
	return (r);
}
const std::string check2()
{
	return (r);
}
int main()
{
	const std::string s1 = "hello";
	const std::string s2 = "hello";
	const std::string s3 = "hello";

	std::cout << "1: " << &s1 << "\n";
	std::cout << "2: " << &s2 << "\n";
	*(const_cast<std::string *>(&s1)) = check();//LIKE string * something = &s3
	const_cast<std::string &>(s2) = check();//그냥 참조형으로하는거임
	//const_cast<std::string *>(s3) = check();
	std::cout << &s3 << "\n";
	std::cout << const_cast<std::string *>(&s3) << "\n";//LIKE string * something = &s3
	//conclusion
	//리턴이 참조형이든 아니든 상관없다.
	//위 28번줄은 포인터형식인 &s3의 주소를 나타내고 그래서 *를 밖에 하나 더 붙임
	//그리고, <>안에는 pointer-to-object 나 pointer-to-data-member 나 reference 있어야함
	//
    //const char * ptr = "hello";
	//char * c = const_cast<char *>(ptr);
	//위는 포인터 화살표를 바꿈
	std::cout << s1 << "\n";
	std::cout << const_cast<std::string &>(s2) << "\n";
	std::cout << "1: " << &s1 << "\n";
	std::cout << "2: " << &s2 << "\n";
	std::cout << s3 << "\n";
}