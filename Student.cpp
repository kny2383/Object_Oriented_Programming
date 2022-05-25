// 이름: 김나영
// 학번: 2021041059

#include "Student.h" // 헤더파일에 저장
#include <iostream>
using namespace std;

// 생성자와 소멸자는 리턴 값이 없다.
Student::Student() { // 디폴트 생성자로 멤버변수의 값 초기화
	// 디폴트 생성자란 매개 변수 없는 생성자, 기본 생성자이다.
	// 객체를 생성할 때 별도로 지정하지 않으면 항상 디폴트 생성자로 초기화된다.
	m_name = ""; // 학생명
	m_hakbun = 0; // 학번
	m_subnum = 0; // 과목수
	m_sub = NULL; // 수강한 과목들
	m_aveGPA = 0.0f; // 수강한 과목들의 평균 평점
	cout << "Student 디폴트 생성자\n";
}

// 인자있는 생성자 (생성자는 오버로딩이 가능하다)
// 과목명, 학점, 등급은 인자값으로, 평점은 따로 계산하여 넣어 줌(평점 계산 함수 호출)
Student::Student(string stdName, int stdHakbun, int subnum, Subject* stdSub) { 
	m_name = stdName; // 학생명
	m_hakbun = stdHakbun; // 학번
	m_subnum = subnum; // 과목수
	m_sub = new Subject[m_subnum]; // 깊은 복사 -> 동적 메모리 할당
	for (int i = 0; i < m_subnum; i++) { // 접근자 함수 사용(클래스의 멤버 변수에 대한 접근을 도와주는 기능)
		m_sub[i].SetName(stdSub[i].GetName());
		m_sub[i].SetHakjum(stdSub[i].GetHakjum());
		m_sub[i].SetGrade(stdSub[i].GetGrade());
		m_sub[i].SetGPA(stdSub[i].GetGPA());
	}
	CalcAveGPA(); // 수강한 과목들의 평균 평점
	cout << "Student 인자있는 생성자\n";
}

// 복사 생성자 : 같은 클래스의 다른 객체와 같은 값을 갖도록 초기화
Student::Student(const Student& std) {  // 다른 Subject 클래스의 멤버변수의 값으로 초기화
	m_name = std.m_name; 
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum]; // 깊은 복사 -> 동적 메모리 할당
	for (int i = 0; i < m_subnum; i++) { // 접근자 함수 사용(클래스의 멤버 변수에 대한 접근을 도와주는 기능)
		m_sub[i].SetName(std.m_sub[i].GetName());
		m_sub[i].SetHakjum(std.m_sub[i].GetHakjum());
		m_sub[i].SetGrade(std.m_sub[i].GetGrade());
		m_sub[i].SetGPA(std.m_sub[i].GetGPA());
	}
	m_aveGPA = std.m_aveGPA;
	cout << "Student 복사 생성자\n";
}

Subject * Student::SubSearch(string subname) const { // 과목 검색 함수
	
	for (int i = 0; i < m_subnum; i++) { // 과목수만큼 반복
		if (subname == m_sub[i].GetName()) { // 과목명 비교
			return &m_sub[i]; // 주소 리턴
		}
		else { // 해당 과목이 없을 경우
			cout << "검색한 교과목이 없습니다.\n";
			return NULL;
		}
	}
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

	cout << "과목 수 : "; 
	InputValue(m_subnum); // 과목 수 입력

	m_sub = new Subject[m_subnum]; // 과목 수 만큼 동적 메모리 할당
	// 과목정보 입력
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData(); 
	}

	CalcAveGPA(); // 평균 평점 계산
}

void Student::PrintData() const { // 멤버변수 값 출력
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

void Student::StdModify() { // 학생 정보 수정
	cout << "<" << m_name << ", " << m_hakbun << ">의 정보를 수정하세요\n";

	cout << "이름 : "; InputValue(m_name);
	cout << "학번 : "; InputValue(m_hakbun);
}

void Student::Modify() { // 정보 수정

	string Type; // 메뉴 입력 받는 string
	//수정하고픈 정보 입력
	cout << "\n수정할 정보를 선택하세요 <학생정보 / 과목정보 / 모두> : ";
	InputValue(Type);
	cout << '\n';

	//학생 정보를 입력한 경우
	if (Type == "학생 정보" || Type == "학생정보") {
		StdModify(); // 학생 정보 수정 
	}
	//과목 정보를 입력한 경우
	else if (Type == "과목 정보" || Type == "과목정보") {
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify(); // 과목 정보 수정
		}
		CalcAveGPA(); // 멤버변수 수정시 과목별 평점 및 평균평점 재계산
	}
	else if (Type == "모두") {
		StdModify(); // 학생 정보 수정
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify(); // 과목 정보 수정
		}
		CalcAveGPA(); // 멤버변수 수정시 과목별 평점 및 평균평점 재계산
	}
	//잘못 입력한 경우
	else {
		cout << "<수정하고자 하는 정보를 정확히 입력해주세요.>\n\n";
	}
}

// 소멸자 : 객체가 소멸되는 시점에서 자동으로 호출되는 함수
Student::~Student() { // 동적 할당 받은 메모리 정리
	cout << "Student 소멸자\n";
	delete[] m_sub;
	m_sub = NULL;
}