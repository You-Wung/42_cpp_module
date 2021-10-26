# ex00: BraiiiiiiinnnzzzZ

`First, make a Zombie class. The zombies have a private name and are able to announce themselves like: `

​		첫 번째로, Zombie클래스를 만들어라. 좀비들은 private name 있고, 다음과 같이 짖을 수 있다.

`<name> BraiiiiiiinnnzzzZ...`

---

`Yes, announce( void ) is a member function. Also, add a debugging message in the destructor including de name of the Zombie.`

​		 announce(void)는 멤버함수다.  좀비 이름을 디버깅용 메세지로 소멸자에 추가하라.

`After this, write a function that will create a Zombie, name it, and return it to be used somewhere else in your code. The prototype of the function is:`

​		그 후, 새 좀비를 만드는 함수를 작성하라. 그 함수는 새 좀비를 리턴하고 너의 코드 어디선가 쓰일 것이다. 프로토타입 :

`Zombie* newZombie( std::string name ); `

---

`You will also have to write another function that will create a Zombie, and make it announce itself. The prototype of the function is: `

​		함수 하나 더 만드는데, 새 좀비를 만들고 추가로 짖는다.

`void randomChump( std::string name );`

---

`Now the actual point of the exercise: your Zombies must be destroyed at the appropriate time (when they are not needed anymore).`

​		이 문제의 point: 좀비들은 알아서 적절한 타이밍에 죽는다. (좀비들이 필요없어질 때)

`They must be allocated on the stack or the heap depending on its use: sometimes it’s appropriate to have them on the stack, at other times the heap may a better choice.`

​		좀비들은 스택이나 힙에 저장된다. 상황따라 잘 쓰길.

---

# ex01: Moar brainz!

`Re-using the Zombie class, now we are going to create an horde(무리) of zombies!`

`Write a function that takes an integer N. When called, it allocates N Zombie objects.`

​		int N  을 매개변수로 가지는 함수를 작성해. 호출 시, 좀비 오브젝트인 N에 할당된다.

`It must allocate all the N Zombie objects in a single allocation. Then, it should initialize each Zombie by giving to each one a name.`

​		그 것은, 모든 N Zombie objects 에 각자 할당해야함. 그 다음 각 좀비에게 이름을 지정하여 초기화해야함.

Last, it should return the pointer to the first Zombie. 

​	마지막으로, 첫 번째 좀비를 리턴해야한다.

`prototype: Zombie* zombieHorde( int N, std::string name );`

`Submit a main to test that your function zombieHorde works as intended.`
`You may want to do so by calling announce() on each one of the Zombies.`
`Do not forget to delete ALL the Zombies when you don’t need them anymore.`

```cpp
int *p = new int[5];
delete p;
//delete[] p;

가리키는 p 포인터는 결국 주소값이므로 delete나 delete[]나 상관 없지 않느냐는 질문의 의도이다.
그런데, 일단 결론부터 말하면 "상관이 있다"이다. 
4바이트 int 타입을 5개 생성하고 나서 메모리를 delete[]로 해제할 경우 각 배열의 요소를 4바이트씩 5번 해제하지만, delete만 사용하게 되면 4바이트짜리 메모리를 한 번만 해제한다.
-------------------------------------------------------------------------------------
ZombieHorde 가 멤버함수이어야하는 이유
  name 이 private 에 있기 때문에, 일반 함수로는 접근 및 변경이 불가능.
```

---

# ex02: HI THIS IS BRAIN

`Make a program in which you will create a string containing "HI THIS IS BRAIN".`

​		"HI THIS IS BRAIN" 이라는 문자열을 가진 프로그램을 만들어라.

`Create a stringPTR which is a pointer to the string; and a stringREF which is a reference to the string.`

​		만들어라. stringPTR  : 문자열 포인터, stringREF : reference(복제)

` Now, display the address in memory of the string. Next, display the address of the string by using stringPTR and stringREF.`

​		이제, 문자열의 메모리 주소를 출력해라. 그 다음, stringPTR, stringREF 의 주소를 출력하라.

`Last, display the string using the pointer, and finally display it using the reference.`

​		마지막으로 포인터 문자열을 출력하고, 참조를 이용해 문자열을 출력하라.

`That’s all, no tricks. The goal of this exercise is to make you demystify references.`
		목표: reference 개념을 바로잡기 위함
`It isn’t something completely new, it is just another syntax for something that you already know:addresses. Even there are some tiny-little-minuscule detail`
		이거 처음하는거 아니야. 

---

# ex03: Unnecessary violence

`Make a Weapon class, that has a type string, and a getType method that returns a const reference to this string. It also has a setType, of course! `

​		Weapon 클래스를 만들어. string 하나, getType 메소드(return: reference of string, setType 메소드(문자열 세팅)

`Now, create two classes, HumanA and HumanB, that both have a Weapon, a name, and an attack() function that displays:`

​		HumanA, HumanB 클래스 만들어. 둘 다 Weapon, name, attack() function 가지고있다. attack 출력 예:

`NAME attacks with his WEAPON_TYPE`

`HumanA and HumanB are almost-almost the same; there are only two tiny-little-minuscule details:`

​		휴먼A, B 는 거의 비슷해. 엄청 작은 두 가지 차이가 있다.

`•  While HumanA takes the Weapon in its constructor, HumanB doesn’t`

​		HumanA 생성자에서 무기를 얻고, HumanB 는 아니다.

`• HumanB may not always have a Weapon, but HumanA will ALWAYS be armed.`

​		HumanB 무기가 없을 수도 있다. 그렇지만, HumanA는 항상 무기를 가지고있다.

`Make it so the following code produces attacks with "crude spiked club" THEN "some other type of club", in both test cases:`

```cpp
int main()
{
		{		
				Weapon club = Weapon("crude spiked club");
				HumanA bob("Bob", club);
				bob.attack();
				club.setType("some other type of club");
				bob.attack();
			}
			{ 
				Weapon club = Weapon("crude spiked club");
				HumanB jim("Jim");
				jim.setWeapon(club);
				jim.attack();
				club.setType("some other type of club");
				jim.attack();
			} 
}
```

` In which case is it appropriate to store the Weapon as a pointer? And as a reference? Why? These are the questions you should ask yourself before turning in this exercise.`

​		이 경우에는 무기를 포인터로 하면 괜찮을까요? 아니면 reference로 하는게 괜찮을까요? 질문 입니다. 잘 생각해보세요.

[참조형 변수&](https://wiserloner.tistory.com/193)

```
*ptrval의 경우에는, 그냥 ptrval을 사용할경우 포인터변수로서 다른 주소값을 참조 가능하다.
예를들면, int b =1; 을 다시 선언하고, ptrval = &b; 라고 하면 해당 포인터변수가 b의 주소값을 가지게 된 것이다.

그리고 해당 주소값 안의 주소를 갖고오거나 조작하기 위해선, *ptrval = 10; printf(*ptrval);
과 같이 사용해야 했다.
-------------------------------------------------------
*ptrval의 경우는 ptrval = &a; ptrval = &b; 와 같이 주소값을 변화시킬수 있고, &val의 경우는
위와같이 주소값을 변화시킬수 없다. 즉 한번 주소값이 서로 연결되면 변경 불가능한 포인터 상수로,
그냥 해당 변수에 대한 '별명'을 지어준다고만 생각하면 된다.
```



---

# ex04: Sed is for losers

`Make a program called replace that takes a filename and two strings, let’s call them s1 and s2, that are NOT empty.`

​		replace 라고 불리는 프로그램을 만들어라. 프로그램은 filename 과 two strings 를 가지고있다. s1과 s2라고 부릅니다.

`It will open the file, and write its contents to FILENAME.replace, after replacing every occurrence of s1 with s2.`

​		파일을 open 할거야. FILENAME.replace after s1을 s2로 replace해라

`All the member functions of the class std::string are allowed, except replace. Use them wisely!`

​	replace 제외하고, 모든 멤버 함수는 std::string 허용. 현명하게 사용해

`Of course, you will handle errors as best you can. Do not use the C file manipulation functions, because that would be cheating, and cheating’s bad, m’kay?`

​		물론, 에러를 최대한 처리해야한다. C file manipulation function 사용하지마. 그건 치팅이야.

`You will turn in some test files to show your program works.`

​		test file 넣고, 잘 되는지 보여줘라

[guide](https://velog.io/@hidaehyunlee/CPP-01-%ED%8C%8C%EC%9D%BC-%EC%9E%85%EC%B6%9C%EB%A0%A5-%EB%B0%8F-%EB%AC%B8%EC%9E%90%EC%97%B4-%EC%B9%98%ED%99%98%ED%95%98%EA%B8%B0)

```
CPP에서는 close 함수를 꼭 쓰지 않아도 된다. 소멸자가 스택에 할당된 자원은 스코프가 끝나면 자동으로 해지되기 때문이다. 이를 객체지향 프로그래밍에서는 RAII(Resource Acquisition Is Initialization)라고 부른다고 한다.

std::ifstream 과 std::ofstream 을 사용하여, 파일을 열고 닫고 std::string::find, std::string::replace 를 통해서 문자열을 찾고 교체할 수 있다.

>> << 으로 파일을 읽고 쓴다. 
fin.eof() 로 파일이 끝났는지 알 수 있다.
```

---

# ex05: Karen 2.0

• "DEBUG" level: Messages in this level contain extensive contextual information. They are mostly used for problem diagnosis. Example: "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"

​		 DEBUG 레벨: 이 레벨의 메세지에는 긴 문자열이 들어가있다. 프로그램 진단용으로 사용된다.

• "INFO" level: These messages contain some contextual information to help trace execution in a production environment. Example: "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"

​		INFO 레벨: 메세지에는 trace execution 을 돕기위한 정보가 들어가있다.

• "WARNING" level: A warning message indicates a potential problem in the system. The system is able to handle the problem by itself or to proceed with this problem anyway. Example: "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."

​		WARNING 레벨: 주의 메세지는 시스템에 가능성이 있는 문제를 가르킨다. 시스템은 알아서 이 문제를 해결할 수 있다.

• "ERROR" level: An error message indicates a serious problem in the system. The problem is usually non-recoverable and requires manual intervention. Example: "This is unacceptable, I want to speak to the manager now."

​		ERROR 레벨: 에러 메세지는 시스템에 심각한 문제를 가르킨다. 쉽게 해결할 수 없고,  메뉴얼대로 처리가 필요하다.

`We are going to automate Karen, she says always the same things. You have to create a class named Karen which will contain the following private member functions:`

​		카렌을 자동화할거야. 그녀는 항상 같은 말만해. 너는 Karen 클래스를 만들고 private 멤버함수들 목록:

 • void debug( void );

• void info( void );

• void warning( void );

• void error( void );

`Karen also has to have a public function that calls to the private functions depending on the level that is passed as parameter. The prototype of the function is:`

​		카렌은 private 함수를 부르는 public 함수를 만들어야한다. 그것은 파라미터로 전달되는 level로 결정된다. 프로토타입:

void complain( std::string level ); 

`The goal of this exercise is to use pointers to member functions. This is not a suggestion, Karen has to complain without using a forest of if/elseif/else, she doesn’t hesitate or think twice!`

​		이번 목표는 포인터를 멤버 함수에 사용하는 것이다. 카렌은 불평을 if,else 문 많이 쓰지않고 해야함

`Submit a main to test that Karen complains a lot. It is okay if you want to use the complains we give as example.`

​		카렌의 불평을 테스트할 수 있는 main문을 제출해라. 우리의 example 대로 써도 괜찮다

# ex06:  Karen-filter

`We are going to implement a system to filter if what Karen says is actually important or not, because sometimes we don’t want to pay attention to everything Karen says.`

​		Karen 이 말한 것이 중요한 것이냐 아니냐에 따라 달라지는 필터링할 수 있는 시스템을 만들거임. 

`You have to write the program karenFilter that will receive as a parameter the log level you want to listen to and display all the info that is at this level or above it. For example:`

​		karenFilter 프로그램을 만들고, 파라미터로 너가 듣고싶은 log level  을 받고, 그 level info 나 그 레벨 위 info 를 모두 출		력해. 예:

```
$> ./karenFilter "WARNING"
[ WARNING ]
I think I deserve to have some extra bacon for free.
I’ve been coming here for years an you just started working here last month.
[ ERROR ]
This is unacceptable, I want to speak to the manager now.
$> ./karenFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

`There are many ways to filter karen, but one of the best ones is to SWITCH her off ;)`

​		필터링하는 많은 방법이 있지만, switch 문이 베스트

---

# 평가표

ex00

- newZombie 함수는 announce(), heap 할당 후 리턴

- randomChump 함수는 stack할당 후 announce()

ex01

- zombieHorde() 추가, new[] 를 사용해 heap에 할당

ex02

- string on stack, pointer, ref

ex03

- humanA 는 ref 가 필요. 생성할 때 같이 초기화되며, 소멸자 호출 시까지 변할 일 없기에 더 편함
- humanB는 pointer 필요. 생성할 때 필요초기화 안하며, 포인터 변경 가능성

ex04

- string, ifstream, fout 이용해 파일 읽고쓰기

ex05

- 
