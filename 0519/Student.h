// 이름: 김나영
// 학번: 2021041059

#pragma once // 전처리기 기호를 사용하여 전역 네임스페이스가 잘못되는 것을 방지함
#include "Subject.h" // Student Class는 내부적으로 Subject Class를 사용함
#include <string>
using namespace std;

class Student { // 학생 클래스
protected: // 클래스 자신과 상속받은 자식 클래스에만 허용
	string m_name;	// 학생명
	int m_hakbun;	// 학번
	int m_subnum;	// 수강한 과목 수 
	Subject* m_sub;	// 수강한 과목들
	float m_aveGPA;	// 수강한 과목들의 평균 평점
public: // 모든 다른 클래스에 허용. 클래스 밖에서 직접 접근 가능
	Student();	// 디폴트 생성자 (멤버변수 초기화)
	Student(string, int, int, Subject*); // 인자있는 생성자 (인자값으로 멤버변수 초기화)
	Student(const Student& std); // 다른 Student 클래스의 멤버변수의 값으로 초기화
	void InputValue(int&); // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	void InputValue(string&);  //  이름, 학번, 과목명 입력 받는 인라인 함수
	void InputData();	// 멤버변수 값 입력
	void PrintData();	// 멤버변수 값 출력
	void CalcAveGPA();	// 평균 평점 계산
	void StdModify(); // 학생 이름 및 학번 수정
	void Modify(); // 멤버변수 값 수정
	~Student(); // 소멸자 (객체가 소멸되는 시점에서 자동으로 호출되는 함수)

	//Subject Class에 멤버함수로 접근자 함수 추가
	// 접근자 함수 : public 접근 권한을 갖는 멤버 함수
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
	// friend 함수
	friend void ShowData(const Student& s);
};