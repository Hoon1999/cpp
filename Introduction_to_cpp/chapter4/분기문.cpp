#include <iostream>

using namespace std;

int main() {
	// if ���� c style�� �ۼ��ϸ� �ȴ�.
	bool t = true;
	bool f = false;
	if (t && f) {
		cout << "if �� ����" << endl;
	}
	else if (t || f) {
		cout << "else if �� ����" << endl;
	}
	else {
		cout << "else �� ����" << endl;
	}

	//switch ���� c style �� �ۼ��Ѵ�.
	int a = 3;
	switch (a) {
	case 1:
		cout << "a = 1 �Դϴ�." << endl;
		break;
	case 3:
		cout << "a = 3 �Դϴ�" << endl;
		break;
	default :
		break;
	}

	
	return 0;
}