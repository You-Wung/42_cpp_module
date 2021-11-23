C++ 04

<span style="background-color:#ffdce0">

##### cpp04 == 다형성을 이해하는 것

---

 canonical form

- default 생성자
- copy 생성자
- 대입연산자 오버로딩
- 소멸자

## <span style="background-color:#ffdce0">ex00: Polymorphism(다형성)</span>

모든 과제에서 너의 메인은 모든 것을 테스트해야한다.

생성자들과 소멸자들은 특정한 아웃풋이 있어야한다.

simple하고 complete base class, Animal 을 만들어라.

Animal의 protected 속성: `std::string type;`

Dog, Cat 만들어. 둘다 animal 상속해.

(for the animal class the type can be left empty or put at any value): animal 클래스는 type이 비어있거나 아무 값이나 넣을 수 있음.

모든 클래스가 그들의 이름을 type filed에 넣어야한다. Dog는 "Dog" 로.

모든 동물은 함수 makeSound() 가 있다.

그 함수는 standard outputs 으로 적절한 메세지를 출력한다.

```cpp
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
```

이 코드는 한 동물이 아니라 Dog와 Cat 클래스의 makeSound 함수안에 출력이 되어야함. 

확실히 하기위해 WrongCat 클래스 만들고 WrongAnimal을 상속하게해. 그리고, WrongAnimal의 makeSound()를 같은 조건 아래에서 실행해봐.

## <span style="background-color:#ffdce0">ex01: i don't want to set world on fire</span>

ex00 클래스들을 다시 사용해.

Brain이라는 클래스를 만들어.

Brain은 100크기의 std::String 배열을 가져. 이름은 ideas.

Dog, Cat은 private Brain* 을 가지게됨.

생성자에서 Dog와 Cat은 Brain* 을 new Brain()으로 초기화하고, 소멸자에서 delete함.

너는 메인에서 Dog로 Animal의 배열을 반 채우고, Cat이 나머지 반을 채워.

나가기 전에, 메인에세 루프를 돌면서 모든 Aminal을 delete해.

너는 직접적으로 Cat과 Dog을 Animal으로서 삭제해야해.

A copy of a Cat or Dog must be "deep". 고양이와 강아지의 복사는  deep이야

Your test should show that copies are deep! 테스트는 deep인걸 보여줘야해

각 클래스의 생성자와 소멸자는 특정 아웃풋이 있다. 

그리고, 적절한 소멸자를 호출해야함

```cpp
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;
```

### about deep copy

기본으로 생성되는 `Shallow copy` 는포인터 있을 때 복사는 하나 두번째 소멸자 호출시 에러발생.

delete 두번하기 때문에.

deep copy 뜻 : 멤버 뿐만 아니라 포인터로 참조하는 대상까지 복사함 (new 새로함)

## <span style="background-color:#ffdce0">ex02:abstract class</span>

일반 동물은 결국 말이 안 돼요.
예를 들어, 그것은 소리가 나지 않습니다!
미래의 실수를 피하기 위해, 기본 동물 클래스는 즉시 사용할 수 없어야 합니다.
실수로 동물 클래스를 인스턴스화하지 않도록 수정하십시오.
나머지는 이전과 같이 작동해야 합니다.

 Pure Virtual Function 은 아래와 같음 (헤더 안)

```cpp
virtual void pvf(void) const = 0;
```



 Pure Virtual Function을 갖고 있는 클래스는 파생 클래스에게 청사진을 제공하면서, 그 자체로는 객체로 이용할 수 없기 때문에 일종의 Interface로 동작한다. 이와 같은 클래스를 Abstract Class (추상 클래스)라고 부른다.

## <span style="background-color:#ffdce0">ex03:Interface & recap</span>

let’s try interfaces and recap everything!

Materias만들어라  Ice and Cure . 소문자로.

clone() 메소드는 새로운 Materia's 인스턴스가 리턴되야함

Regarding the use(ICharacter&) method, it’ll display:

• Ice: "* shoots an ice bolt at NAME *" *

*• Cure: "* heals NAME’s wounds *" 

(Of course, replace NAME by the name of the Character given as parameter.)

캐릭터는 최대 4개의 마테리아의 인벤토리를 가지고 있으며 시작 시 비어 있습니다. 

마테리아를 슬롯 0부터 3까지 순서대로 장착합니다.

우리가 마테리아의 전체 인벤토리를 갖추려고 하거나 존재하지 않는 마테리아의 사용/제거를 시도한다면, 아무것도 하지 마세요.

unequip()는 materia삭제 X

use(int, ICharacter&) method 가 idx 슬롯에서 마테리아를 사용.

target 을 파라미터로 AMateria::use 메소드로 전달

Character은 이름을 파라미터로 받는 생성자 필요. 

복사나 대입된 Character은 deep 이어야함.

Character의 old 마테리아는 삭제되어야함. 캐릭터 소멸할때도 같음.

learnMateria는 파라미터로 전달된 마테리아를 복사해서 메모리에 저장한다. cloned 나중에 하기위해.

112 / 5000

발음듣기Copy

Translate

자동완성Autocomplete

Korean열기/닫기 아이콘

캐릭터 와 마찬가지로 Source는 기껏해야 4개의 마테리아를 알 수 있는데, 이것은 필수X

createMateria(std::string const &) 는 새로운 마테리아를 리턴한다. 그 마테리아는 복사된 마테리아이다.(전 소스에서 배웠지?) 그 타입은 파라미터와 같다. 타입을 알수 없다면 0을 리턴.

간단: 너의 소스는 마테리아의 "템플릿"을 학생하고 필요에따라 다시 만들 수 있어야한다.

그러면 Real Type을 몰라도 마테리아를 만들 수 있고. 문자열만 식별하면된다.

```cpp
std::cout << "Copy Destructor\n";
std::cout << "Copy Constructor\n";
std::cout << "Default Constructor\n";
```

---

- AMateria → Interface of Cure & Ice

- Cure

- Ice

- ICharacter → Interface of Character

- Character

- IMateriaSource → Interface of MateriaSource

- MateriaSource

![image-20211121232338756](/Users/taewung/Library/Application Support/typora-user-images/image-20211121232338756.png)

요약

1. 사용자: Character
2. Character 은 Cure 나 Ice 소지 O
3. Character 는 equip, unequip, use 상호작용
4. Ice, Cure 생성을 위해서 MateriaSource를 이용해야한다.
5. MateriaSource를 이용하여 물질을 생성하기 전에 먼저 물질에 대한 learn 필요. 
6. 이를 위한 상호작용으로는 MateriaSource의 learnMateria와 createMateria가 있다.
