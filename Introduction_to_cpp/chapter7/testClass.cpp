#include <iostream>
#include "testClass.h"
using namespace std;
//������ ���� ������ :: �� �̿��Ͽ� �����Ѵ�.
void testClass::show() {
	cout << "i * f = " << square << endl;

}
testClass::testClass(int memi, float memf) {
	this->memi = memi;
	this->memf = memf;
	square = calc_squ();
	// this �� �����Ͷ�� ������ �����ϱ� ���� �̹�,
	// �����ڿ��� this�� java���� ����ϵ� this.memi, this.memf �� �ۼ��Ϸ��� �ϴ� visual studio��
	// �ڵ����� �������������( -> )�� �������־���. �� ���� �� this�� ������ �����Ͷ�� ���� �� �� �ִ�.
	// �� ���� �ڵ带 �����ϸ� ���������� �۵��ϴ°��� ���� this�� ���� Ŭ������ �ּҰ��� ���� ���������� �� �� �־���.
}
testClass ::~testClass() {}; 

// ���� �׷��� Ŭ������ �Ű������� ���ϰ����� ����� �� �ִ�.
// ���� ������ ����Ϸ��� �ڷ��� �ڸ��� Ŭ�������� ������ �ȴ�. �翬�ϴ�.
// �Ű������� ����� ���� & ��ȣ�� �ִ´�.
// ������� aClass �� �޼ҵ尡 bClass �� �Ű������� �ް�, bClass�� �����Ѵٸ� �Ʒ�ó�� �ۼ��Ѵ�.
// bClass aClass::aMethod(bClass& i) {return i;} 
// ������ ���� bClass�� aClass���� ó���� �� �ʿ�� ���� �������̴�. �� ���⿣ ���յ��� �������� ����.
// �׷��� ���� aClass �޼ҵ尡 aClass�� �Ű������� �޾Ƽ� aClass �� ������ ���ٰ��̴�. �׷� �Ʒ�ó�� �ۼ��Ѵ�.
// aClass aClass::aMethod(aClass& i) {return i;}
// ���� return ������ this�� �شٸ�?? *this�� �־�� �Ѵ�.
// �ֳ�?? return �ڷ����� aClass �ε�, this�� aClass�� �������̱� �����̴�.
