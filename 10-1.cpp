// 이름: 김나영
// 학번: 2021041059

#include <iostream>
using namespace std;

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"

int main() {
	// Student 디폴트 생성자 호출
	Student std; 
	std.InputData(); // 멤버변수 값 입력
	std.PrintData(); // 멤버변수 값 출력
	Subject* sub = std.SubSearch("사진학"); // 사진학이라는 과목 생성
	// 과목명이 성공적으로 탐색된 경우
	// 해당 과목정보가 있는 메모리 주소를 리턴
	if (sub != NULL) {
		sub->PrintTitle(); // 멤버변수에 대한 title Text 출력
		sub->PrintData(); // 멤버변수 값 출력
	}
}