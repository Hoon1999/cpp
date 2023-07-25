#include <iostream>
#include "time.h"
/*
* 출력연산자 << 는 o stream 클래스에 구현되어 있다.
* 오버로딩을 ostream에서 직접 오버로딩을 해도 되겠지만,
* i/o stream은 c++ 표준이라서 하면 안된다고 한다.
* 
* 직접 오버로딩 외에도 firend를 사용한 오버로딩을 배웠으니
* friend를 사용해 오버로딩을 해본다.
* 
* i/o stream 은 i stream 과 o stream을 다중상속받은 클래스라고 한다.
*/


/* 헤더에 포함 될 프렌드
* friend std::ostream& operator<<(std::ostream& os, Time& t)
* 
* return 값이 ostream& 이 아닌 std::ostream& 인 이유
* 처음 공부할 때, 쉽게 이해하려고 :: 를 클래스의 멤버를 지칭하는 연산자라고 생각했다.
* 그래서 std 클래스의 멤버 ostream 클래스 라고 읽어서 이해를 못했다.
* :: 는 클래스 뿐만 아니라 scope 를 지정해주는 연산자로써
* std::ostream 은 std namespace 안의 ostream 클래스라는 의미이다.
* 즉 std는 클래스가 아니다.
*/
std::ostream& operator<<(std::ostream& os, Time& t) {
	os << t.hour << "시간 " << t.min << "분";
	return os;
}