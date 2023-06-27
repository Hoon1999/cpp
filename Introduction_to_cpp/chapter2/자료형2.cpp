#include <iostream>

using namespace std;

/*
	�迭, cin, string, ����ü, ����ü(union), ������, ������
*/
int main() {

	/* 
	���� ��������(����ü) : �⺻ ������ �� �ε� �Ҽ��� �ڷ����� ����
	�迭 : ���� �ڷ����� ����
	�迭�� ������ c���� �����ϴ�.
	�迭�� �ʱ�ȭ �� �� ����� ������ �� �ִ�.
	*/

	//char str[6] = { 'h', 'e', 'l', 'l', \0 };
	//char str[] = { 'h', 'e', 'l', 'l', \0 };
	char str[] = "hello"; 

	/*
	c out : print
	c in : scan
	*/
	//cout << "5�ڸ� ���ڸ� �Է����ּ���" << endl;
	//cin >> str;
	//str[4] = '\0';
	//cout << str << endl;
	//cin.ignore(6, '\n'); // ���� �ʱ�ȭ
	/*
	c in �� scanf ó�� ������ end of stream���� �ν��Ѵ�.
	���� ���ڵ� �ޱ� ���ؼ� cin.get �Ǵ� cin.getline�� ����Ѵ�.
	cin.get �� cin.getline�� ������� �����ϴ�.
	cin.get(������, �迭����)
	*/
	/*cout << "5�ڸ� ���ڸ� �Է����ּ���" << endl;
	cin.getline(str, 6);*/
	
	/*
	c++ ���� ���ڹ迭 ��� string ��ü�� ����� �� �ִ�.
	����� �ʱ�ȭ�� c style �� ����Ѵ�.
	�迭�� �迭���� ���Կ����� �� �� ������ string ��ü�� �����ϴ�.
	string ��ü�� ������ó�� �ε��� ������ �����ϴ�.
	*/

	string str2;
	string str3 = "test";
	str2 = str3; //���ڹ迭������ �Ұ���
	cout << "str2[2] = " << str2[2] << endl;
	cout << "-----------" << endl;

	//����ü�� �ʱ�ȭ �� �� ���� �Ҵ����� ������(���߰�ȣ)�� ����� 0�� �Ҵ�ȴ�.

	/*����ü(union �� ����üó�� ���� �ڷ����� ������ �� ������, ���� ������ �ϳ��� �����ϴ�.
	������ ����� ����ü�� �����ϴ�.
	*/
	union myunion {
		int a;
		long b;
		float c;
	};
	myunion testUnion;
	testUnion.a = 10;
	cout << "a = " << testUnion.a << endl;
	cout << "-----------" << endl;
	testUnion.b = 30;
	cout << "a = " << testUnion.a << endl;
	cout << "b = " << testUnion.b << endl;
	cout << "-----------" << endl;
	testUnion.c = 2.2;
	cout << "a = " << testUnion.a << endl;
	cout << "b = " << testUnion.b << endl;
	cout << "c = " << testUnion.c << endl;
	cout << "-----------" << endl;

	//enum �� c�� ������.

	//�������� ����� �⺻���� ������� c style�� �����ϴ�.
	//int *a; //c style �� ����ص� ��������.
	//int* a; //c++ style
	
	/*
	new �����ڸ� ����Ͽ� ������ ���� ������ ������ �� �ִ�.
	�ش� ������ �����ϱ����ؼ��� �ּҸ� �˾ƾ��Ѵ�.
	new �����ڴ� ������ �ּҰ��� �������ֱ� ������ �ش� ����
	������ ������ �Ҵ����־� ����Ѵ�.

	�޸𸮸� ������ ���� delete �����ڸ� ����Ѵ�.
	*/
	/*
	Delete ��Ģ
	1. new �� ������� ���� �����ʹ� delete�� ������ �� ����.
	2. new �ڷ���[] �� ������ ���� delete[] �����͸� ���� �ۼ��Ѵ�.
	*/
	
	int* pointer = new int;
	*pointer = 123;
	cout << *pointer << endl;
	delete pointer;

	pointer = new int[10];
	delete[] pointer;

	//���� ����ü(����ü������) : �������� �ƴ� ���� �ð��� ������ ����ü.
	//������ ������ �����ϴ� ������� �ϸ�ȴ�.
	//����ü�������� ����� ������ �� ȭ��ǥ( -> ) �� ����Ѵ�.
	// ����ü������->���
	//(*����ü������).��� �� ����ؼ� ���ٵ� �����ϴ�.
	return 0;
}