#ifndef TESTCLASS
class testClass {
	//java�� ���������� private �� public���� ������. ������ java�� ������.
	//��� �����ϴ� ����� �ٸ���.
private:
	int memi;
	float memf;
	double square;
	double calc_squ() { return memi * memf; } //����ο��� �ʱ�ȭ(�� ����) ����.
public:
	void show();//����ο��� �����ص� ������ ������.
	testClass(int memi, float memf);//������
	~testClass();//�ı���
};
#endif