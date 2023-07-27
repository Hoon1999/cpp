#pragma once
#include <iostream>
#ifndef TIME
#define TIME

class Time {
private:
	int hour;
	int min;
public :
	Time();
	Time(int, int);
	void addHour(int);
	void addMin(int);
	Time sum(Time&);
	Time operator+(Time&); //+������ �����ε�. �����δ� sum �� ������.
	Time operator*(int);
	//friend Time operator*(int, Time&); //operator*(int) �� ����, ����� �����ϴ�. �ζ��� �Լ��� ������ ����������.
	friend Time operator*(int n, Time& t) {
		return t * n; // Time * int �� operator*(int)���� ���� ��.
	}
	friend std::ostream& operator<<(std::ostream& os, Time& t);
	void show();
	~Time();
};

#endif