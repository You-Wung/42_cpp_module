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
static_cast : C++에서 제공하는 기능중 하나로 프로그래머가 형변환을 할 때 오류를 체크해 줍니다.
이 오류는 코드상에서 체크해줍니다. 마치 없는 변수나 함수를 사용자가 사용할 때 처럼 말이죠.

double std::strtod (const char *str, char **str_end);
double로 string을 변환시켜서 리턴. str_end는 마지막 문자를 지정해줄 수 있다.
 str_end 정상리턴 '\0', 비정상리턴 '\0'아님 그게 f가 아니라면, 
//https://en.cppreference.com/w/cpp/string/byte/strtof

try 속 첫번째 if
  value가 0.0 이고, input 첫문자가 - or + or 숫자가 아니면, 입력에러
try 속 두번째 if
  *ptr 값이 있는 것(숫자뒤 문자가있음), 그게 f 가 아니라면
  
throw 밑은 실행X

Nan(숫자가 아님), inf(무한대)
  
double modf(double value, double *iptr); 실수 값을 정수 부분과 소수점 부분으로 분할
float modff(float value, float *iptr); 실수 값을 정수 부분과 소수점 부분으로 분할

std::numeric_limits<T>::digits10
	10진수를 기반으로 변경되지 않고 나타낼 수 있는 숫자. 리턴. int같은경우 9인이유는 10숫자 꽉 채우면 9,999,999,999 같은거 표현못하기 때문.
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

* 직렬화, 역직렬화

  직렬화의 주된 목적은 객체를 상태 **그대로 저장**하고 필요할 때 다시 생성하여 사용하는 것

  - 직렬화: 객체를 바이트 스트림으로 바꾸는 것

  - 역질렬화: DB에서 바이트 스트림을 가져와 객체가 저장되었던 바로 그 상태로 변환하는 것

![](https://miro.medium.com/max/1258/0*adJu9E9hB0RPdoAW.png)

```cpp
1. uintptr_t 와 intptr_t 는 포인터가 참조하는 주소를 숫자로 저장하기 위해 이용

2. static_cast 는 형 변환 함수를 호출합니다. 원하는 형 변환 함수를 호출할 뿐이며, 함수가 없으면 에러 메시지를 호출(?)합니다.

3. static_cast 와 reinterpret_cast 의 차이
	int 5 를 static_cast<float> 하면 내부함수를 호출해 알아서 잘 바꿔준다.
	int 5 를 reinterpret_cast<float> 하면 0101(2) 비트가 그대로 float화가 되어 완전히 다른 숫자가 된다. ( https://blog.naver.com/wkdghcjf1234/220210906503 )
  결론: reinterpret_cast 는 low-level copy 이다.

 
reinterpret_cast 가지고 주소값을 가지고 노는게 아니라,
                                                                                "바이트 스트림으로 바꾸고(직렬화), 다시 원래대로 복구한다(역직렬화)" 라고 이해하면 될 듯
                                                                                	int a = 10;
	int b = 15;

	uintptr_t a1 = reinterpret_cast<uintptr_t>(&a);
	b = *(reinterpret_cast<int *>(a1));
                                                                                
위에서, a와 b의 "주소가 다른 것"은 당연하고, 값이 같지는 것이다.

```

## Exercise 02: Identify real type

virtual 소멸자를 사용하는 Base 클래스 만듦. 빈 클래스 A, B, C  를 만들어.
ABC는 Base 을 상속받음

Base * generate(void);		: A,B,C 를 랜덤으로 인스턴스화하고, 인스턴스를 기준 포인터로 반환.  랜덤성을 위해 당신이 좋아하는 어떤 것이든 자유롭게 사용

void identify(Base* p);		: real Type p 의 따라서 A 인지 B 인지 C 인지 출력

void identify(Base& p);		: 포인터 함수 내에 사용하지마.  real Type p 의 따라서 A 인지 B 인지 C 인지 출력

이 함수들을  Wrap 해서 모든 것이 제대로 작동하는지 증명해. 

\<typeinfo\> 금지

