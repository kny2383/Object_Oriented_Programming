#include <iostream>
using namespace std;

int main() {
	int arr[6] = { 1,2,3,4,5,6 };
	int* chr_ptr; // 1) int에 대한 포인터 변수 chr_ptr 선언

	//chr_ptr이 arr 배열이 저장되어 있는 메모리 주소값을 갖도록 초기화
	chr_ptr = arr;

	chr_ptr++; // chr_ptr의 값을 하나 증가

	cout << chr_ptr << "\n"; // 3) 옆 문장이 실행되었을 때의 결과는? -> arr[1]의 주소값
	cout << *chr_ptr << "\n"; // 4) 옆 문장이 실행되었을 때의 결과는? -> 2
	cout << arr << "\n"; // 5) 옆 문장이 실행되었을 때의 결과는? -> arr[0]의 주소값
	cout << arr+4 << "\n"; // 6) 옆 문장이 실행되었을 때의 결과는? -> arr[4]의 주소값
	cout << &arr[3] << "\n"; // 7) 옆 문장이 실행되었을 때의 결과는? -> arr[3]의 주소값
	cout << arr[4] << "\n"; // 8) 옆 문장이 실행되었을 때의 결과는? -> 5

	// arr[3]의 값을 chr_ptr을 이용하여 프린트
	cout << *(chr_ptr + 2) << endl; // chr_ptr[3]와 동일 (chr_ptr++에 의해)

}