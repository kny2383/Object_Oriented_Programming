// 이름: 김나영
// 학번: 2021041059

#include <iostream>
using namespace std;

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"

void Data(const Student& s) { // 응용프로그램에 있는 전역함수
	// const 객체가 Get함수를 호출할 때 Get함수가 const가 아니면 오류 발생함. 
	cout << s.GetName() << "이 수강한 과목은 총" << s.GetSubNum() << "개로";
	cout << "수강한 과목의 평균평점은" << s.GetAveGPA() << "입니다.\n";
}
int main() {
	// 인자있는 생성자 호출
	Subject sub1("컴퓨터", 3, "C0"); // sub1 생성
	Subject sub2("계산기", 2, "A0"); // sub2 생성

	// static 멤버함수 호출
	Subject::PrintTitle(); // 멤버변수에 대한 title 텍스트를 화면에 출력

	sub1.PrintData(); // sub1의 값(교과목명, 학점수, 등급, 평점)을 화면에 출력
	sub2.PrintData(); // sub2의 값(교과목명, 학점수, 등급, 평점)을 화면에 출력

	Student st1("홍길동", 2013909845, 1, &sub1); // st1 생성
	st1.PrintData(); // st1의 값 출력
	Data(st1); // st1의 정보 출력
}