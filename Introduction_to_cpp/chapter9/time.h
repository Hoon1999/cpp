#include <iostream> //���̰� ifndef ���ο� �־�� �ǳ�? �ִ°� �´°� ������..
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
	virtual void show(); //virtual Ű���带 ����� �������̵� �ɼ������� ����Ѵ�.
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
	void show(); // �޼ҵ��̸��� �Ķ���Ͱ� ��ġ���� ��������.
};
#endif 