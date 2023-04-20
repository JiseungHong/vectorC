# vectorC
C언어를 이용하여 직접 벡터 (vector) 구조체를 구현한 코드입니다.

(참고 : https://aticleworld.com/implement-vector-in-c/)

***

## 개요
(sVector.c) C언어에서 사용되는 structure와 function pointer을 위주로 아래에 코드에 대한 자세한 설명을 첨가하였습니다.

(main.c) Vector 구조체를 이용한 여러 가지 알고리즘를 아래에 문제 설명과 해설을 첨부하여 구현해놓았습니다.

### Function Pointer
C/ C++과 python의 차이점 중 하나는 C/ C++은 Static Binding (Early Binding)을 따르는 반면 python은 Runtime Binding (Late Binding)을 따른다는 것입니다. Binding은 variables (변수), functions (함수)와 연관된 attribute (속성)들에게 값을 부여하는 작업입니다. 이름에서 알 수 있듯이 Static Binding (C/C++)은 compile time에 정적으로 값을 할당하는 반면 Runtime Binding (python)은 run time에 dynamic (동적)으로 값을 할당해줍니다. Runtime Binding이 overhead가 크다는 단점이 있지만 동적으로 작동되기 때문에 갖는 이점도 있습니다. C/ C++에서 Runtime Binding polymorphism (다형성)을 구현하는 방법이 Function Pointer입니다.


Function pointer이란, function (함수)의 주소값을 저장한 pointer (포인터)로서, 필요할 때마다 해당 함수를 부를 수 있도록 해주는 기법입니다. C언어에서 function pointer의 declaration (선언)은 다음과 같이 할 수 있습니다.


> Function_return_type (*Function_Pointer_name)(Function argument list);
> (예시) void (*fpData)(int);


C언어에서 function pointer의 assigning (할당)은 다음과 같이 할 수 있습니다.


> Function_Pointer = Function_Name; or &Function_Name;
> (예시) fpData = &Call_Back_Function;


C언어에서 function pointer의 call (호출)은 다음과 같이 할 수 있습니다.


> (*Function_Name)(Argument_List); or (); if argument list is empty
> (예시) (*fpData)(3)



(참고 : https://aticleworld.com/c-function-pointer/)