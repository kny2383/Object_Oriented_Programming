// 이름: 김나영
// 학번: 2021041059

#include <iostream>	
#include <string> // 문자열 사용
using namespace std;

class Subject { // 과목 클래스
protected: // 클래스 자신과 상속받은 자식 클래스에만 허용
	string m_name;	// 과목명
	int m_hakjum;	// 학점
	string m_grade;	// 등급
	float m_GPA;	// 평점
public: // 모든 다른 클래스에 허용. 클래스 밖에서 직접 접근 가능
	void Initialize();	// 멤버변수 초기화
	void Initialize(string, int, string);	// 인자값으로 멤버변수 초기화
	void InputValue(int&); // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	void InputValue(string&); //  이름, 학번, 과목명 입력 받는 인라인 함수
	void InputData();	// 멤버변수 값 입력
	void PrintTitle();	// 멤버변수에 대한 title Text 출력
	void PrintData();	// 멤버변수 값 출력
	void CalcGPA();		// 평점 계산

	// Subject Class에 멤버함수로 접근자 함수 추가
	// 접근자 함수 : public 접근 권한을 갖는 멤버 함수
	// 멤버 변수의 값을 변경하거나 읽어올 때, 멤버 변수의 값에 대한 유효성 검사 가능
	string GetName() {
		return m_name; // m_name 리턴
	}
	int GetHakjum() {
		return m_hakjum; // m_hakjum 리턴
	}
	string GetGrade() {
		return m_grade; // m_grade 리턴
	}
	float GetGPA() {
		return m_GPA; // m_GPA 리턴
	}
};

class Student { // 학생 클래스
protected: // 클래스 자신과 상속받은 자식 클래스에만 허용
	string m_name;	// 학생명
	int m_hakbun;	// 학번
	int m_subnum;	// 수강한 과목 수 
	Subject* m_sub;	// 수강한 과목들
	float m_aveGPA;	// 수강한 과목들의 평균 평점
public: // 모든 다른 클래스에 허용. 클래스 밖에서 직접 접근 가능
	void Initialize();	// 멤버변수 초기화
	void Initialize(string, int, int, Subject*);	// 인자값으로 멤버변수 초기화
	void Remove();		// 동적메모리 해제(m_sub)
	void InputValue(int&); // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	void InputValue(string&); //  이름, 학번, 과목명 입력 받는 인라인 함수
	void InputData();	// 멤버변수 값 입력
	void PrintData();	// 멤버변수 값 출력
	void CalcAveGPA();	// 평균 평점 계산

	//Subject Class에 멤버함수로 접근자 함수 추가
	// 접근자 함수 : public 접근 권한을 갖는 멤버 함수
    // 멤버 변수의 값을 변경하거나 읽어올 때, 멤버 변수의 값에 대한 유효성 검사 가능
	string GetName() {
		return m_name;
	}
	int GetHakbun() {
		return m_hakbun;
	}
	int GetSubNum() {
		return m_subnum;
	}
	float GetAveGPA() {
		return m_aveGPA;
	}
};

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

void Subject::InputValue(int& i) { // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	cin >> i;
	cin.ignore();
}

void Subject::InputValue(string& str) { //  이름, 학번, 과목명 입력 받는 인라인 함수
	getline(cin, str);
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

void Student::InputValue(int& i) { // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	cin >> i;
	cin.ignore();
}

void Student::InputValue(string& str) { //  이름, 학번, 과목명 입력 받는 인라인 함수
	getline(cin, str);
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

int main() {
	Subject sub[2]; // 과목 객체 생성
	sub[0].Initialize("컴퓨터", 3, "C"); // 초기화
	sub[1].Initialize("현대무용", 2, "A"); // 초기화
	Student st1, st2; // 학생 객체 생성
	st1.Initialize("TEST", 0, 2, new Subject[2]); // 초기화
	st2.Initialize("홍길동", 2013909845, 2, sub); // 초기화
	st1.InputData(); // 정보 입력
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData(); // 정보 출력
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData(); // 정보 출력
	st1.Remove(); // 동적메모리 해제(m_sub)
}