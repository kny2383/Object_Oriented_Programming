// 이름 : 김나영
// 학번 : 2021041059

#include <iostream>
#include <cstring> // strcmp() 함수 사용을 위한 선언
using namespace std;

void GetMin(int a, int b) { // 정수 최소값 찾는 함수

	if (a > b)
		cout << "최소값은 " << b << "입니다" << endl;
	else
		cout << "최소값은 " << a << "입니다" << endl;
}

void GetMin(double a, double b) { // 실수 최소값 찾는 함수

	if (a > b)
		cout << "최소값은 " << b << "입니다" << endl;
	else
		cout << "최소값은 " << a << "입니다" << endl;
}

void GetMin(char a[10], char b[10]) { // 문자열 최소값 찾는 함수

	if (strcmp(a, b) > 0) { // 문자열 a와 문자열 b를 비교하는 함수 strcmp() , 0보다 크면 a가 더 큰 것이다.
		cout << "최소값은 " << b << "입니다" << endl;
	}
	else
		cout << "최소값은 " << a << "입니다" << endl;
}

void GetMin(int *a, int size) { // a는 배열 이름 , size는 배열의 크기

	int min = a[0]; // 처음 최소값은 배열의 첫번째 값으로 설정한다.

	for (int i = 0; i < size-1; i++) { // 0부터 size-1까지 최소값을 찾는다
		if (min > a[i+1]) 
			min = a[i+1];
	}
	cout << "최소값은 " << min << "입니다" << endl;
}

int main() { 

	// GetMin()함수를 통해 동일한 이름을 사용하면 함수 이름을 구분하여 기억할 필요 없고, 함수 호출을 잘못하는 실수를 줄일 수가 있다.

	// 중복된 함수들의 이름이 동일하고 매개 변수 타입이 다 다르기 때문에 구현이 가능하다.

	int a, b = 0; // 정수 변수 초기화
	cout << "두개의 정수를 입력하세요 : "; cin >> a >> b;
	GetMin(a,b);

	double c, d = 0; // 실수 변수 초기화
	cout << "두개의 실수를 입력하세요 : "; cin >> c >> d;
	GetMin(c,d);

	char e[10]; // 문자열 변수 e,f
	char f[10];
	cout << "두개의 문자열를 입력하세요 : "; cin >> e >> f;
	GetMin(e, f);

	int size = 0; // 배열의 크기 초기화
	cout << "배열의 크기를 입력하세요 : "; cin >> size;
	int* g = new int[size]; // 크기만큼 g 배열 동적할당
	cout << "배열의 원소 : "; 
	for (int i = 0; i < size; i++)
	{
		cin >> g[i]; // 배열 입력 받기
	}
	GetMin(g,size);
}