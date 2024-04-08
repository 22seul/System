# 0409 - argc, argv 주제 발표
## PPT + 대본
> ![슬라이드1](https://github.com/22seul/System/assets/143988446/c54da26b-0cf7-495b-b535-5f33c23d76dd)
---
> ![슬라이드2](https://github.com/22seul/System/assets/143988446/3cab73b4-ad3a-4ee2-af2f-b31f14e9f547)
> * 먼저 argc, argv에 대해 설명하기 전에 간단한 단어들에 대해 설명하고 들어가겠습니다. 처음으로 명령행 인자(command line arguments)입니다. 보통 C언어 프로그램의 구조가 main함수에 인자가 없는 구조인데요, 오른쪽과 같이 인자를 넣어줄 수도 있습니다. 이러한 프로그램을 실행할 때 명령 프롬프트나 터미널을 통해 프로그램에 전달되는 인자 값을 명령행 인자라고 합니다. 그리고 이 인자들은 프로그램이 실행될 때 프로그램 이름 뒤에 공백으로 구분하여 입력합니다.
---
> ![슬라이드3](https://github.com/22seul/System/assets/143988446/44bd62bb-a07a-430f-bbca-578c151280dd)
> * 다음으로 argument와 parameter에 대해 간략히 설명해 보자면 일단 argument, 전달인자는 함수와 메서드를 호출할 때 실제로 전달되는 값을 의미하고, parameter, 매개변수는 함수나 메서드 정의에 사용되는 변수이고, 이 변수들은 함수가 실행될 때 필요한 입력 값의 ‘형식’을 정의합니다. 예시로 한번 보자면, int add(int a, int b)에서 a와 b는 parameter, add(3,5)에서 3과 5는 argument입니다. 요약하자면 argument는 호출 단계, parameter은 정의 단계라고 보면 좋을 것 같습니다.
---
> ![슬라이드4](https://github.com/22seul/System/assets/143988446/f693fc56-bb62-4be6-9c73-5c10918f210d)
> * main함수에서 명령행 인자를 전달받으려면 다음과 같이 첫 번째 인자 argc와 두 번째 인자 argv로 정의해야 합니다. Argc, argument count는 프로그램에 전달된 인자의 개수를 나타내고, 프로그램 이름 자체도 하나의 인자로 취급되기 때문에 값이 항상 1 이상입니다. 다음으로 argv, argument vector는 문자열 포인터의 배열로 실제로 전달된 인자들의 값을 담고 있습니다. index 0은 프로그램의 실행 경로를 나타내며, 1부터 시작하는 나머지 요소들은 사용자가 입력한 인자들을 순서대로 담고 있습니다
---
> ![슬라이드5](https://github.com/22seul/System/assets/143988446/730043f1-d2a2-43b5-aadd-fd7565034292)
> * 이제 실습을 해보겠습니다.
1.	mkdir ex1 - 일단 실습할 ex1 디렉토리를 만들어 보겠습니다.
2.	cd ex1 – 네, 디렉토리 들어가고
3.	vi test.c – test.c 파일을 작성해 주겠습니다.
4.	#include<stdio.h>
int main(int argc, char* argv[]){ - 일단 인자를 받기 위해 argument count, argument vector를 적고
5.	printf(“인자 수 : %d\n”,argc); - 인자 수 즉 argument count 의 값을 출력하도록 print문을 적어줍니다.
6.	for(int i=0;i<argc;i++)
printf(“argv[%d] : %s\n”,I,argv[i]); - 인자 수 만큼 argument vector안의 값을 출력하는 for문을 작성해 주고
7.	esc + :wq : 이제 저장하고 나가줍니다.
8.	make test : 저번주에 배운 make를 이용하여 컴파일 시켜 주고
9.	./test 시스템프로그래밍 화요일 5시부터 8시까지 – 제가 공백으로 나눠서 4개의 인자를 전달해 실행시켜 주겠습니다.
10.	그러면 이제 앞서 설명대로 argv[0]에는 프로그램 실행경로가 들어가게 되고, 1부터 4까지는 제가 전달한 인수들로 출력되는 것을 볼 수 있습니다.
---
> ![슬라이드6](https://github.com/22seul/System/assets/143988446/aab19727-0515-4e91-a871-09d1a328ee31)
---
