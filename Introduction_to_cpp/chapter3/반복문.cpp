#include <iostream>

using namespace std;

int main() {
	//반복문은 c언어와 동일하다.
	//c# 의 foreach(i in array) 문은
	//c++에서 for( i : array)로 작성하면 된다.
	for (int i = 0; i < 5;) {
		cout << " i = " << i << endl;
		i++;
	}
	int j=0;
	while (j < 5) {
		cout << "j는 " << j << endl;
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