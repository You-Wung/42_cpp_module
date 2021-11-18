

# cpp module 03

reference from [this](https://bigpel66.oopy.io/library/42/inner-circle/14)

## ex00

- ClapTrap 구현, main

## ex01

- 상속받는 ScavTrap 구현
- guardGate() 추가

### <span style="background-color:#ffdce0">업캐스팅</span>

업캐스팅이란 **자식 클래스의 객체가 부모 클래스 타입으로 형변환 되는 것**을 말한다. 

부모 클래스는 Person, 자식 클래스는 Student이다. 아래 코드에서 **Person p = s;** 부분이 업캐스팅한 부분이다. p가 Student 객체를 가리키지만, p는 Person 타입이기 때문에 Person 클래스의 멤버에만 접근이 가능하다. 

```java
public class Main{
	public static void main(String[] args){
		Student s = new Student("홍길동");
		Person p = s;	// 업캐스팅
		p.name = "이름이다.";

		p.check = "컴파일 에러 발생";	// 컴파일 에러 발생
	}
```

 

## <span style="background-color:#ffdce0">다운캐스팅(Downcasting)</span>

업캐스팅과 반대로 캐스팅 하는 것을 다운캐스팅이라고 한다. 업캐스팅된 것을 다시 원상태로 돌리는 것을 말한다. 하위 클래스로의 다운캐스팅을 할때는 타입을 명시적으로 지정해줘야한다는 특징이 있다.

아래 코드를 보면 **Student s = (Student)p;** 라고 나오는데 이 부분이 바로 다운캐스팅이다.

```java
public class Main{
	public static void main(String[] args){
		Person p = new Student("홍길동");
        
		Student s = (Student)p;	// 다운캐스팅
		s.name = "김유신";
		s.check = "check!";
	}
}
```

## <span style="background-color:#ffdce0">virtual</span>

​	실행시간(Runtime)에 함수의 다형성(Polymorphism)을 구현

​	다형성 : 하나의 객체가 여러 가지 타입을 가질 수 있는 것을 의미합니다. 자바에서는 이러한 다형성을 부모
​					클래스 타입의 참조 변수로 자식 클래스 타입의 인스턴스를 참조할 수 있도록 하여 구현하고 있습니다.

다형성 이용을 위해 부모 클래스의 포인터로부터 자식 클래스를 호출할 때, 가상 함수로 정의되지 않은 자식 클래스의 오버라이딩된 함수를 호출하면 부모 클래스의 멤버 함수가 호출된다. 소멸자도 자식 클래스에서 오버라이딩된 함수라고 볼 수 있기 때문에 만약 부모 포인터로 객체를 삭제하면 부모 클래스의 소멸자가 호출된다.

```cpp
class parent {
public :
    virtual void v_print()
        cout << "parent" << "\n";
    void print()
        cout << "parent" << "\n";
};
class child : public parent {
public :
    void v_print()
        cout << "child" << "\n";
    void print()
        cout << "child" << "\n";
};
int main() {
    parent* p;
    child c;
  
    p = &c;
    p->v_print();
    p->print();
}
-------------------------------------
  출력값
  	child
	  parent
```

​	v_print 함수는 가상 키워드로 선언되어 **가상 함수** 가 되었다. 가상함수가 아니라면, parent 객체이기 때문에
​	컴파일 시에 parent 클래스이 print()로 정해지진다. 벗, v_print()는 가상 함수이기 때문에, 런타임 중 결정되어
​	child 클래스의 v_print()가 실행된 것.

​	**가상함수** : 실행시간(Runtime) 에 그 값이 결정된다. (후기 바인딩 라고도함) 

##### virtual 키워드가 함수 앞에 붙으면, 업캐스팅 상황에서 업캐스팅 전 클래스의 오버라이딩된 함수를 찾는다. 없으면, 자기자신 호출. 있으면 업캐스팅 전 의 함수 호출.

## <span style="background-color:#ffdce0">virtual 소멸자</span>

 다형성 이용을 위해 부모 클래스의 포인터로부터 자식 클래스를 호출할 때, 가상 함수로 정의되지 않은 자식 클래스의 오버라이딩된 함수를 호출하면 부모 클래스의 멤버 함수가 호출된다.

소멸자도 자식 클래스에서 오버라이딩된 함수라고 볼 수 있기 때문에 만약 부모 포인터로 객체를 삭제하면 부모 클래스의 소멸자가 호출된다.

```cpp
class classA
{
public:
  classA();
  virtual ~classA();
};
class classB : public classA
{
public:
  classB();
  ~classB();
};
classA::classA()
{
  cout << "A" << endl;
}
classA::~classA()
{
  cout << "~A" << endl;
}
classB::classB()
{
  cout << "B"<< endl;
}
classB::~classB()
{
  cout << "~B" << endl;
}
int main()
{
  classB *B = new classB;
  classA *A = B;
  delete A;
  return 0;
}
---출력값---
 classA 소멸자에 virtual을 쓰지 않았을 때
A
B
~A
  classA 소멸자에 virtual을 사용했을 때
A
B
~B
~A
```

​	위 코드를 컴파일 할 때, B가 A로 업캐스팅 되었기 때문에, **B의 소멸자는 A소멸자**가 된다.
​	하지만,  **virtual 소멸자를 사용**하면, 

​		업캐스팅이 되었더라도 **B는 ClassB 의 인스턴스 이기 때문에 B 소멸자를 호출** 하게된다.

## <span style="background-color:#ffdce0">virtual 상속</span>

- 다중상속에서 다이아몬드 구조를 띄게 될 경우 데이터의 중복과 불필요한 생성자 호출을 막기위해 virtual inheritance(가상 상속)을 사용한다.

- 이러한 다중상속으로 인한 가상 상속은 기존 데이터 크기보다 더 커질 수 있으며, 성능 저하를 야기할 수 있다.

![1](https://t1.daumcdn.net/cfile/tistory/997279425AA73DCC0E)

###### 위: 다이아몬드 형태의 상속을 풀어서 그린 사진

![a](https://t1.daumcdn.net/cfile/tistory/99E87B465AA73F4004)

###### 위: 가상 상속을 했을 때 컴퓨터가 이해하는 것

![1](https://t1.daumcdn.net/cfile/tistory/9926DA3D5AA77FFA1A)

###### 위: 그 위의 사진을 자세하게 푼 것.(가운데 화살표가 없더라도 ClassA는 하나임 so, 어느 경로든 선택O)

​	A class가 가상상속을 했기 때문에 A는 가상의 class가 되어서 D class에서는 A class가 몇개인지 알 수 없음.
​	이럴때 D class는 A class를 1개로 인식을 해버린다. 실제론 다중 상속을 하고 있는 구조임.

