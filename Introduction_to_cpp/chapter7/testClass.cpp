#include <iostream>
#include "testClass.h"
using namespace std;
//사용범위 결정 연산자 :: 를 이용하여 구현한다.
void testClass::show() {
	cout << "i * f = " << square << endl;

}
testClass::testClass(int memi, float memf) {
	this->memi = memi;
	this->memf = memf;
	square = calc_squ();
	// this 가 포인터라는 개념을 공부하기 전에 이미,
	// 생성자에서 this를 java에서 사용하듯 this.memi, this.memf 로 작성하려고 하니 visual studio가
	// 자동으로 간접멤버연산자( -> )로 정정해주었다. 이 말은 즉 this는 무언가의 포인터라는 것을 알 수 있다.
	// 그 다음 코드를 실행하면 정상적으로 작동하는것을 보아 this는 현재 클래스의 주소값을 갖는 포인터임을 알 수 있었다.
}
testClass ::~testClass() {}; 

// 으레 그렇듯 클래스를 매개변수와 리턴값으로 사용할 수 있다.
// 리턴 값으로 사용하려면 자료형 자리에 클래스명을 넣으면 된다. 당연하다.
// 매개변수로 사용할 때는 & 기호를 넣는다.
// 예를들어 aClass 의 메소드가 bClass 를 매개변수로 받고, bClass를 리턴한다면 아래처럼 작성한다.
// bClass aClass::aMethod(bClass& i) {return i;} 
// 하지만 굳이 bClass를 aClass에서 처리를 할 필요는 거의 없을것이다. 딱 보기엔 결합도가 안좋을것 같다.
// 그러면 보통 aClass 메소드가 aClass를 매개변수로 받아서 aClass 로 리턴을 해줄것이다. 그럼 아래처럼 작성한다.
// aClass aClass::aMethod(aClass& i) {return i;}
// 만약 return 값으로 this를 준다면?? *this로 주어야 한다.
// 왜냐?? return 자료형은 aClass 인데, this는 aClass의 포인터이기 때문이다.
