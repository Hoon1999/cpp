#include "time.h"

/*
* 클래스의 private에는 같은 멤버함수(메소드? 명칭이 뭐지) 말고도 접근이 가능한 존재가 있다.
* 바로 friend 함수이다.
* 
* friend는 주로 언제 쓰일까?
* 바로 이항연산자를 오버로딩할 때 사용하게 된다.
* 앞서 만들었던 +연산자 오버로딩의 경우 Time + Time 형태만 가능하다.
* 그렇다면 int + Time 은 연산자 오버로딩으로 만들 수 있을까?
* 정답은 불가능하다 이다.
* operator+(int) 는 항상 Time + int 만 가능하다는 뜻이다.
* 
* 클래스의 메소드는 항상 class.method() 형태로 호출해야 되므로,
* Time + int 형태의 연산자는 절대 만들 수 없다.
* 그래서 friend 키워드를 이용해 일반함수에 class의 private 멤버에 대한 접근 권한을 제공하는 것이다.
*/
/* 프렌드는 클래스의 멤버 함수가 아니므로,
 * 일반적인 함수의 구현부와 동일하게 작성한다.
 * 리턴값 함수명(파라미터)
 */
//Time operator*(int n, Time& t) {
//	Time result;
//	long temp = t.hour * 60 * n + t.min * n;
//
//	result.hour = temp / 60;
//	result.min = temp % 60;
//
//	return result;
//}
/*
* 위 friend 의 문제점은
* n * Time은 가능하지만
* Time * n 이 불가능하다.
* 처음에 설명하였듯이 Time * n 은 연산자 오버로딩(operator*(int n))으로 구현이 가능하다.
* 
* 그렇게 하면 friend는 한 줄로 축약이 가능해진다.
* 위 처럼 한 줄로 축약을 하면 멤버 변수에 접근을 하지 않으니
* friend 일 필요도 없고,
* 한줄짜리 코드이므로 인라인 함수로 구현도 가능해진다.
* 
* 하지만!!
* 그렇다고 해서 firend를 지워도 되는 것은 아니다.
* operator*(int n, Time&)는 n * Time 을 연산하는 함수로써
* 오직 Time class만을 위해서 존재하는 함수이기 때문에,
* Time class 의 인터페이스라는 의미로 Time class 내부에 남겨두어야 한다.
*/

Time Time::operator*(int n) {
	Time result;
	long temp = hour * 60 * n + min * n;

	result.hour = temp / 60;
	result.min = temp % 60;

	return result;
}
