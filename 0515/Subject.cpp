// 이름: 김나영
// 학번: 2021041059

#include "Student.h" // 헤더파일에 저장
#include <iostream>

void Subject::Initialize() { // 멤버변수의 값 초기화
	m_name = ""; // 과목명
	m_hakjum = 0; // 학점
	m_grade = ""; // 등급
	m_GPA = 0.0f; // 평점
}

// 오버로딩을 이용한 또다른 초기화 방법
// 과목명, 학점, 등급은 인자값으로, 평점은 따로 계산하여 넣어 줌(평점 계산 함수 호출)
void Subject::Initialize(string subName, int subHakjum, string subGrade) {
	m_name = subName; // 과목명
	m_hakjum = subHakjum; // 학점
	m_grade = subGrade; // 등급
	CalcGPA(); // 평점 계산 함수 호출
}

// 개별 데이타를 사용자로부터 입력받을 때 사용하는 코드를 묶어 오버로드 된 인라인함수

void Subject::InputValue(string& str) { //  이름, 학번, 과목명 입력 받는 인라인 함수
	getline(cin, str); 
}

void Subject::InputValue(int& i) { // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	cin >> i;
	cin.ignore();
}

void Subject::InputData() { // 멤버변수의 값을 화면에서 입력 받음
	// InputValue() 함수 이용하여 개별 데이터 입력
	cout << "교과목명 : ";
	InputValue(m_name);
	cout << "과목학점 : ";
	InputValue(m_hakjum);
	cout << "과목등급(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	CalcGPA();
}

void Subject::PrintTitle() { // 멤버변수에 대한 title 텍스트를 화면에 출력
	cout << "===============================================================\n";
	cout.width(15);
	cout << "교과목명";
	cout.width(15);
	cout << "학점수";
	cout.width(15);
	cout << "등급";
	cout.width(15);
	cout << "평점\n";
	cout << "===============================================================\n";
}

void Subject::PrintData() { // 멤버변수의 값(교과목명, 학점수, 등급, 평점)을 화면에 출력
	// 과목정보 출력
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << m_hakjum;
	cout.width(15);
	cout << m_grade;
	cout.width(15);
	cout << m_GPA << '\n';
}

void Subject::CalcGPA() { // 평점 계산
	float result;

	//해당 과목의 grade를 비교하여 해당하는 평점을 저장
	if (m_grade == "A+")
		result = 4.5;
	else if (m_grade == "A0")
		result = 4.0;
	else if (m_grade == "B+")
		result = 3.5;
	else if (m_grade == "B0")
		result = 3.0;
	else if (m_grade == "C+")
		result = 2.5;
	else if (m_grade == "C0")
		result = 2.0;
	else if (m_grade == "D+")
		result = 1.5;
	else if (m_grade == "D0")
		result = 1.0;
	else
		result = 0.0;

	m_GPA = result * m_hakjum; // 계산된 학점
}