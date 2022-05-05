#include <iostream>
using namespace std;

void A();
void B();
void C();

int main() {
	
	A();
	B();
	C();
}

void A() {
	int i1 = 10;
	int i2 = 20;
	const int* pInt1; // ������ ������ ����Ű�� ������ const�� ���

	pInt1 = &i1; 
	*pInt1 = 30; // ��� ������ ���� ������ �� ���� -> ����
}

void B() {
	int i1 = 10;
	int i2 = 20;
	int *const pInt2 = &i1; // ������ ���� �ڽ��� const�� ���

	pInt2 = &i2; // ��� �����ʹ� �ʱ�ȭ �Ŀ� ����Ű�� �ּҸ� ������ �� ���� �������̴� -> ����
	*pInt2 = 50;
}

void C() {
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2; // �� ���� ��� const�� ���

	p = &i1; // ��� �����ʹ� �ʱ�ȭ �Ŀ� ����Ű�� �ּҸ� ������ �� ���� �������̴� -> ���� 
	*p = 40; // ��� ������ ���� ������ �� ���� -> ����
}