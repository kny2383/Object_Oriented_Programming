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
	Subject sub("컴퓨터", 3, "C0"); // sub 객체 생성
	Student std("홍길동", 20138342, 1, &sub); // std 객체 생성

	std.PrintData(); // 수정 전의 정보를 출력
	std.Modify(); // Student Class의 멤버변수 값 수정
	std.PrintData(); // 수정 후의 정보를 출력
}