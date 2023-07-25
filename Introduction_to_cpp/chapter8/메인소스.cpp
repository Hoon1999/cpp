#include <iostream>
#include "time.h"

using namespace std;

int main() {
	/*
	* 1. ������ �����ε�
	* 2. ������
	* 3. stream insertion ������( << ) �����ε�
	*/
	Time day1(2, 40);
	Time day2(3, 30);
	day1.show();
	day2.show();

	cout << "day1.sum(day2) : ";
	day1.sum(day2).show();

	cout << "day1 + day2 : ";
	(day1 + day2).show();

	cout << endl << "----------------------------\n" << endl;
	cout << "2 * day1 : ";
	(2 * day1).show();

	cout << endl << "----------------------------\n" << endl;
	cout << "day1 : " << day1;

	cout << endl << "\n----------------------------\n" << endl;
	return 0;
}