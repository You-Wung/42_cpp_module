# cpp module 08

## Templated containers, iterators, algorithms

### Day Specific Rule

예외적으로 이전 서브젝트들과 달리 Modern C++을 허용한다.
STL에서 소개되는 Container, Iterator, Algorithm 모든 것을 허용한다.
물론 Module 08에서 STL을 최대한 지양하면서 코드를 완성해도 되지만,
서브젝트에서는 Modern C++의 기능과 STL을 적극 사용하는 것을 권장한다.

### 	STL( Standard Template Library)

위에서 말한 것처럼 STL은 Container, Iterator, Algorithm을 모두 포함한 개념.
템플릿을 적용한 라이브러리이므로, 임의의 타입에 대해서 Container, Iterator, Algorithm 지원.

## Exercise 00: Easy find

템플릿T 적용되고, T 와int 를 파라미터로 받는 easyfind 라는 함수 만들어.

T는 int의 컨테이너이고, 두번째 파라미터인 int형을 첫번째 컨테이너에서 찾는다.(처음으로 찾는 정수) 

찾을 수 없다면, exception 사용해서 에러 처리해. or 에러 값을 리턴해.

standard container 가 어떻게 작동하는지 알아보고 알아서해.

```cpp
STL
	- 임의 타입의 객체를 보관할 수 있는 컨테이너 (container)
		1. 배열 처럼 객체들을 순차적으로 보관하는 시퀀스 컨테이너 (sequence container)
				 벡터(vector) : 가변길이 배열
				 리스트(list) : 양방향 연결 구조를 가진 자료형
				 덱(deque) : 맨 뒤 원소와 맨 앞 원소 추가/제거 가능
				
		2. 키를 바탕으로 대응되는 값을 찾아주는 연관 컨테이너 (associative container)
		
	컨테이너에 보관된 원소에 접근할 수 있는 반복자 (iterator)
	
	반복자들을 가지고 일련의 작업을 수행하는 알고리즘 (algorithm)

```

## Exercise 01: Span

N ints 을 저장할 수 있는 Span 클래스 생성.

N is unsigned int.

생성자에서 파라미터로 받는다.

함수 addNumber : 숫자 추가가능. 이미 있는 숫자면 에러이고, 예외처리 되어야함.

함수 shortestSpan, longestSpan : 가지고 있는 숫자 중에 가장 차이가 작은숫자와 차이가 큰 숫자를 리턴. 만약 저장된 숫자가 없거나, 하나 밖에 없다면, throw exception.

최소 숫자 10,000 개 이상해야함.

iterator 이용해서, 숫자들을 넘겨줘 추가할 수 있다면 더 좋음.  

```cpp
//main
int main()
{
Span sp = Span(5);
sp.addNumber(5);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}
//output
$> ./ex01
	2
	14
$>
```

```cpp
capacity는 vector의 요소(element)들을 담을 수 있는 메모리가 할당되어 있는 공간의 용량이다.
size는 실제 유효한 요소(element)들의 갯수이다.
  
std::transform 이용 절대값 구하기.
https://stackoverflow.com/questions/35638832/stdabs-with-stdtransform-not-working

C++03까지의 STL에는 데이터셋에서 가장 작은 요소를 찾을 때는 min_element, 가장 큰 요소를 찾을 때는max_element를 사용하였습니다.
C++0x에서는 이런 불편함을 개선하기 위해 한번에 최소와 최고를 찾아주는 minmax_element 알고리즘이 새로 생겼습니다. ( https://jacking.tistory.com/1007 )
```



| format                                  | Description                                            |
| --------------------------------------- | ------------------------------------------------------ |
| vector<자료형> 변수명                   | vector 변수 생성                                       |
| vector<자료형> 변수명(숫자)             | vector 변수 생성 및 숫자만큼 size, 초기값 0            |
| vector<자료형> 변수명 = {x, y, z, ... } | vector 생성 후, 오른쪽 변수 x, y, z 등의 값으로 초기화 |
| vector<vector<자료형>> 변수명           | 2차원 벡터 생성(열과 행 모두 가변길이)                 |
| vector.assign(범위, 초기값)             | 범위만큼 초기값으로 초기화                             |

