// 이름: 김나영
// 학번: 2021041059

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

void main() {
	Student std; // std라는 학생 객체 선언
	std.InputData(); // std의 멤버변수 값 입력
	IOInterface* IO[2] = { new Subject("사진학",3,"A+"), &std }; // std의 사진학 과목 정보와 입력한 과목의 정보 생성 
	for (int i = 0; i < 2; i++) { 
		cout << "\n * " << i + 1 << "번째 데이터 : " << "\n";
		IO[i]->PrintData(); // 파생클래스의 멤버함수가 호출되어야 함 / 정보 출력
	}
}