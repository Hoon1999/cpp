#include <iostream>

using namespace std;

int main() {
	//�ݺ����� c���� �����ϴ�.
	//c# �� foreach(i in array) ����
	//c++���� for( i : array)�� �ۼ��ϸ� �ȴ�.
	for (int i = 0; i < 5;) {
		cout << " i = " << i << endl;
		i++;
	}
	int j=0;
	while (j < 5) {
		cout << "j�� " << j << endl;
		j++;
	}
	string str = "study";
	int k = 0;
	do
	{
		cout << str[k] << endl;
		k++;
	} while (false);
	return 0;
}