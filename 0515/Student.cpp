// 이름: 김나영
// 학번: 2021041059

#include "Student.h" // 헤더파일에 저장
#include <iostream>
using namespace std;

void Student::Initialize() { // 멤버변수의 값 초기화
	m_name = ""; // 학생명
	m_hakbun = 0; // 학번
	m_subnum = 0; // 과목수
	m_sub = NULL; // 수강한 과목들
	m_aveGPA = 0.0f; // 수강한 과목들의 평균 평점
}

void Student::Initialize(string stdName, int stdHakbun, int subnum, Subject* stdSub) { // 인자값으로 멤버변수 초기화
	m_name = stdName; // 학생명
	m_hakbun = stdHakbun; // 학번
	m_subnum = subnum; // 과목수
	m_sub = stdSub; // 수강한 과목들
	CalcAveGPA(); // 수강한 과목들의 평균 평점
}

void Student::Remove() { // 동적메모리 해제(m_sub)
	delete[] m_sub;
}

void Student::InputValue(string& str) { //  이름, 학번, 과목명 입력 받는 인라인 함수
	getline(cin, str);
}

void Student::InputValue(int& i) { // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	cin >> i;
	cin.ignore();
}

void Student::InputData() { // 멤버변수 값 입력
	// 학생정보 입력
	cout << "이름 : ";
	InputValue(m_name); // 이름 입력
	cout << "학번 : ";
	InputValue(m_hakbun); // 학번 입력

	// 과목정보 입력
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData(); 
	}

	CalcAveGPA(); // 평균 평점 계산
}

void Student::PrintData() { // 멤버변수 값 출력
	// 학생 정보 title
	cout << "===============================================================\n";
	cout.width(15);
	cout << "이름 : ";
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << "학번 : ";
	cout.width(15);
	cout << m_hakbun << '\n';

	// 과목 정보 title
	m_sub->PrintTitle();
	// 과목 정보 출력
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "===============================================================\n";

	//해당 학생의 과목 평균 평점 출력
	cout.width(45);
	cout << "평균평점 : ";
	cout << m_aveGPA << '\n';
}

void Student::CalcAveGPA() { // 평균 평점 계산
	float sumGPA = 0.0;

	for (int i = 0; i < m_subnum; i++) {
		//모든 과목의 평점 저장
		sumGPA += m_sub[i].GetGPA();
	}
	//계산된 과목 평균 평점 전달
	m_aveGPA = sumGPA / m_subnum;
}