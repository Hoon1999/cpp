#include <iostream>
#include "time.h"

using namespace std;

int main() {
	/*
	* 1. 상속
	* 2. 다형상속(public 만)
	* 3. 동적 결합
	*/
	
	cout << "부모와 자식 클래스의 생성자 실행 순서를 알아봅시다." << endl;
	DerivedTime day1();
	DerivedTime day2(2, 40, 5);

	cout << "------------------------" << endl;

	day2.show();

	cout << "------------------------" << endl;

	/*
	* 동적 결합
	* 기본적으로 업캐스팅된 객체가 호출하는 메소드는 부모클래스의 메소드를 호출한다.
	* 대신 해당 메소드가 virtual로 선언되어 있고, 자식에서 오버라이딩 했다면,
	* 오버라이드 된 메소드가 호출된다. 이를 동적결합이라고 한다.
	* 
	* 어차피 재정의할 매소드들은 오버라이딩 해서 
	* 사용할텐데 이런거까지 알아야 하나 싶지만,
	* 이를 염두하지 않을경우 파괴자를 오버라이딩 하지 않는 일이 발생한다.
	* 파괴자를 오버라이딩 하지 않으면, 객체를 메모리 해제할 때
	* 자식클래스의 인스턴스를 부모클래스의 파괴자를 이용하여 메모리 해제하게 된다.
	* 이 경우 제대로된 메모리해제가 아니므로 문제가 발생한다.
	* 따라서 파괴자의 경우 잊지말고 virtual로 선언해야한다.
	*/

	Time* tp[3]; //time pointer
	tp[0] = new Time(1, 1);
	tp[1] = new DerivedTime(2, 2, 2);
	tp[2] = new Time(3, 3);
	cout << endl;

	for (int i = 0; i < 3; i++) {
		tp[i]->show(); 
		//부모 show() 의 virtual 키워드를 지우면 
		//자식 show()가 호출되지 않는 것을 확인할 수 있다.
	}
	cout << endl;

	// new 는 동적메모리 할당이다. 즉 메모리해제를 해줘야됨. c++ 은 gc가 없다.
	// 메모리 해제 키워드는 delete.
	for (int i = 0; i < 3; i++) {
		delete tp[i];
	}
	return 0;
}