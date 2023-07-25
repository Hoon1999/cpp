#include <iostream>
#include "time.h"
using namespace std;

/*
* �Լ� �����ε��� �Ķ������ ������ �ٸ��� �����ߴ�.
* ������ �����ε��� ������ ��� �ұ�?
* 
* �̹� ���� ����ϴ� ������ �߿��� �����ε� �Ǿ��ִ°� �ִ�.
* �ٷ� * ������
* A * B ( A ���ϱ� B ). ���� �����ڷ� ����� �� �� �ְ�,
* int *pt = &a; ������ ������, �������������ڷε� ��� �� �� �ִ�.
* 
* ������ �����ε��� �ǿ������� �ڷ����� ���� �����Ѵ�.
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
	// + ������ �����ε�.
	// �����δ� sum�� �Ϻ��ϰ� ������.
	Time sum;
	sum.hour = hour + t.hour;
	sum.min = min + t.min;

	sum.hour = sum.hour + sum.min / 60;
	sum.min = sum.min % 60;

	return sum;
}
void Time::show() {
	cout << hour << "�ð� ";
	cout << min << "��" << endl;
}
Time::~Time() {
}
