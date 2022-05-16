// 이름: 김나영
// 학번: 2021041059

#include <iostream>	
using namespace std;

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"

int main() {
	Subject sub[2]; // 과목 객체 생성
	sub[0].Initialize("컴퓨터", 3, "C"); // 초기화
	sub[1].Initialize("현대무용", 2, "A"); // 초기화
	Student st1, st2; // 학생 객체 생성
	st1.Initialize("TEST", 0, 2, new Subject[2]); // 초기화
	st2.Initialize("홍길동", 2013909845, 2, sub); // 초기화
	st1.InputData(); // 정보 입력
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData(); // 정보 출력
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData(); // 정보 출력
	st1.Remove(); // 동적메모리 해제(m_sub)
}