#include <iostream>

using namespace std;

const int SIZE = 6;

void sumArr(int arr[], int n);
void sumArr2(int* arr, int n);
void sumArr3(int* start, int* end);

struct Time {
	int hour;
	int min;
};
Time betweenTime(Time* start, Time* end);
int main() {
	/*
	1. 함수
	2. 매개변수로써 배열과 포인터
	3. 매개변수로 구조체 포인터 사용
	4. 함수 포인터 개념
	*/
	//c++은 객체지향인데 함수라는 명칭을 사용하는건가?
	//배열을 함수의 리턴 자료형으로 사용 불가능하다. 원래 c언어도 그랬나?
	//배열을 리턴값으로 설정한 적이 없어서 모르겠네.
	//함수의 선언, 정의, 호출은 c와 동일하다.

	//함수로 알아보는 배열과 포인터 차이
	//기본적으로 포인터는 배열처럼 사용이 가능하며, 배열 변수는 주소값을 갖는다.
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };
	sumArr(arr, SIZE);
	sumArr2(arr, SIZE);
	sumArr3(arr, arr + SIZE); // arr + SIZE == 주소값 + (주소값)6
	
	cout << "------------------------------" << endl;

	//그럼 배열이랑 포인터는 표현방법만 다를 뿐 완전히 같은 개념이고 같은 로직인가??
	//그렇지 않다. 이는 sizeof를 사용하면 알 수 있다.
	int* pointer = arr;
	cout << "배열의 크기는 " << sizeof arr << " Byte입니다." << endl; //4byte int 6개 -> 총 24 byte
	cout << "포인터의 크기는 " << sizeof(pointer) << " Byte입니다." << endl; //주소값 공간의 크기 8 Byte

	cout << "------------------------------" << endl;

	//구조체 매개변수의 호출 방식은 call by value 이다.(call by address가 아니라는 뜻)
	//만약 구조체의 크기가 10000000byte라면? 복사하는데만 한참이 걸릴 것이다.
	//따라서 일반적으로 구조체는 포인터를 선언하여 호출한다.
	Time t1 = { 3, 20 };
	Time t2 = { 4, 10 };
	Time t3;
	t3 = betweenTime(&t1, &t2);
	cout << t1.hour << "시" << t1.min << "분에 시작하여 " << t2.hour << "시" << t2.min << "분에 끝나면" << endl;
	cout<< "걸린 시간은 " << t3.hour << "시간" << t3.min << "분 입니다." << endl;

	cout << "------------------------------" << endl;

	//함수 포인터
	//함수의 주소 값은 함수 이름에 저장되어 있다.
	//함수 포인터의 선언은 함수 형식에 맞춰서 선언하면 된다. 자바의 델리게이트와 유사하다.
	//함수 포인터의 사용(접근)방법은 변수 포인터와 동일하다. 대신 함수이니 만큼 매개변수도 포함하고 있다.
	void (*ptf)(int arr[], int n); // 함수포인터 ptf는 할당될 함수와 동일한 파라미터를 가진다.
	ptf = sumArr;
	(*ptf)(arr, SIZE); // *(애스터리스크)로 포인터에 접근, 접근하였으므로 매개변수가 필요하다.
	cout << "함수 sumArr의 주소는 " << ptf << "입니다." << endl;

	return 0;
}
void sumArr(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << "배열의 합은 " << sum << "입니다." << endl;
}
void sumArr2(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << "배열(포인터ver)의 합은 " << sum << "입니다." << endl;
}
void sumArr3(int* start, int* end) {
	int sum = 0;
	int* pointer = start;
	for (; pointer != end ; pointer++) {
		sum += *pointer;
	}
	cout << "sumArr3의 합은 " << sum << "입니다." << endl;
}
Time betweenTime(Time* start, Time* end) {
	Time between;

	between.hour = end->hour - start->hour;
	if (end->min - start->min >= 0) {
		between.min = end->min - start->min;
	}
	else {
		between.min = 60 + (end->min - start->min);
		between.hour--;
	}
	return between;
}