#include <iostream> // .h 안붙인다

/*c out 은 io stream 의 std 에 존재하는 함수이다(정확히는 함수가 아니라 객체임).
using namespace std를 사용하지 않으면 std::cout 이렇게 작성하여야 한다.*/
using namespace std;

int main() {
	/*<< 는 값을 전달하는 역할이다. a << b 는 쉘에서 b | a 와 동일하다.
	endl 은 new line 이다.*/


	cout << "hello, world!" << endl;
	/*(hello, world << endl) == (hello, world\n)
	(cout << hello, world) == cout("hello, world!\n")*/
	return 0;
}