#include <iostream>
#include "time.h"
/*
* ��¿����� << �� o stream Ŭ������ �����Ǿ� �ִ�.
* �����ε��� ostream���� ���� �����ε��� �ص� �ǰ�����,
* i/o stream�� c++ ǥ���̶� �ϸ� �ȵȴٰ� �Ѵ�.
* 
* ���� �����ε� �ܿ��� firend�� ����� �����ε��� �������
* friend�� ����� �����ε��� �غ���.
* 
* i/o stream �� i stream �� o stream�� ���߻�ӹ��� Ŭ������� �Ѵ�.
*/


/* ����� ���� �� ������
* friend std::ostream& operator<<(std::ostream& os, Time& t)
* 
* return ���� ostream& �� �ƴ� std::ostream& �� ����
* ó�� ������ ��, ���� �����Ϸ��� :: �� Ŭ������ ����� ��Ī�ϴ� �����ڶ�� �����ߴ�.
* �׷��� std Ŭ������ ��� ostream Ŭ���� ��� �о ���ظ� ���ߴ�.
* :: �� Ŭ���� �Ӹ� �ƴ϶� scope �� �������ִ� �����ڷν�
* std::ostream �� std namespace ���� ostream Ŭ������� �ǹ��̴�.
* �� std�� Ŭ������ �ƴϴ�.
*/
std::ostream& operator<<(std::ostream& os, Time& t) {
	os << t.hour << "�ð� " << t.min << "��";
	return os;
}