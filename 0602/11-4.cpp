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

	// Student Class의 Modify() 멤버함수 수정
	// 사용자가 “과목정보” 를 입력하면 과목에 대한 정보를 변경하는데, 과목정보를 변경할 때
	// 수정하고자 하는 과목을 검색한 후, 검색된 과목만 수정할 수 있도록 변경함

	std.PrintData(); // 수정 전의 정보를 출력
	std.Modify(); // Student Class의 멤버변수 값 수정
	std.PrintData(); // 수정 후의 정보를 출력(수정이 안됐으면 원래 정보 출력). 이때, 수강중인 과목이 아닌 과목을 검색하면 다시 검색하라는 메시지와 함께 정보를 다시 출력해준다.
}