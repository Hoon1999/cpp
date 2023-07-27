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
	Time operator+(Time&); //+연산자 오버로딩. 구현부는 sum 과 동일함.
	Time operator*(int);
	//friend Time operator*(int, Time&); //operator*(int) 로 인해, 축약이 가능하다. 인라인 함수로 구현이 가능해진다.
	friend Time operator*(int n, Time& t) {
		return t * n; // Time * int 는 operator*(int)에서 연산 함.
	}
	friend std::ostream& operator<<(std::ostream& os, Time& t);
	void show();
	~Time();
};

#endif