// 이름: 김나영
// 학번: 2021041059

#pragma once // 전처리기 기호를 사용하여 전역 네임스페이스가 잘못되는 것을 방지함
#include <string> // 문자열 사용
using namespace std;

class Subject {
protected:
	string m_name;	// 과목명
	int m_hakjum;	// 학점
	string m_grade;	// 등급
	float m_GPA;	// 평점
public:
	void Initialize();	// 멤버변수 초기화
	void Initialize(string, int, string);	// 인자값으로 멤버변수 초기화
	void InputValue(int&); 
	void InputValue(string&);
	void InputData();	// 멤버변수 값 입력
	void PrintTitle();	// 멤버변수에 대한 title Text 출력
	void PrintData();	// 멤버변수 값 출력
	void CalcGPA();		// 평점 계산

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
};