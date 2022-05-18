// 이름: 김나영
// 학번: 2021041059

#include <iostream>
using namespace std;

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"

int main() {
	Subject sub1("컴퓨터", 3, "C0"); // Subject 인자있는 생성자 호출 
	Subject sub2(sub1); // Subject 복사 생성자 호출

	cout << "\n" << "sub1 정보" << "\n"; 
	sub1.PrintData(); // sub1 정보 출력
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintData(); // sub2 정보 출력
	sub2.Modify(); // sub2 정보 수정

	Student st1; // Student 디폴트 생성자 호출 & Subject 디폴트 생성자 호출
	Student st2("홍길동", 2013909845, 1, &sub1); // Student 인자있는 생성자 호출 & Subject 디폴트 생성자 호출
	Student st3("김성령", 2015909845, 1, &sub2); // Student 인자있는 생성자 호출 & Subject 디폴트 생성자 호출
	st1 = st2; // 객체간의 대입, st2 객체를 st1에 비트 단위 복사 (깊은 복사가 아님)

	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData(); // st1 정보 출력

	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData(); // st2 정보 출력
	// 결과적으로 복사하였기 때문에 st1과 st2는 같은 결과가 나옴

	st2.Modify(); // st2 정보 수정
	cout << "\n" << "수정된 st2 정보" << "\n";

	// '모두'라는 메뉴 선택시, st2의 이름과 학번이 Modify() 함수를 통해 바뀌었고 
	// 교과목명, 학점수, 등급, 평점, 평균평점 역시 Modify() 함수를 통해 수정한 대로 바뀌었다.
	st2.PrintData(); 

	//  '모두'라는 메뉴 선택시, st2와 같이 이름과 학번, 교과목명, 학점수, 등급, 평점은 수정한 대로 바뀌었으나, 평균평점은 바뀌지 않음.
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData(); 

	cout << "\n" << "st3 정보" << "\n";
	st3.PrintData(); // sub2.Modify()를 통해 과목정보가 수정됨.

	// 깊은 복사를 하지 않았을 때에는 Student, Subject 순으로 한번씩 소멸자가 호출되다가 
	// Subject가 소멸할 때, 프로그램이 비정상 종료가 된다. 
}