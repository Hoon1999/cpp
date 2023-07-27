#include <iostream>
#include "time.h"

using namespace std;

Time::Time() {
	hour = min = 0;
	cout << "Time() �����ڰ� �����" << endl;
}
Time::Time(int h, int m) {
	hour = h;
	min = m;
	cout << "Time(int, int) �����ڰ� �����" << endl;
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
int Time::getHour() {
	return hour;
}
int Time::getMin() {
	return min;
}
Time::~Time() {
}

DerivedTime::DerivedTime() : Time() {
	//���� : Time()�� �ۼ����� �ʴ´ٸ�,
	//�θ� �����ڰ� ���� ���� �� ��, �ڽ� �����ڰ� �����.
	//���� ����� �׷��� �ǵ� ���� ����� ����.
	sec = 0;
	cout << "DerivedTime() �����" << endl;
}
DerivedTime::DerivedTime(int h, int m, int s) : Time(h, m) {
	//���� Time(h, m)�� ���(?)���� �ʴ´ٸ�,
	//Time() �� ����� ��, DerivedTime �����ڰ� ����ȴ�.
	//�׷��� DerivedTime �����ڿ��� Time(h, m)�� ȣ������� �ϱ� ������
	//���ʿ��� ������ �þ��.
	//�׷� �ٷ� �θ��� hour, min ������ �Ҵ��ϸ� ���� �ʳ� ������ �� �ִ�.
	//������ �ڽ�Ŭ�������� �θ�Ŭ������ private ������� ������ �� ����.

	//�ƹ�ư (int h, int m, int s) : Time(h, m) ���� �����ϸ�
	//�ڽĻ������� h, m ���� �θ� �������� �Ķ���ͷ� ������ �ȴ�.
	//�״��� �θ�����ڰ� ����ǰ� �ڽĻ����ڰ� ����ȴ�.

	sec = s;
	cout << "DerivedTime(int, int, int) �����" << endl;
}
void DerivedTime::show() {
	// 1. �ڽ� �޼ҵ忡�� �������̵��Ϸ��� �θ�޼ҵ忡�� virtual�� �����ؾ��Ѵ�.
	// 2. virtual�� ����� �޼ҵ�� �ڽ�, �ڽ��� �ڽ� ���� ���������� ��� virtual �޼ҵ尡 �ȴ�.
	// 3. ���������� �Ѵ�.
	//�������� ���ߵ���, ��ӹ޾Ƶ� �θ�Ŭ������ private ����� ������ �Ұ��ϴ�.
	cout << getHour() << "�ð� ";
	cout << getMin() << "�� ";
	cout << sec << "�� " << endl;
}