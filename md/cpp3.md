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







