#include <iostream>

using namespace std;

const int SIZE = 6;

void sumArr(int arr[], int n);
void sumArr2(int* arr, int n);
void sumArr3(int* start, int* end);

struct Time {
	int hour;
	int min;
};
Time betweenTime(Time* start, Time* end);
int main() {
	/*
	1. �Լ�
	2. �Ű������ν� �迭�� ������
	3. �Ű������� ����ü ������ ���
	4. �Լ� ������ ����
	*/
	//c++�� ��ü�����ε� �Լ���� ��Ī�� ����ϴ°ǰ�?
	//�迭�� �Լ��� ���� �ڷ������� ��� �Ұ����ϴ�. ���� c�� �׷���?
	//�迭�� ���ϰ����� ������ ���� ��� �𸣰ڳ�.
	//�Լ��� ����, ����, ȣ���� c�� �����ϴ�.

	//�Լ��� �˾ƺ��� �迭�� ������ ����
	//�⺻������ �����ʹ� �迭ó�� ����� �����ϸ�, �迭 ������ �ּҰ��� ���´�.
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6 };
	sumArr(arr, SIZE);
	sumArr2(arr, SIZE);
	sumArr3(arr, arr + SIZE); // arr + SIZE == �ּҰ� + (�ּҰ�)6
	
	cout << "------------------------------" << endl;

	//�׷� �迭�̶� �����ʹ� ǥ������� �ٸ� �� ������ ���� �����̰� ���� �����ΰ�??
	//�׷��� �ʴ�. �̴� sizeof�� ����ϸ� �� �� �ִ�.
	int* pointer = arr;
	cout << "�迭�� ũ��� " << sizeof arr << " Byte�Դϴ�." << endl; //4byte int 6�� -> �� 24 byte
	cout << "�������� ũ��� " << sizeof(pointer) << " Byte�Դϴ�." << endl; //�ּҰ� ������ ũ�� 8 Byte

	cout << "------------------------------" << endl;

	//����ü �Ű������� ȣ�� ����� call by value �̴�.(call by address�� �ƴ϶�� ��)
	//���� ����ü�� ũ�Ⱑ 10000000byte���? �����ϴµ��� ������ �ɸ� ���̴�.
	//���� �Ϲ������� ����ü�� �����͸� �����Ͽ� ȣ���Ѵ�.
	Time t1 = { 3, 20 };
	Time t2 = { 4, 10 };
	Time t3;
	t3 = betweenTime(&t1, &t2);
	cout << t1.hour << "��" << t1.min << "�п� �����Ͽ� " << t2.hour << "��" << t2.min << "�п� ������" << endl;
	cout<< "�ɸ� �ð��� " << t3.hour << "�ð�" << t3.min << "�� �Դϴ�." << endl;

	cout << "------------------------------" << endl;

	//�Լ� ������
	//�Լ��� �ּ� ���� �Լ� �̸��� ����Ǿ� �ִ�.
	//�Լ� �������� ������ �Լ� ���Ŀ� ���缭 �����ϸ� �ȴ�. �ڹ��� ��������Ʈ�� �����ϴ�.
	//�Լ� �������� ���(����)����� ���� �����Ϳ� �����ϴ�. ��� �Լ��̴� ��ŭ �Ű������� �����ϰ� �ִ�.
	void (*ptf)(int arr[], int n); // �Լ������� ptf�� �Ҵ�� �Լ��� ������ �Ķ���͸� ������.
	ptf = sumArr;
	(*ptf)(arr, SIZE); // *(�ֽ��͸���ũ)�� �����Ϳ� ����, �����Ͽ����Ƿ� �Ű������� �ʿ��ϴ�.
	cout << "�Լ� sumArr�� �ּҴ� " << ptf << "�Դϴ�." << endl;

	return 0;
}
void sumArr(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << "�迭�� ���� " << sum << "�Դϴ�." << endl;
}
void sumArr2(int* arr, int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	cout << "�迭(������ver)�� ���� " << sum << "�Դϴ�." << endl;
}
void sumArr3(int* start, int* end) {
	int sum = 0;
	int* pointer = start;
	for (; pointer != end ; pointer++) {
		sum += *pointer;
	}
	cout << "sumArr3�� ���� " << sum << "�Դϴ�." << endl;
}
Time betweenTime(Time* start, Time* end) {
	Time between;

	between.hour = end->hour - start->hour;
	if (end->min - start->min >= 0) {
		between.min = end->min - start->min;
	}
	else {
		between.min = 60 + (end->min - start->min);
		between.hour--;
	}
	return between;
}