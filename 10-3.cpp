// 이름: 김나영
// 학번: 2021041059

#include <iostream>
using namespace std;

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"

void main() {
	// 객체 배열 선언 및 초기화 {} 안에 생성자 나열
	Subject sub1[2] = { Subject("컴퓨터", 3, "C0"), Subject("현대무용", 2, "A0") }; // Subject 인자있는 생성자 2번 호출
	// 포인터 객체 배열 선언 및 초기화, 객체의 동적 생성
	Subject* sub2[2] = { new Subject(), new Subject("수학", 3, "C0") }; // Subject 디폴트 생성자 호출, Subject 인자있는 생성자 호출

	Student st1; // st1 학생 객체 생성, Student 디폴트 생성자 호출, Subject 디폴트 생성자 호출
	Student st2("홍길동", 2013909845, 2, sub1); // st2 객체 생성, Subject 디폴트 생성자 호출, Student 인자있는 생성자 호출
	Student* st3 = new Student[2]; // 디폴트 생성자로 초기화한 st3 포인터 생성, Student 디폴트 생성자 2번 호출
	cout << "\n" << "sub2[0] 입력" << "\n";
		sub2[0]->InputData(); // 포인터로 멤버 접근
	cout << "\n" << "st1 입력" << "\n";
	st1.InputData(); // st1 정보 입력
	cout << "\n" << "st3 입력" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->InputData(); // 포인터로 멤버 접근, Subject 디폴트 생성자 반복문 돌 때마다 호출
	cout << "\n" << "sub1 정보 출력" << "\n";
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++) 
		sub1[i].PrintData(); // sub1 정보 출력 : [컴퓨터, 3, C0], [현대무용,2,A0]
	cout << "\n" << "sub2 정보 출력" << "\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++) 
		sub2[i]->PrintData(); // sub2 정보 출력 : 입력한 과목과 수학 과목 정보
	cout << "\n" << "st1 정보 출력" << "\n";
	st1.PrintData(); // st1 정보 출력
	cout << "\n" << "st2 정보 출력" << "\n";
	st2.PrintData(); // st2 정보 출력 :  홍길동의 sub1 과목 정보와 인적사항
	cout << "\n" << "st3 정보 출력" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->PrintData(); // st3 정보 출력 : 입력한 st3의 인적사항과 과목 정보 출력

	// Student 소멸자 호출
	// Subject 소멸자 호출
	// Subject 소멸자 호출
	// Student 소멸자 호출
	// Subject 소멸자 호출
	// Subject 소멸자 호출
	// Subject 소멸자 호출
}