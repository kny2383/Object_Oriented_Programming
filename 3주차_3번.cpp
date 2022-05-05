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
	const int* pInt1; // 포인터 변수가 가르키는 변수가 const인 경우

	pInt1 = &i1; 
	*pInt1 = 30; // 상수 변수는 값을 변경할 수 없다 -> 에러
}

void B() {
	int i1 = 10;
	int i2 = 20;
	int *const pInt2 = &i1; // 포인터 변수 자신이 const인 경우

	pInt2 = &i2; // 상수 포인터는 초기화 후에 가리키는 주소를 변경할 수 없는 포인터이다 -> 에러
	*pInt2 = 50;
}

void C() {
	int i1 = 10;
	int i2 = 20;
	const int* const p = &i2; // 두 변수 모두 const인 경우

	p = &i1; // 상수 포인터는 초기화 후에 가리키는 주소를 변경할 수 없는 포인터이다 -> 에러 
	*p = 40; // 상수 변수는 값을 변경할 수 없다 -> 에러
}