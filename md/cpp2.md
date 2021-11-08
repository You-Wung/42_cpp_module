# cpp2

#### 보너스 룰

- `From now on, each class you write MUST be in orthodox canonical form: At least one default constructor, a copy contructor, an assignation operator overload and a destructor. We won’t ask again.`

  ​		지금부터는 고전전인 form으로 클래스를 작성해야한다. 적어도 하나 이상의 default 생성자, 복사 생성자, 		연산자 오버로딩, 소멸자 -> [가이드](https://hysimok.github.io/posts/til2021/2021-02-28/)

---



### ex00:  My First Orthodox

​		file :  Makefile, main.cpp, Fixed.hpp and Fixed.cpp

 Please read this 3-page article ([1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html), [2](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html), [3](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)) to discover.
	1, 2, 3 페이지 읽어봐라.

it's safe to assume that integers and floating point numbers have opposite caracteristics. 

​		정수와 부동소수점은 다른 특징을 가지고있다.

You are going to discover a new and awesome number type: fixed point numbers!

​		새로운 숫자 데이터 타입을 발견하게된다 : fixed point numbers		 

Always missing from most languages scalar types, fixed point numbers offer a valuable balance between performance, accuracy, range and precision that explains why these numbers are widely used in graphics, sound or scientific programming to name a few.

​		대부분 스칼라 유형 언어 중에 없는, fixed point numbers는 성능, 정확도, 범위, 정밀도에 가치있는 균형을 유지한다. 그러한 이유로, 그래픽이나 사운드, 과학적 프로그래밍에 사용되는 것.

 As C++ lacks fixed point numbers, you're going to add them yourself today.

 I'd recommend [this](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html) article from Berkeley as a start. If it's good for them, it's good for you. If you have no idea what Berkeley is, read [this](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html) section of their wikipedia page.

---

​	Write an orthodox class to represent fixed point numbers: 

• Private members: 
		◦ An integer to store the fixed point value. 
		◦ A static constant integer to store the number of fractional bits. This constant will always be the litteral 8. 

• Public members: 
		◦ A default constructor that initializes the fixed point value to 0. 
		◦ A destructor. 
		◦ A copy constructor.
		 ◦ An assignation operator overload. `대입연산자 오버로드`
		 ◦ A member function int getRawBits( void ) const; that returns the raw value of the fixed point value. 
		◦ A member function void setRawBits( int const raw ); that sets the raw value of the fixed point value.

```cpp
//input
int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
```

```bash
//output
$> ./a.out
Default constructor called
Copy constructor called
Assignation operator called
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```

```c
정리
Fractional Bits가 8일 경우의 공식들
	정수 -> 고정소수값 (실수안되는 이유, float 형식 4바이트먹음)
		N << 8
  정수 || 실수 -> 고정소수값
		N * 256
	고정소수값 -> 정수값 || 실수
		fixed_point_number >> 8
		fixed_point_number / 256
	고정소수값 -> 실수
		(float)fixed_point_number / (1 << 8)
	 	(float)(fixed_point_number / 256)

##operator 연산자가 클래스 안에서 작동하는게 아니라 밖에서##
고정소수점(Fixed Point)방식은 소수점 이상/이하를 특정 비트로 딱 나눠서 처리합니다.
4바이트 float을 정수부(16비트) 실수부(16비트) 씩 나누거나 아님 정수부(8비트) 실수부(24비트) 이런식으로 나눌수 있는것입니다.
연산을 할때 정수부분보다 실수부분을 정밀하게 처리하도록 하고 싶다면 실수부분에 더 많은 비트를 할당할 수 있는것이지요.

그럼 12.34를 2바이트에 저장하고 정수부와 실수부는 각각 1바이트씩 표현한다고 했을때
12는 2진수 8비트로 표현하면
12/2 = 6 0
6/2  = 3 0
3/2  = 1 1
1/2  = 0 1
0000 1100 이렇게 8비트가 되고 (마지막부터 위로 올라가면서 비트 체크)

.34는 2진수 8비트로 표현면
0.34*2 = 0.68 0	| 0.1*2 = 0.2 0
0.68*2 = 1.36 1	| 0.2*2 = 0.4 0
0.36*2 = 0.72 0 | 0.4*2 = 0.8 0
0.72*2 = 1.44 1 | 0.8*2 = 1.6 1
0.44*2 = 0.88 0 | 0.6*2 = 1.2 1
0.88*2 = 1.76 1 | 0.2*2 = 0.4 0
0.76*2 = 1.52 1 | 0.4*2 = 0.8 0
0.52*2 = 1.04 1 | 0.8*2 = 1.6 1
0101 0111 이렇게 8비트가 됩니다. (순서대로 비트 체크)

이걸 합쳐서 0000 1100 0101 0111 하면 12.34의 2바이트(1:1) Fixed Point 표현방법이 되죠.
(앞에 부호비트는 걍 생략했습니다.) 참고로 부호비트는 0이면 양수 1이면 음수입니다.
  -------------------------------------------------------------
  virtual 소멸자
https://wonjayk.tistory.com/243 
```



### ex01 : Towards a more useful fixed point class

ex00 was a good start, but our class is still pretty useless, being only able to represent the fixed point value 0.0. Add the following public constructors and public member functions to your class:
`ex00은 value 0.0 만 가능하게되는 것. 새로운 public 생성자와 public 멤버함수를 추가해라`

• A constructor that takes a constant integer as a parameter and that converts it to the correspondant fixed(8) point value. The fractional bits value is initialized like in ex00. 

`생성자는 const int 형을 파라미터, static fixed 8비트`

• A constructor that takes a constant floating point as a parameter and that converts it to the correspondant fixed(8) point value. The fractional bits value is initialized like in ex00. 

`생성자는 const 소수을 파라미터롤 받고. fixed(8)point 값으로 바꿔짐`

• A member function float toFloat( void ) const; that converts the fixed point value to a floating point value. 

`float toFloat( void ) const;` `fixed point -> float`

• A member function int toInt( void ) const; that converts the fixed point value to an integer value.

`int toInt( void ) const;` `fixed point value -> int`

• An overload to the « operator that inserts a floating point representation of the fixed point value into the parameter output stream.

`<< 오버로딩해라. float 형 output`

```cpp
int main( void ) {
  Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
```

```
output
$> ./a.out
Default constructor called
Int constructor called
Float constructor called
Copy constructor called
Assignation operator called
Float constructor called
Assignation operator called
Destructor called
a is 1234.43
b is 10
c is 42.4219
d is 10
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
Destructor called
Destructor called
Destructor called
Destructor called
```

---

### ex02: Noew we're talking

 Add the following public member operator overloads to your class:

`뒤에 나오는 public 연산자 오버로딩을 너의 클래스의 추가해라`

• Six comparison operators: >, <, >=, <=, == and !=. `6개의 비교연산자 `

• Four arithmetic operators: +, -, *, and /. `4개의 계산 연산자`

• The pre-increment, post-increment, pre-decrement and post-decrement operators, that will increment or decrement the fixed point value from the smallest representable  such as 1 +  > 1.

`example: a++, ++a, --a, a-- 고정소수점 + 1 해주기`

---

Add the following public static member functions overloads to your class

`public static 멤버함수로 너의 함수에 추가하라`

• The static member function min that takes references on two fixed point values and returns a reference to the smallest value, and an overload that takes references on two constant fixed point values and returns a reference to the smallest constant value.

`static 멤버함수 min 은 2개 Fixed 레퍼런스로 받아서 작은 값을 리턴. 그리고, 오버로드해서 작은 상수값에 대한 참고를 반환`

• The static member function max that takes references on two fixed point values and returns a reference to the biggest value, and an overload that takes references on two constant fixed point values and returns a reference to the biggest constant value.

`static 멤버함수 max는 2개 Fixed 참조로 받아 큰 값을 리턴하고, 오버로드는 큰 Fixed 참조로 리턴한다.`

```cpp
int main( void ) {
  
}
//정리
멤버함수에 의한 오버로딩
 operator + 는 함수와 같이 간주
	c = a + b
	c = a.operator+ (b); 로 기술할 수도 있음
		• 객체 a의 멤버함수 operator + 를 호출하고 인수 b를 전달
```

```
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016

https://velog.io/@appti/CPP-Module-03-ex02
```

---

# 평가표

- ex00
  - 표준이되는 클래스 형식을 다루는 클래스를 소개한다.
    1. 기본 생성자
    2. 소멸자
    3. 복사 생성자
    4. 대입연산자 

