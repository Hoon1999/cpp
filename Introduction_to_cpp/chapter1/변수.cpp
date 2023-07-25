#include <iostream>
#include <climits> //INT_MAX, SHRT_MAX ...
using namespace std;

int main() {
	/*���� ������
	������ ����Ģ�� ��Ÿ ���α׷��� ���� �����ϴ�.
	cpp�� �ּҰ��� ����ϸ�, c���� �����ϰ� &��ȣ�� ����Ѵ�.
	*/

	int a = 0;
	int b = 1;
	cout << &a << endl << b << endl;
	// �ڹ�ó�� �Ķ���͸� �ڵ����� ���ڿ��� ��ȯ���� ������ش�.
	
	short c = SHRT_MAX;
	unsigned short d = -1;
	cout << "Short �ڷ����� " << sizeof c << "����Ʈ �Դϴ�." << endl;
	cout << "short �� �ִ� ���� " << c << "�Դϴ�." << endl;
	cout << "unsigned short �� �ִ� ���� " << d << "�Դϴ�." << endl;

	//char �� c�� �����ϴ�.
	//cpp �� string �ڷ����� �����Ѵ�.

	//bool �� c�� �����ϴ�. 0�� false ������ true.

	//����� ������ C�� �����ϰ� #define A 0 ���� �����ϰų�
	//const Ű���带 ����Ͽ� �ʱ�ȭ �� �� �ִ�.
	//C style�� �������� �ڷ����� �������شٴ� ���̰� �ִ�.
	const int e = 0;

	//����� �� ��ȯ ����� �������� �ִ�.
	char ch = 0;
	//C style
	//(int)ch
	
	//C++ style
	int i = int(ch); // int i �� ������ ������ ���µ� ������ �𸣰ڴ�.

	//c++ friend style
	static_cast<int>(ch);

	return 0;
}