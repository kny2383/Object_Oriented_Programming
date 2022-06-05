// 이름: 김나영
// 학번: 2021041059

#pragma once // 전처리기 기호를 사용하여 전역 네임스페이스가 잘못되는 것을 방지함
#include <string> // 문자열 사용
#include "Student.h"
#include "Subject.h"
using namespace std;

class GradeManager {
protected: 
	Student* m_std; // 전체 학생 정보를 담고 있는 Student 객체
	int m_stdnum; // 관리하고 있는 전체 학생수
	static void PrintMenu(); // 메뉴 출력
	Student* StdSearch(string stdname) const; // 원하는 학생 검색
	void PrintAllStdList() const; // 전체 학생 목록 출력
	void Modify(); // 원하는 학생의 정보 수정

public:
	GradeManager(); // 디폴트 생성자
	GradeManager(int m_stdnum); // 인자 있는 생성자
	~GradeManager(); // 소멸자
	void Execute(); // 학생 성적을 관리하는 함수
};