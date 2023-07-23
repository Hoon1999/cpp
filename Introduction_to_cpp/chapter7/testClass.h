#ifndef TESTCLASS
class testClass {
	//java와 마찬가지로 private 과 public으로 나뉜다. 역할은 java와 동일함.
	//대신 선언하는 방법이 다르다.
private:
	int memi;
	float memf;
	double square;
	double calc_squ() { return memi * memf; } //선언부에서 초기화(및 구현) 가능.
public:
	void show();//선언부에서 구현해도 되지만 따로함.
	testClass(int memi, float memf);//생성자
	~testClass();//파괴자
};
#endif