#include <iostream>
#include "time.h"
using namespace std;

/*
* 함수 오버로딩은 파라미터의 개수로 다름을 구별했다.
* 연산자 오버로딩은 구별을 어떻게 할까?
* 
* 이미 자주 사용하는 연산자 중에서 오버로딩 되어있는게 있다.
* 바로 * 연산자
* A * B ( A 곱하기 B ). 곱셈 연산자로 사용을 할 수 있고,
* int *pt = &a; 포인터 연산자, 간접참조연산자로도 사용 할 수 있다.
* 
* 연산자 오버로딩은 피연산자의 자료형에 따라 구별한다.
*/

Time::Time() {
	hour = min = 0;
}
Time::Time(int h, int m) {
	hour = h;
	min = m;
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
Time::~Time() {
}
