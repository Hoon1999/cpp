#include <iostream>

using namespace std;

/*
	배열, cin, string, 구조체, 공용체(union), 열거형, 포인터
*/
int main() {

	/* 
	복합 데이터형(구조체) : 기본 정수형 과 부동 소수점 자료형의 집합
	배열 : 같은 자료형의 집합
	배열의 선언은 c언어와 동일하다.
	배열을 초기화 할 때 사이즈를 생략할 수 있다.
	*/

	//char str[6] = { 'h', 'e', 'l', 'l', \0 };
	//char str[] = { 'h', 'e', 'l', 'l', \0 };
	char str[] = "hello"; 

	/*
	c out : print
	c in : scan
	*/
	//cout << "5자리 문자를 입력해주세요" << endl;
	//cin >> str;
	//str[4] = '\0';
	//cout << str << endl;
	//cin.ignore(6, '\n'); // 버퍼 초기화
	/*
	c in 은 scanf 처럼 공백을 end of stream으로 인식한다.
	공백 문자도 받기 위해선 cin.get 또는 cin.getline을 사용한다.
	cin.get 과 cin.getline은 사용방법이 동일하다.
	cin.get(변수명, 배열길이)
	*/
	/*cout << "5자리 문자를 입력해주세요" << endl;
	cin.getline(str, 6);*/
	
	/*
	c++ 에선 문자배열 대신 string 객체를 사용할 수 있다.
	선언과 초기화는 c style 을 사용한다.
	배열은 배열끼리 대입연산을 할 수 없지만 string 객체는 가능하다.
	string 객체는 포인터처럼 인덱스 접근이 가능하다.
	*/

	string str2;
	string str3 = "test";
	str2 = str3; //문자배열에서는 불가능
	cout << "str2[2] = " << str2[2] << endl;
	cout << "-----------" << endl;

	//구조체를 초기화 할 때 값을 할당하지 않으면(빈중괄호)로 만들면 0이 할당된다.

	/*공용체(union 은 구조체처럼 여러 자료형을 선언할 수 있지만, 값의 보관은 하나만 가능하다.
	선언의 방식은 구조체와 동일하다.
	*/
	union myunion {
		int a;
		long b;
		float c;
	};
	myunion testUnion;
	testUnion.a = 10;
	cout << "a = " << testUnion.a << endl;
	cout << "-----------" << endl;
	testUnion.b = 30;
	cout << "a = " << testUnion.a << endl;
	cout << "b = " << testUnion.b << endl;
	cout << "-----------" << endl;
	testUnion.c = 2.2;
	cout << "a = " << testUnion.a << endl;
	cout << "b = " << testUnion.b << endl;
	cout << "c = " << testUnion.c << endl;
	cout << "-----------" << endl;

	//enum 은 c와 동일함.

	//포인터의 선언과 기본적인 사용방법은 c style과 동일하다.
	//int *a; //c style 을 사용해도 문제없다.
	//int* a; //c++ style
	
	/*
	new 연산자를 사용하여 변수명 없이 변수를 생성할 수 있다.
	해당 변수에 접근하기위해서는 주소를 알아야한다.
	new 연산자는 변수의 주소값을 리턴해주기 때문에 해당 값을
	포인터 변수에 할당해주어 사용한다.

	메모리를 해제할 때는 delete 연산자를 사용한다.
	*/
	/*
	Delete 규칙
	1. new 로 선언되지 않은 포인터는 delete로 해제할 수 없다.
	2. new 자료형[] 을 해제할 때는 delete[] 포인터명 으로 작성한다.
	*/
	
	int* pointer = new int;
	*pointer = 123;
	cout << *pointer << endl;
	delete pointer;

	pointer = new int[10];
	delete[] pointer;

	//동적 구조체(구조체포인터) : 컴파일이 아닌 실행 시간에 생성된 구조체.
	//선언은 포인터 선언하는 방법으로 하면된다.
	//구조체포인터의 멤버에 접근할 때 화살표( -> ) 를 사용한다.
	// 구조체포인터->멤버
	//(*구조체포인터).멤버 를 사용해서 접근도 가능하다.
	return 0;
}