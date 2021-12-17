# cpp module 05

## <span style="background-color:#ffdce0">반복과 예외</span>

---

### Exercise 00: 엄마, 난 크면 공무원이 될 거에요

예외 클래스는 orthodox canonical form 필요X.
모든 다른 클래스들도 같은 방식.

우리는 사무실과 복도, forms, waiting in line 의 악몽을 만듦.

Bureaucrat클래스.

const name, grade 등급은 1등급(최상)부터 150등급(최하)까지.
이상한 grade 들어오면 throw an exception 해라. `Bureaucrat::GradeTooHighException` 아님`Bureaucrat::GradeTooLowException` 으로

getName getGrade 멤버 함수 만들어.

그리고 grade를 높이고 낮출 수 있는 함수. 그 함수들도 exception throw 아까처럼. (3에서 등급 올리면 2등급)

```cpp
try {
/* do some stuff with bureaucrats */
} catch (std::exception & e) {
/* handle
}
```

<< 오버라이딩 해서, ` <name>, bureaucrat <grade>` 같이 출력

```cpp
//what
what이라는 멤버 함수를 정의한 것을 볼 수 있는데,
이는 std::exception에서 정의된 virtual로 명시된 함수를 Overriding한 것이다.
이 때 what 함수의 원형을 통해 몇 가지 살펴볼 사항들이 있다.
//throw
throw는 런 타임에 이용되는 키워드이다. 반면에 함수 원형에 사용된 throw는 컴파일 타임에 이용되는 키워드이며, 이 때문에 throw()는 고유한 하나의 구문으로 이용된다. 따라서 함수 원형에서 throw()를 throw(void)와 혼동해선 안 된다.
//const_cast
const_cast는 포인터(pointer) 또는 참조형(reference)의 상수성(const)를 잠깐 제거해주는데 사용합니다.
```



### Exercise 01: Form up, maggots!

Form 클래스를 만들어.
name, boolean type(처음에 승인된 것인지 확인), grade(승인하기위한).
실행하기 위해 grade가 필요하다.

name과 grade는 const. 그리고 나머지는 모두 private임(protected ㄴㄴ)
grade 는 Bureaucrat 룰과 같고, 범위 벗어나면 똑같이 예외를 throw 한다.
Form::GradeTooHighException 혹은 Form::GradeTooLowException

이전과 똑같이, 우리는 getter 를 모든 attributes 를 위해 만들거고, <<오버로딩해서, 폼의 상태를 출력하라.

beSigned 함수 작성. (파라미터는 Bureaucrat) 그리고, Bureaucrat의 등급이 기준보다 높으면 승인하라. 1등급이 2등급보다 좋다는 것을 잊지마. grade가 너무 낮으면 Form::GradeTooLowException로 throw.

Bureaucrat에 signForm 함수 작성. 승인 제대로 되었다면, 출력 `<bureaucrat> signes <form>`
승인 안되었다면 출력 `<bureaucrat> cannot sign <form> because <reason>`

메인으로 테스트 해줘

### Exercise 02: No, you need Form 28B, not 28C

구체적인 폼들을 만들거야.

- ShrubberyCreationForm (Required grades: sign 145, exec 137)
  - Action: Create a file called _shrubbery, and write ASCII trees inside it, in the current
    directory. 파일 _shrubbery를 생성해서, ASCII trees 를 안에 만들어. 현재 디렉토리안에
- RobotomyRequestForm (Required grades: sign 72, exec 45). 
  - Action: Makes some drilling noises, and tell us that  has been robotomized successfully 50% of the time. Otherwise, tell us it’s a failure. 어떤 drilling noises 를 만들고 이것이 성공적으로 50% 로봇화가 성공했다고 말해주거나, 아님 실패했다고 말해줘.
- PresidentialPardonForm (Required grades: sign 25, exec 5). 
  - Action: Tells us has been pardoned by Zafod Beeblebrox 우리에게  Zafod Beeblebrox 덕분에 용서되었다고 말해줘

얘네들은 호직 하나의 파라미터를 가져. 그건 폼을 가르킬거야. 예를 들어, 너가 shrubbery를 키우고싶다면 기억해. 그  form의 속성들은 base class 에 private로 남아있어

execute(Bureaucrat const & executor) const 라는 함수를 base form에 추가해. 구체적인 폼들 안에서 실행되는 form action 을 implement해라. 너는 그 폼이 승인됬는지 체크해야하고. grade가 충분하지 않아서 거절된다면 적절한 expection을 throw해라. 

구체적인 폼 클래스에서 이러한 검사들을 할지아니면,  기본 클래스에서 설정한 후 다른 메소드를 실행할지는 너 마음이야. 둘 중 하나가 더 이상적인 방법이야. 근데, 어떠한 경우에도, bass class는 추상클래스여야해.

bureaucrat에 executeForm(Form const & form)를 추가해. 그건 form를 실행하려는 시도를 해야해. 성공했다면, `<공무원> excuses <form>`을 실행하고 아니면, 에러 메세지 출력해.

```cpp
dynamic_cast 의 피연사자는 다형 클래스여야한다.
다형 클래스는 virtual 을 붙여 가상함수테이블에 추가가 되기 때문에, 그 후 변환이 가능

상수생성 https://modoocode.com/304
```



### Exercise 03: At least this beats coffee-making

인턴을 뽑아서 일을 시키자!

Intern 클래스 만들어. 인턴은 이름이 없고, 등급도 없고, 특징도 없고, 그냥 일에만 신경써.

인턴이 가진 makeForm 함수는 중요해. 이건 두개의 문자열을 파라미터로 가지고있어. 첫번째 문자열은 form의 이름을 뜻하고. 두번째 문자열은 form의 대상이야. 이건 form을 포인터식으로 리턴해. 

a pointer to whichever concrete form class is represented by the first parameter, initialized with the second parameter. 
첫번째 파라미터로 구체적 폼을 표현하고, 두번째 파라미터로 초기화한다.

이건 `Interm creats <form>` 같이 출력해야하고. 만약에 if/elseif/elseif/else 같이 못생기게 함수 작성하면 넌 평가에서 탈락이야. 전달된 폼이 없는거면 에러메세지를 출력해.

```cpp
Intern someRandomIntern;
Form* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
```

이건 Bender 타겟인 RobotomyRequestForm 폼을 만들어야해.

![스크린샷 2021-12-17 18.34.37](/Users/taewung/Desktop/스크린샷 2021-12-17 18.34.37.png)

