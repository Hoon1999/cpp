#include <iostream>
#include "time.h"

using namespace std;

Time::Time() {
	hour = min = 0;
	cout << "Time() 생성자가 실행됨" << endl;
}
Time::Time(int h, int m) {
	hour = h;
	min = m;
	cout << "Time(int, int) 생성자가 실행됨" << endl;
}
void Time::addHour(int h) {
	hour += h;
}
void Time::addMin(int m) {
	min += m;
	hour = min / 60;
	min %= 60;
}
Time Time::sum(Time& t) {
	Time sum;
	sum.hour = hour + t.hour;
	sum.min = min + t.min;

	sum.hour = sum.hour + sum.min / 60;
	sum.min = sum.min % 60;

	return sum;
}
Time Time::operator+(Time& t) {
	// + 연산자 오버로딩.
	// 구현부는 sum과 완벽하게 동일함.
	Time sum;
	sum.hour = hour + t.hour;
	sum.min = min + t.min;

	sum.hour = sum.hour + sum.min / 60;
	sum.min = sum.min % 60;

	return sum;
}
void Time::show() {
	cout << hour << "시간 ";
	cout << min << "분" << endl;
}
int Time::getHour() {
	return hour;
}
int Time::getMin() {
	return min;
}
Time::~Time() {
}

DerivedTime::DerivedTime() : Time() {
	//만약 : Time()을 작성하지 않는다면,
	//부모 생성자가 먼저 실행 된 후, 자식 생성자가 실행됨.
	//여기 블록은 그렇게 되도 딱히 상관이 없다.
	sec = 0;
	cout << "DerivedTime() 실행됨" << endl;
}
DerivedTime::DerivedTime(int h, int m, int s) : Time(h, m) {
	//만약 Time(h, m)을 상속(?)받지 않는다면,
	//Time() 이 실행된 후, DerivedTime 생성자가 실행된다.
	//그러면 DerivedTime 생성자에서 Time(h, m)을 호출해줘야 하기 때문에
	//불필요한 연산이 늘어난다.
	//그럼 바로 부모의 hour, min 변수에 할당하면 되지 않나 생각할 수 있다.
	//하지만 자식클래스에서 부모클래스의 private 멤버에는 접근할 수 없다.

	//아무튼 (int h, int m, int s) : Time(h, m) 으로 정의하면
	//자식생성자의 h, m 값이 부모 생성자의 파라미터로 전달이 된다.
	//그다음 부모생성자가 실행되고 자식생성자가 실행된다.

	sec = s;
	cout << "DerivedTime(int, int, int) 실행됨" << endl;
}
void DerivedTime::show() {
	// 1. 자식 메소드에서 오버라이드하려면 부모메소드에서 virtual로 선언해야한다.
	// 2. virtual로 선언된 메소드는 자식, 자식의 자식 전부 연쇄적으로 모두 virtual 메소드가 된다.
	// 3. 동적결합을 한다.
	//위에서도 말했듯이, 상속받아도 부모클래스의 private 멤버에 접근은 불가하다.
	cout << getHour() << "시간 ";
	cout << getMin() << "분 ";
	cout << sec << "초 " << endl;
}