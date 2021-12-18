# cpp module 06



## 보너스룰

각 문제에서, cast 하는 상황은 는 특정한 cast 로 해결된다. 



## Exercise 00: Scalar conversion

허용함수: string to int, float, double 변환함



char, int, float or double 타입 형식을 따르는, string을 파라미터로 받는 프로그램 작성.

10진수만.

int ex) 0, -43,  42
float ex) 0.0f, -4.2f, 4.2f	/	-inff, +inff, nanf 도 받음.
double ex) 0.0, -4.2, 4.2	/	-inf, +inf, nan 도 받음.

프로그램이 문자열의 타입을 찾아내서 문자열을 적절한 타입으로 변환해야한다.
3가지 타입으로 **명시적(explicit)** 으로 변환하고 아래와 같은 형식을 사용하여 결과를 표시.
변환이 불가능하거나, overflow가 있다면, 에러 출력. 헤더에 아무거나 추가가능

```cpp
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
  
./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```

```cpp
double std::strtod (const char *str, char **str_end);
double로 string을 변환시켜서 리턴. str_end는 마지막 문자를 지정해줄 수 있다.
 str_end 정상리턴 '\0', 비정상리턴 '\0'아님 그게 f가 아니라면, 
//https://en.cppreference.com/w/cpp/string/byte/strtof

```



## Exercise 01: Serialization

uintptr_t serialize(Data* ptr); 작성: integer type return 

Data* deserialize(uintptr_t raw); 작성: serialize 사용해  너가 생성한 raw data 데이터 구조로 반환합니다.

모든 것이 의도한 대로 작동한다는 것을 증명하는 프로그램으로 이 두 기능을 래핑하세요.
제대로 된 data structure 작성해야해.
data address 를 받아 serialize 를 그 위에 사용해.
리턴값을 deserialize 에 보내.
리턴값이 첫 포인터와 맞는지 확인해.
너가 사용한 Data Structure을 include 하는거 잊지마.



## Exercise 02: Identify real type

virtual 소멸자를 사용하는 Base 클래스 만듦. 빈 클래스 A, B, C  를 만들어.
Base에서 상속받음.

Base * generate(void);		: A,B,C 를 랜덤으로 인스턴스화하고, 인스턴스를 기준 포인터로 반환.  랜덤성을 위해 당신이 좋아하는 어떤 것이든 자유롭게 사용

void identify(Base* p);		: real Type p 의 따라서 A 인지 B 인지 C 인지 출력

void identify(Base& p);		: 포인터 함수 내에 사용하지마.  real Type p 의 따라서 A 인지 B 인지 C 인지 출력

이 함수들을  Wrap 해서 모든 것이 제대로 작동하는지 증명해. 

\<typeinfo\> 금지

