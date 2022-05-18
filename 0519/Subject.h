// 이름: 김나영
// 학번: 2021041059

#pragma once // 전처리기 기호를 사용하여 전역 네임스페이스가 잘못되는 것을 방지함
#include <string> // 문자열 사용
using namespace std;

class Subject { // 과목 클래스
protected:
	string m_name;	// 과목명
	int m_hakjum;	// 학점
	string m_grade;	// 등급
	float m_GPA;	// 평점
public:
	Subject();	// 디폴트 생성자 (멤버변수 초기화)
	Subject(string, int, string);	// 인자있는 생성자 (인자값으로 멤버변수 초기화)
	Subject(const Subject& sub); // 복사 생성자 (다른 Subject 클래스의 멤버변수의 값으로 초기화)
	void InputValue(int&); // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	void InputValue(string&); //  이름, 학번, 과목명 입력 받는 인라인 함수
	void InputData();	// 멤버변수 값 입력
	void PrintTitle();	// 멤버변수에 대한 title Text 출력
	void PrintData();	// 멤버변수 값 출력
	void CalcGPA();		// 평점 계산
	void Modify(); // 화면에서 입력되는 데이터로 Subject Class의 멤버변수 값 수정
	~Subject(); // 소멸자 (객체가 소멸되는 시점에서 자동으로 호출되는 함수)

	//Subject Class에 멤버함수로 접근자 함수 추가
	// 접근자 함수 : public 접근 권한을 갖는 멤버 함수
	string GetName() {
		return m_name;
	}
	int GetHakjum() {
		return m_hakjum;
	}
	string GetGrade() {
		return m_grade;
	}
	float GetGPA() {
		return m_GPA;
	}

	void SetName(string subName) {
		m_name = subName;
	}
	void SetHakjum(int subHakjum) {
		m_hakjum = subHakjum;
	}
	void SetGrade(string subGrade) {
		m_grade = subGrade;
	}
	void SetGPA(float subGPA) {
		m_GPA = subGPA;
	}
};