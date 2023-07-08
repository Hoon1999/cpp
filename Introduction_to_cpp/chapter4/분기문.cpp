#include <iostream>

using namespace std;

int main() {
	// if 문은 c style로 작성하면 된다.
	bool t = true;
	bool f = false;
	if (t && f) {
		cout << "if 문 내부" << endl;
	}
	else if (t || f) {
		cout << "else if 문 내부" << endl;
	}
	else {
		cout << "else 문 내부" << endl;
	}

	//switch 문도 c style 로 작성한다.
	int a = 3;
	switch (a) {
	case 1:
		cout << "a = 1 입니다." << endl;
		break;
	case 3:
		cout << "a = 3 입니다" << endl;
		break;
	default :
		break;
	}

	
	return 0;
}