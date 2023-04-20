# vectorC
C언어를 이용하여 직접 벡터 (vector) 구조체를 구현한 코드입니다.

(참고 : https://aticleworld.com/implement-vector-in-c/)

***

## 개요
(sVector.c) C언어에서 사용되는 structure와 function pointer을 위주로 아래에 코드에 대한 자세한 설명을 첨가하였습니다.

(main.c) Vector 구조체를 이용한 알고리즘를 아래에 문제 설명과 해설을 첨부하여 구현해놓았습니다.

### Function Pointer
C/ C++과 python의 차이점 중 하나는 C/ C++은 Static Binding (Early Binding)을 따르는 반면 python은 Runtime Binding (Late Binding)을 따른다는 것입니다. Binding은 variables (변수), functions (함수)와 연관된 attribute (속성)들에게 값을 부여하는 작업입니다. 이름에서 알 수 있듯이 Static Binding (C/C++)은 compile time에 정적으로 값을 할당하는 반면 Runtime Binding (python)은 run time에 dynamic (동적)으로 값을 할당해줍니다. Runtime Binding이 overhead가 크다는 단점이 있지만 동적으로 작동되기 때문에 갖는 이점도 있습니다. C/ C++에서 Runtime Binding polymorphism (다형성)을 구현하는 방법이 Function Pointer입니다.


Function pointer이란, function (함수)의 주소값을 저장한 pointer (포인터)로서, 필요할 때마다 해당 함수를 부를 수 있도록 해주는 기법입니다. C언어에서 function pointer의 declaration (선언)은 다음과 같이 할 수 있습니다.

> Function_return_type (*Function_Pointer_name)(Function argument list);
>
> (예시) void (*fpData)(int);


C언어에서 function pointer의 assigning (할당)은 다음과 같이 할 수 있습니다.

> Function_Pointer = Function_Name; or &Function_Name;
>
> (예시) fpData = &Call_Back_Function;


C언어에서 function pointer의 call (호출)은 다음과 같이 할 수 있습니다.

> (*Function_Name)(Argument_List); or (); if argument list is empty
>
> (예시) (*fpData)(3)


C programming에서 function pointer을 활용하는 경우 중 하나는 call-back function을 코딩할 때 입니다. Call-back function와 같이 제 3자에 의해서 사용되는 경우가 많기 때문에 Runtime-Binding이 요구되며, 이 때문에 보통 library API를 통해 사용이 됩니다.


### int main(int argc, char *argv[])
C/ C++에서는 웬만해서는 또다른 .c 파일을 참조하지 않는 것이 좋습니다. Python과 같은 경우에는 "from Example import *" 등과 같이 또다른 python 파일을 import하는 경우가 많지만, C/ C++에서는 다음과 같은 이유로 사용하지 않는 편입니다.
1. 사소한 한 줄의 include가 파일 전체를 rebuild하는 결과를 가져와, 소모적입니다.
2. 굳이 include를 할 필요가 없다면, 파일들 간의 전체적인 구성이 잘 짜여있지 않는 한 뜻하지 않은 결함이 반드시 발생합니다.


C/ C++에서 int argc와 char *argv[]는 main 함수에 전달되는 command line arguments의 방식을 나타냅니다. argc (argument count)는 argument의 총 개수 + 1 (프로그램의 이름까지 더해줍니다.)이고, argv (argument vector)는 arguments를 담은 배열입니다.


### Dangling Pointer
[내용]


### 알고리즘 예시
(예제) 단변수 다항 방정식의 수치적 해법

(문제 설명) _a[n]*x^n + a[n-1]*x^(n-1) + ... + a[0] = 0_ 와 같은 단변수 x에 관한 다항 방정식의 해를 이분법을 이용하여 수치적으로 구한다. 추가적으로 [-L, L] 구간 내에 존재하는 해만을 구한다.

(풀이) 




### References
{function pointer : https://aticleworld.com/c-function-pointer/ }
{including another .c file : https://stackoverflow.com/questions/10448047/include-c-file-in-another }
{argc, argv : https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean }
