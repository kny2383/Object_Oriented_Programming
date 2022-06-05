// 이름: 김나영
// 학번: 2021041059

#include "GradeManager.h" // 헤더파일에 저장
#include "Student.h"
#include <iostream>
using namespace std;

int menuNum; // 기능 입력 전역 변수 선언
string stdname; // 학생 이름 변수 선언

GradeManager::GradeManager() { // 디폴트 생성자
	m_std = 0; // 학생 객체
	m_stdnum = 0; // 전체 학생 수
}

GradeManager::GradeManager(int m_stdNum) { // 인자있는 생성자
	m_stdnum = m_stdNum; // 인자값으로 
	m_std = new Student[m_stdnum]; // m_std는 m_stdnum 만큼 동적할당
}

GradeManager::~GradeManager() { // 소멸자. 동적할당 받은 m_std 해제
	delete m_std; // 해제
}

void GradeManager::PrintMenu() { // 전체 메뉴 출력
	cout << endl;
	cout << "===== 메뉴 =====" << endl;
	cout << "1. 학생 성적 입력" << endl; 
	cout << "2. 전체 성적 보기" << endl; 
	cout<< "3. 학생 검색" << endl;
	cout << "4. 학생 목록 보기" << endl;
	cout << "5. 학생 정보 수정" << endl;
	cout << "6. 프로그램 종료" << endl;
	cout << endl;
	cout << "원하는 기능을 입력하세요(번호입력) : ";
	cin >> menuNum; // 메뉴 입력 변수
}

void GradeManager::Execute() {
	while (1) {
		PrintMenu(); // 전체 메뉴 출력 함수

		if (menuNum == 1) {
			cin.ignore();
			for (int i = 0; i < m_stdnum; i++) {
				m_std[i].Student::InputData(); // 정보 입력 받기
			}
		}
		else if (menuNum == 2) {
			for (int i = 0; i < m_stdnum; i++) {
				m_std[i].Student::PrintData(); // 정보 출력 
			}
		}
		else if (menuNum == 3) {
			cout << "찾으려는 학생의 이름을 입력하세요 : ";
			cin >> stdname; // 학생 이름 입력 받기
			Student* std = StdSearch(stdname); // 입력 받은 학생 검색
		}
		else if (menuNum == 4) {
			PrintAllStdList(); // 전체 학생 목록 출력
		}
		else if (menuNum == 5) {
			Modify(); // 원하는 학생의 정보 수정
		}
		else if (menuNum == 6) {
			cout << "프로그램을 종료합니다." << endl;
			break;
		}
		//출력된 메뉴에 없는 번호를 선택했을 경우
		else {
			cout << "없는 메뉴 번호를 선택하셨습니다." << endl;
		}
	}
}

Student* GradeManager::StdSearch(string stdname) const { // 학생 검색
	for (int i = 0; i < m_stdnum; i++) { // 학생 수 만큼 반복
		if (stdname == m_std[i].GetName()) { // 학생 이름 비교
			return &m_std[i]; // 주소 리턴
		}
		else { // 해당 학생이 없을 경우
			cout << "찾으시는 학생이 없다." << endl;
			return NULL;
		}
	}
}

void GradeManager::PrintAllStdList() const {
	cout << "========================================" << endl;
	cout.width(15);
	cout << "이름";
	cout.width(15);
	cout << "학번";
	cout << endl;
	cout << "========================================" << endl;
	for (int i = 0; i < m_stdnum; i++) {
		cout.width(15);
		cout << m_std[i].GetName(); // 학생 이름 출력
		cout.width(15);
		cout << m_std[i].GetHakbun(); // 학생 학번 출력
		cout << endl;
	}
	cout << "========================================" << endl;
}

void GradeManager::Modify() {
	Student* std = NULL; // 찾고자하는 학생 이름

	cout << "수정할 학생의 이름을 입력하세요 : ";
	cin >> stdname; 
	std = StdSearch(stdname); // 학생정보가 있는 메모리 주소 리턴 값
	  // 입력한 과목 이름이 수강하는 과목과 일치하는지 비교
	cin.ignore();
	if (std != NULL) { // 값이 있으면
		std->Student::Modify(); // 검색된 학생 정보 수정
	}
	else {
		cout << "검색한 학생이 없습니다. 다시 검색하세요.\n";
	}
}