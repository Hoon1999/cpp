#include <iostream> //ㅇ이거 ifndef 내부에 넣어야 되나? 넣는게 맞는거 같은데..
#ifndef TIME
#define TIME

class Time {
private:
	int hour;
	int min;
public:
	Time();
	Time(int, int);
	void addHour(int);
	void addMin(int);
	Time sum(Time&);
	Time operator+(Time&); 
	Time operator*(int);
	friend Time operator*(int n, Time& t) {
		return t * n;
	}
	friend std::ostream& operator<<(std::ostream& os, Time& t);
	virtual void show(); //virtual 키워드를 사용해 오버라이딩 될수있음을 명시한다.
	int getHour();
	int getMin();
	virtual ~Time(); //virtual
};

class DerivedTime : public Time {
private :
	int sec;
public :
	DerivedTime(); 
	DerivedTime(int, int, int);
	void show(); // 메소드이름과 파라미터가 겹치지만 문제없다.
};
#endif 