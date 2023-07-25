#include <iostream>
#include <climits> //INT_MAX, SHRT_MAX ...
using namespace std;

int main() {
	/*변수 선언방법
	변수명 명명규칙은 여타 프로그래밍 언어와 동일하다.
	cpp도 주소값을 사용하며, c언어와 동일하게 &기호를 사용한다.
	*/

	int a = 0;
	int b = 1;
	cout << &a << endl << b << endl;
	// 자바처럼 파라미터를 자동으로 문자열로 변환시켜 출력해준다.
	
	short c = SHRT_MAX;
	unsigned short d = -1;
	cout << "Short 자료형은 " << sizeof c << "바이트 입니다." << endl;
	cout << "short 의 최대 값은 " << c << "입니다." << endl;
	cout << "unsigned short 의 최대 값은 " << d << "입니다." << endl;

	//char 는 c랑 동일하다.
	//cpp 은 string 자료형이 존재한다.

	//bool 은 c와 동일하다. 0은 false 나머지 true.

	//상수의 선언은 C와 동일하게 #define A 0 으로 선언하거나
	//const 키워드를 사용하여 초기화 할 수 있다.
	//C style과 차이점은 자료형을 지정해준다는 차이가 있다.
	const int e = 0;

	//명시적 형 변환 방법은 세가지가 있다.
	char ch = 0;
	//C style
	//(int)ch
	
	//C++ style
	int i = int(ch); // int i 가 없으면 에러가 나는데 이유를 모르겠다.

	//c++ friend style
	static_cast<int>(ch);

	return 0;
}