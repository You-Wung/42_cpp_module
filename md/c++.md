# C++

# 함수

---

### 함수의 기본 매개변수

```cpp
void test(int a, int b = 10)
```

​	매개변수가 들어오지 않았을 때, 기본적으로 들어가는 값 지정가능.

### 함수 오버로딩

```cpp
void test2(int a)
void test2(double a)
```

​	파라미터 형식이 다르면 오버로딩 가능. (리턴값 무관, 오버로딩 횟수 무관)

### 전역 스코프의 쉐도잉

​	전역 변수랑 같은 이름인 지역 변수 선언이 **지역변수가 전역변수를 가림.**
​	그래서, **범위 해결 연산자** 사용가능.	*::* 를 사용하면 전역변수를 뜻함.

# 클래스

---

### 타입을 이용해 인스턴스를 생성

​	타입*(클래스)*: 추상화 ex. 시계

​	인스턴스*(객체)*: 타입을 실제화 ex. 집에 있는 시계, 학교에 있는 시계

### 객체의 속성 == 데이터 멤버, 멤버함수

데이터 멤버 : 속성을 표현하기 위한 **변수**
멤버함수 : **기능의 모임**

|     타입     |   <->   |     클래스      |
| :----------: | :-----: | :-------------: |
| **인스턴스** | **<->** |    **객체**     |
|   **속성**   | **<->** | **데이터 멤버** |
|   **행위**   | **<->** |  **멤버 함수**  |

### 인스턴스화: 클래스 기반으로 인스터스를 만드는 것

````cpp
class Circle										//헤더
{
	private:
		double radius;							//데이터 멤버선언
	public:
		double getRadius() const; 	//멤버함수 const: 함수내부에서 어떠한 것 변경x
		void	 setRadius(double v); //멤버함수
};
````

| 접근 제한자 | 같은 클래스에서의 접근 | 서브 클래스에서의 접근 | 모든 곳으로부터의 접근 |
| :---------: | :--------------------: | :--------------------: | :--------------------: |
|   private   |           O            |           X            |           X            |
|  protected  |           O            |           O            |           X            |
|   public    |           O            |           O            |           O            |

private 라면 **맴버 함수를 통해서만** 접근
public 라면 **동일한 클래스 내부, 서브 클래스 내부, 애플리케이션에서** 접근

일반적으로 데이터 멤버에 접근해 작업 시, 어플맄케이션에서 맴버 함수를 사용할 수 있어야하기에 **일반적으로 public**으로 설정. (내부에서만 사용 시, private 가능)

```cpp
double Circle::getRadius() const
{
  return (radius);
}
```

### 객체 인스턴스화

```cpp
Circle circle1;
```

​	데이터 멤버를 초기화 하지 않았으므로, 쓰레기값 담겨져있음.

```cpp
circle1.setRadius(10.0);
```

​	이런 식으로의 데이터 멤버를 함수멤버로 초기화

### 생성자: 객체를 생성하기 위해 부르는 특별한 멤버 함수

1. 리턴값x
2. 생성자 이름 == 클래스
3. 생성자는 데이터 멤버를 초기화하는 작업을 하므로 **const** x
4. **기본 생성자는 별로 괄호 없이도 호출o**

```cpp
Circle::Circle()
: radius(1.0)//초기화 리스트
{
//내용
}
```

### 소멸자: 객체를 정리하는 작업을 하는 특별한 멤버 함수

1. 리턴값x
2. 소멸자 이름은 클래스 이름 앞에 **물결** 기호가 붙음
3. 객체가 스코프를 벗어나는 것과 같은 상황에 **자동호출**

```cpp
//소멸자 선언 예시
class Circle
{
	...
	public:
				~Circle();
}
//소멸자 정의
Circle::~Circle()
{
  //내용
}
```

---

### 기본적으로 데이터 멤버는 private 설정

​	데이터 멤버를 public 으로하면 멤버 함수 호출 없지 애플리케이션에서 데이터 멤버에 접근가능
​	그 자체로 **객체 지향 프로그래밍의 기본적인 개념에 어긋남**

​	***객체 지향 프로그래밍은 멤버 함수를 통해서 속성을 조작하는 것이 기본***

---

### 함수 assert <cassert>

​	매개변수가 true이면 아무 것도 하지 않지만, false 라면 프로그램을 종료

---

### 정적 (데이터 멤버) 변수 초기화

​	클래스 또는 모든 인스턴스에 포함되는 멤버
​	`int Circle::count = 0;`

### 정적 멤버 함수

​	모든 인스턴스나 클래스에 포함되며, 두 가지 방법으로 접근 가능

```cpp
circle1.getCount();
Circle::getCound();
```

​	인스턴스들은 존재하는 영역 (스코프) 가 지나면 삭제된다.

---

## C문자열

### 문자열 리터럴 사용한 문자열 생성

*c++는 문자열 리터럴을 상수가 아닌 포인터에 할당하는 것을 금지한다*

```cpp
char *str = "hello";			//error
char str[] = "hello"			//OK
const char *str = "hello"	//OK
  
char str[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // '\0' 넣어줘야함
```

### 힙 메모리에 생성 (delete필수)

```cpp
char* str = new char[3];				//그냥 문자열	
const char* str = new char[3];	//상수 문자		
```

문자열복사 : strcpy, strncpy
문자열탐색 : strstr
문자열비교 : strcmp, strncmp

## CPP문자열 <string>

### 	*cpp문자열은 null문자로 끝나지않는다*

1. 문자열의 길이는 capacity 보다 작거나 같음
2. 시작 위치의 인덱스 0
3. 끝 위치의 인덱스 size -1

 ```cpp
 string::size_type length;
 /*
 	size_type 은 unsigned int형
 	목적 1. 문자열의 인덱스
 	목적 2. 문자의 수
 */
 string::npos;
 /*
 	상수 npos(non-position) 는 size_type 자료형이고 -1 로 설정
 	npos는 존재하지 않은 인덱스를 나타낼 때 사용
 	"안녕하세요" 에서 '안'을 찾는다면 npos의 값은 0, '녕'을 찾는다면 npos는 1
 */
 ```

### cpp 생성자

`string str;` : 빈 문자열 객체 생성

```cpp
//매개변수 생성자, 마지막 널 문자 제외
string strg1(5, 'a');				//"aaaaa"
string strg2("hello");			//"hello"
string strg2("hello", 2);		//"he"

string strg(oldStrg);										//oldStrg 전체 복사
string strg(oldStrg, index, length);		//oldStrg 일부 복사
```

### 크기와 용적(capacity)

**c++ 문자열 객체는 힙에 문자 배열을 생성합니다.** 문자열 연산에 따라서 배열의 크기를 조절하는 경우에는 내부적으로 이루어진다. 하지만, 그 경우가 잦다면 시스템에 쓸데없는 오버헤드가 발생.

오버헤드 방지를 위해 시스템은 사용자가 사용할 문자열의 크기를 문자열의 크기보다 크게 예약기능.

```cpp
size_type n = str.size();				//문자열 크기 구하기			cout과 함께
size_type n = str.max_size();		//최대 크기 구하기

str.resize(n, 'c');							//문자열 크기 변경. 남는 부분 c 로채움
size_type n = str.capacity();		//capacity 
strg.reserve(n);								//용적 예약 (용적 늘리기 만 가능)
bool fact = str.empty();				//크기0 이면 true;

char c = strg[n];								//can change c
char c = str.at(n);							//same
```

- getline() <istream>

  ```cpp
  getline(cin, str);				//read by '\n'   
  getline(cin, str, 'c');		//read by  'c'
  ```

`str.substr(8); : 8번째부터 끝까지 된 문자열 리턴`
`str.substr(4, 12); : 4번쨰부터 12번쨰 까지 문자열 리턴`

### 문자탐색

​	`str.find, str.rfind : 정방향 문자탐색, 역방향 문자탐색 (문자중 하나만 찾으면 리턴)`

​	`find_first_of : 정방향 탐색함수, 문자집합 중 처음 등장하는 문자 인덱스 리턴 or npos`
​	`find_first_not_of : 정방향 탐색함수, 문자 집합에 없는 문자 인덱스 리턴 or npos`
​	`find_last_of, find_last_not_of`
​	위 함수들을 이용해 토큰화에 이용한다.

​	 `string::size_type wStart, wEnd` 같이 문자를 찾으며 그 위치를 저장하는 방식
​	npos는 형식 상 -1인데 unsigned int형이기에 언더플로 방지 차원으로,
​	(unsigned int 형의 최대값 -1) 이 된다.

### 문자열 비교

```cpp
int result = str.compare(pos1, n1, str2, pos2, n2); //c++ 문자열 2개
int result = str.compare(pos1, n1, str, n2); //c++ 1개 c 1개
//pos는 시작 위치를 지정하는 것이며, c++만 해줄수 있다.
//n은 끝 위치를 지정.
//같으면 0 다르면 non-zero + 구글.
//pos 나 n 없으면 첨부터 끝까지 비교.
c++문자열은 oper 연산자로 ascii 로 변환 후 비교가 가능하다.
```

---

### 문자열 수정

```cpp
str.push_back(c); : str 뒤에 c를 추가
str.append(tmp); : 뒤에 추가
str.insert(pos1, tmp); : 중간에 삽입(뒤로 밀려남)
str.replace(pos1, n1, tmp); : 대체하기
str.assign(tmp); : 문자열 자체를 tmp로 교체

str.clear(); : 문자열 전체제거
str.erase(pos, n) : 문자열 일부제거
```

### 문자열 출력

`cout << str1 + " " + str2 << end` :  `+`사용가능

# 객체지향

---

### 상속

​	protected, private 상속은 거의 사용되지 않는다. (다른 언어에서는 public 만 지원)

1. public

2. protected
   파생 클래스에서도 protected 데이터 멤버를 볼 수 있으므로, 직접 변경가능

3. private (default)

   베이스 클래스의 private 데이터멤버를 변경하려면 꼭 public 멤버함수를 이용해 변경가능

### 상속막기

​	*클래스 선언 시, 클래스 이름 뒤에 **final** 한정자를 붙임* (상속 후 추가상속 막기에도 사용가능)

### 상속유형

| 속성      | 클래스 내 접근 | 객체에서 접근 | 삭송받은 파생 클래스 내에서 접근 | 상속받은 객체에서 접근 |
| --------- | -------------- | ------------- | -------------------------------- | ---------------------- |
| private   | O              | X             | X                                | X                      |
| protected | O              | X             | O                                | X                      |
| public    | O              | O             | O                                | O                      |

- protected 사용되지않음.
- private 링크드 리스트로 코드 재사용만이 필요로할 때같이 특이한 케이스에만 사용됨.

### 소유

​	구조체 안에 다른 구조체가 있는 것 같은 개념.

### 구성

​	 생성자에서 같이 초기화 해주는 정도고, 데이터 멤버로 가지고있진 않다.

---

### virtual (가상함수)

​	파생 클래스에서 베이스 클래스에 있는 함수와 같은 이름의 함수를 선언 후 실행해보면
​	**베이스를 먼저 읽는다.** 그래서, virutal 을 클래스 함수멤버 선언부에 맨 앞에 붙인다.

​	그럼, **함수 이름이 같더라도 클래스 별로 다른 기능을 하는 함수를 구현**할 수 있다. 이 것이 **다형성**

- 가상 소멸자(다형성을 사용하는 케이스)

  ```cpp
  Person *ptr;
  ptr = new Person();//힙 할당
  delete ptr;//Person* 형이믐로 Person 제거
  
  ptr = new Student();//힙 합당
  delete ptr;//Person* 형이므로, Stduent 소멸자를 호출하지않고 Person 소멸자를 호출한다. 그러므로, Person 클래스의 소멸자는 virtual 이어야함.
  ```

### 바인딩

- 정적바인딩

  ```cpp
  person.print();
  student.printf();
  ```

  정확하게 컴파일러가 이해를 했기 때문에, 다형성 필도없고, 바인딩은 컴파일 시점에 이루어짐.

- 동적바인딩

  바인딩이 런타임 시점에 일어나는 바인딩이다. 뜻하는 객체가 어떤 객체인지 정확하게 모를 때.
  다형성을 발생 시킬 떄 동적 바인딩이 일어남. **다형성은 동적바인딩과 연관됨**

typeid 연산자 : 객체 자료형 확인

업캐스트 : 베이스 클래스 포인터에 파생 클래스의 객체를 넣은 것.

다운캐스트 : 파생 클래스 포인터에 베이스 클래스 객체를 넣는 것. 벝, dynamic_cast 연산자 필요

### 추상클래스

- *하나 이상의 **순수 가상 함수**를 포함하는 클래스*

- 선언

  ```cpp
  virtual double getArea() = 0;
  ```

- 정의

  상속하는 다른 클래스에서 순수 가상 함수를 정의 (추상 클래스는 순수 가상 함수를 정의하지 않음 or  다음 상속 단계로 넣길 수 있다)

- 특징
  1. 인스턴스화 불가 : 추상 클래스에는 **순수 가상 함수**의 대한 정의가 없기 때문
  2. 인터페이스 : 모든 멤버 함수를 **순수 가상 함수**로 갖는 경우
  3. 목적 : 파생클래스가 **모든 순수 가상 함수**를 구현하게 강제하는 것

### 다중 상속

​	*둘 이상의 클래스를 **베이스 클래스**로 만드는 상속* (데이터 멤버의 중복 시, 가상 베이스 구현)

### 가상 베이스 (다중 상속에서 중복으로 발생하는 문제 해결방법)

-  데이터의 멤버 중복 시, 가상 베이스 상속을 사용할 수 있음
  가상 베이스 사용하면, 꼭 누굴 통해가는 것이 아닌, 다이아몬드에서 최상위 클래스로 감

  즉, 파생 클래스에 베이스 클래스의 멤버가 직접들어가지 않는다.

- 가상 베이스 사용 시, *위임* 을 조심해야한다. 같은 print함수를 정의하고, 실행 시 print 함수가 3번 실행 될 수 도있기 때문에, 공통 데이터 멤버를 protected 로 설정하여, 모든 파생 클래스에서 접근할 수 있게하고, 위임이 있는 멤버 함수를 사용하지 않아야한다. 

### 믹스인 클래스 (다중 상속에서 중복으로 발생하는 문제 해결방법)

- **순수 가상함수** 를 가져서 인스턴스화 X, 벝 다른 클래스의 데이터 멤버를 추가해주는 클래스

---

## 객체의 역할

---

- ### 호스트객체

  호스트 객체는 함수 호출의 주체 (호스트 객체 == *this)
  **인스턴스 맴버 함수 내부에서는 자기 자신(호스트 객체)를 가르키려면 this 포인터를 사용해야함**

```cpp
void Fun::multiply()
{
	cout << num * 2;					//사용자가 작성한 코드
	coud << (this->num) * 2;	//컴파일러가 변환한 코드
}
```

- ### 객체 보호

  명시적으로 멤버 함수가 호스트 객체를 변경하지 못하게하려면 멤버 함수 뒤에 const 한정자 필요

- ### 매개변수 객체 : 매개변수로 전달된 객체를 의미

  1. 값 전달 (사용x)
  2. 참조로 전달
  3. 포인터로 전달

  ```cpp
  //객체보호 할 경우
  void Fun::two(const Type& para)
  {
  	...;
  }
  //호출
  fun1.two(para);
  ```

- ### 리턴 객체 : 생성자 소멸자 제외

  1. 값 전달 (사용x)
  2. 참조로 전달 `const Fun& Fun::two()`
  3. 포인터로 전달

  **리턴된 객체를 보호해야하는 경우 const 한정자를 붙인다**

- 연산자 오버로드 : 어떤 연산자를 사용해 어떤 처리를 할 수 있게 해주는 문법

### 연산자 오버로드 (멤버 함수로 오버로드, 비멤버 함수로 오버로드, 자료형 변환) - 생략

---

## try - catch 문

- try 절에는 프로그램을 중단시킬 가능성이 있는 코드
- catch 절는 예외발생 시 실행되며 코드를 계속해 진행
- throw 연산자
- 예외 처리를 위해서, throw 구문은 직접적, 간접적으로 try 구문 내부에 있어야함

```cpp
catch(...) //모든 자료형
```

- 꼭 예외처리를 함수 내부에서 할 필요x (에외 전파, 예외 전달)

### 스마트포인터를 사용하면 메모리 누수관련해서 효율적이다.

C 언어를 배우고 C++ 프로그래밍 하는 개발자가 흔히 저지르는 실수가 new 연산자가 메모리 할당을 실패했을 때 malloc과 동일하게 NULL 포인터가 반환된다고 생각하는 것입니다. 그러나, C++에서 new 연산자는 메모리를 할당할 수 없는 경우 예외를 던집니다.

---

#### exception도 클래스임 <stdexcept>

---

## 함수 템블릿 사용

```cpp
template<typename T, typename U, ..., typename Z>
T fun_name(U first, ... Z last)
```

< > : 함수 내부에서 사용할 자료형 목록의 심볼을 지정

 예제

```cpp
template<tyoename T>
T smaller(T& first, T& second)
{
	...//크기 비교, 변수 값스왑
}
```

배열출력 시

```cpp
template<typename T, int N>
void print(T(&array)[N]) //arrary는 변수이름
```

명시적 자료형 결정

```cpp
cout << smaller(23, 67.2); //int 와 double 이므로 안됨
cout << smaller<double>(23, 67.2) //OK
```

특수화

```cpp
template<typename T>
T smaller(T& first, T& second) { }
//이제 특수화
template<>
char *smaller(const char* const &first, const char* const &second) { }//특별한 타입 재정의
// const char *v : 메모리주소 변경X
// char* const v : 값 변경X
```

`함수 템블릿 오버로딩 가능`

---

## 클래스 템플릿

```cpp
template<typename T>
class Name
{
	private:
		T data;
	public:
		Name();
		void set(T data);
}
//구현
template<typename T>	//함수 정의할 때마다 쓰기
void name<T>::set(T d)//<T> 부분 필수.
{
	data = d;
}
int main()
{
  Name<int> n1(23);
  Name<char> n2('A'); 
}
```

- export

  **템플릿**은 클래스와 함수가 아니다. 클래스와  멤버 함수 정의 생성 방법을 컴파일러에게 알려주는 지시문.
  그래서, **템플릿**은 개별 컴파일 불가. 보통, 모든 템플릿 관련 정보를 헤더 파일에 넣고, 그 템플릿들은 사용하는 파일에
  그 헤더 파일을 포함 시키는것이다. export 를 모든 템플릿 선언 정의 앞에 붙이면된다. (보통 header 파일에 템플릿)

  **현재  export 는 오류 문제로 추천하지 않으므로, 템플릿 선언 시, 정의도 함께 하는 것을 추천**

- typedef

  ```cpp
  tyepdef stack<int> istack;
  tyepdef stack<double> dstack;
  ```

- 상속이 가능하나, 사용 거의 안함

---

- 스트림

  프로그램과 소스(키보드, 파일, 문자열) or 싱크(모니터, 파일, 문자열) 을 연결하는 중간다리가 있어야함. 이 것이 '스트림'

  **바이트열만 스트림 타고 이동 가능**

  - 특징
    1. 모든 스트림 객체들은 복사 생성자와 할당 연산자 제공X
    2. 참조로 전달 (복사 생성자 없기때문)
    3. 참조로 리턴을 사용 (복사 생성자 없기때문)
    4. 무조건 상태변화 만드므로 const X

- 콘솔 입출력

  iostate 이라는 자료형이 존재.

  `cin.get(char &c)` 

  `cin.getline(char *s, int n, char d = '\n')`

  ` cout.put(char c)`

- 파일스트림 <fstream>

  ```cpp
  ifstream inStream;//입력
  ofstream outStream;//출력
  fstream inOutStream;//입출력
  //파일열기
  inStream.open(const char* inFile, ...);	//이하동문
  //파일닫기
  inStream.close();	//이하동문
  //열렸나 확인
  inStream.is_open(); //bool 타입, 제대로 열렸나확인										
  ```

  예제 - 파일쓰기

  ```cpp
  ofstream outStrm;
  
  outStrm.open("test");
  if(!outStrm,is_open())
  		cout << "can't open\n";
  for(int i=0; i<10; i++)
  	outStrm << i << " ";
  ```

  예제 - 파일읽기

  ```cpp
  ifstream inStrm;
  int data;
  
  inStrm.open("test");
  if (!inStrm.is_open())
  		cout << "can't open\n";
  for(int i=0; i<10; i++)
  {
  		inStrm >> data;				//공백 전까지 읽음
  		cout << data << " ";
  }
  ```

- 파일스트림 열기모드 (열기모드 없으면, 기본모드)

  los::in	los::out	los::app etc.
  목적에 따라 다르게 열 수 있다.	*( | 으로 묶을 수 있다.*)

- 이진 입출력 : 텍스트가 아닌 데이터 처리 시, 이진 모드로 연다

---

### 문자열 스트림 

- 문자열 스트림의 데이터 소스와 싱크는 프로그램 내부에 있는 문자열
- 프로그램 내부에서 생성, 자동 소멸한다. 즉, 문자열 스트림에는 open(), close() 없다.
- istringstream <istream> : 추출
- ostringstream <ostream>: 삽입
- stringstream <iostream> : 삽입/추출

### 조정자는 사용자가 정의할 수 있다. (cout << func << "hi")

​	cout.setf, cout.unsetf

---

## STL

```cpp
//vector class
vector<int> vec;
vector<int>::iterator iter1;
vector<int>::reverse_interator iter2;

vec.push_back(정수);															//계속해서 뒤로 넣어줌
iter1 = vec.begin();														//첫번째 요소, rbegin()은 맨 뒤
++iter1;																				//두번째요소
vector<vector<int>> table(10, vetor<int>(10));	//int 2차원 배열

//deque class : 양쪽으로 추가가능
dep.push_front(value);	//벡터와 차이점
dep.pop_front();				//벡터와 차이점

//stack class : last_in_first_out
stack<char> stk;

stk.top(); stk.push(); stk.pop(); //size(), empty()

//queue class : first_in_first_out
큐접근 front(), back(), push(); pop();

//priority_queue class : 요소 잡인 시, 순위에 따라 요소를 꺼낼 수 있다.(push, pop, top)
//차이점: 얘는 관계 연산자를 지원하지 않는다.

//set class : 키라고 부르는 템플릿 자료형만 지정. 키는 오름차순으로만 정렬. 중복 허용X
set.begin(); end(); rbegin(); rend(); [첫소요 앞 가르킴]
count, find 등등 탐색 가능. (세트 set.at(n); 불가. 키를 사용해서 접근해야함)
  이 외에는 삽입, 제거
  
//map class (테이블, 딕셔너리, 애관배열 과 가능말임) : 키와 값을 쌍으로 갖는 요소 여러 개
map<string, int> scores;
map<string, int>::iterator iter;	//포지션
iter->first : string
iter->second : int
  while(cin >> str)
  {
    ++scores[str]; //str 을 가진 string 포지션의 int 값을 ++함.
  }

//STL 함수 for_each 
void print(int value)
	밸류 출력;
vector<int> vec;
vec.push_back(24); vec.push_back(25); vec.push_back(26);
for_each(vec.begin(), vec.end(), print);

//transform 알고리즘
코드는 위에서 연결됨
  transform(vec.begin(), vec.end(), vec.begin(), negate<int>()); //negate 객체 사용, 음수화

//비변경 알고리즘
cout << count(vec.begin(), vec.end(), 10); //10개 몇개나 있는지 
cout << count_if(vec.begin(), vec.end(), isEven); //짝수개수
for_each(vec.begin(), vec.end(), timesTwo); //2곱하기 

//변경 알고리즘
reverse(vec.begin(), vec.end()); //반전 벡터
rotate(vec.begin(), vec.end()); //회전
random_shuffle(vec.begin(), vec.end()); //랜덤 셔플

//정렬 알고리즘
sort(vec.begin(), vec.end()); //오름차순
sort(vec.begin(), vec.end(), greater<int>()); //내림차순

//이진 탐색 알고리즘
binary_search(vec.begin(), vec.end(), 10); //ture or false 리턴, 10이 있나없나.

//합집합 커맨드 : set_union (endIter 리턴)
//수치 알고리즘(수학적 계산)
int sum = accumulate(vec.begin(), vec.end(), 0); //합계

```

STL은 표준 템플릿 라이브러리이며, 현재까지 배운 개념들이나 알고리즘을 쉽게 구현할 수 있게 도와준다.









