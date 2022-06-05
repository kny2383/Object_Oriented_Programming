// 이름: 김나영
// 학번: 2021041059

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"
#include "GradeManager.h"
#include <iostream>
#include <string>
using namespace std;

void main() {
	int stdnum;
	cout << "입력할 학생 수를 입력 : ";
	cin >> stdnum;
	// Student::InputValue(stdnum);
	cout << endl;
	GradeManager GradeMgr(stdnum); // stdnum 학생 수 만큼 GradeManager 객체 생성
	GradeMgr.Execute(); // 사용자가 입력한 메뉴 번호에 따라 실제 해야 할 함수 호출
}