// 이름 : 김나영
// 학번 : 2021041059

#include <iostream> 
#include <algorithm> // algoritm 헤더 파일에 있는 swap()함수 사용하기 위해 선언
using namespace std;

void selectMenu();// 메뉴 선택 함수
template <class T> // 함수나 클래스를 일반화하는 C++ 도구 , 변수나 매개 변수의 타입만 다르고, 코드 부분이 동일한 함수를 일반화 시킴
void Sort(T *arr, T size); // 정렬 함수
int menu = 0; // 메뉴 변수
int intNum[5]; // 정수 배열
double douNum[5]; // 실수 배열

int main() {

	selectMenu(); // 메뉴 선택 함수
}

void selectMenu() { // 메뉴 선택 함수

	cout << "1. 정수 정렬" << endl;
	cout << "2. 실수 정렬" << endl;
	cout << "3. 종료" << endl;
	cout << "메뉴 선택 : "; cin >> menu;
	
	switch (menu) {
		case 1 :
			cout << "5개의 정수를 입력하세요 : "; 
			for (int i = 0; i < 5; i++) // 배열 입력
			{
				cin >> intNum[i];
			}
			cout << "정렬 결과 : ";
			Sort<int>(intNum, 5);
			selectMenu();
		case 2 :
			cout << "5개의 실수를 입력하세요 : ";
			for (int i = 0; i < 5; i++) // 배열 입력
			{
				cin >> douNum[i];
			}
			cout << "정렬 결과 : ";
			Sort<double>(douNum, 5);
			selectMenu();
		case 3 :
			exit(0);

	}

}

template <class T> // 제네릭 타입 T 선언
// 제네릭이란 함수나 클래스를 일반화시키고 매개 변수 타입을 지정하여 틀에 찍어 내듯이 함수를 생산하는 기법

void Sort(T *arr, T size) { // arr는 배열이름 size는 배열의 크기

	int temp; // 배열의 값을 임시 저장 해놓는 변수
	for (int i = 0; i < size-1; i++) { // 선택정렬 방식
		temp = i; // 시작은 temp = 0
		for (int j = i+1; j < size; j++) {
			if (arr[temp] > arr[j]) // 오름차순 정렬
			{
				temp = j;
			}
		}
		swap(arr[temp], arr[i]); // algoritm 헤더 파일에 있는 swap()함수 : 두 값을 바꿔준다.
	}
	for (int i = 0; i < size; i++) { // 배열 출력
		cout << arr[i] << " ";
	}
	cout << endl;
}

		