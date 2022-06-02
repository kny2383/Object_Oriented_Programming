// 이름: 김나영
// 학번: 2021041059

#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOInterface {
protected: // 멤버변수
	string m_name;
	int m_data;
public: // 멤버함수

	IOInterface() { // 디폴트 생성자 
		cout << "IOInterface의 디폴트 생성자 호출\n";
		m_name = "";
		m_data = 0;
	}

	IOInterface(string m_name, int m_data) { // 인자있는 생성자
		cout << "IOInterface의 인자있는 생성자 호출\n";
		this->m_name = m_name; 
		this->m_data = m_data;
	}

	~IOInterface() { // 소멸자 
		cout << "IOInterface의 소멸자 호출\n";
	}

	void InputValue(string& str) { // 문자열 입력받는 인라인 함수
		getline(cin, str);
	}

	void InputValue(int& i) { // 정수 입력받는 인라인 함수
		cin >> i;
		cin.ignore();
	}

	void InputData() { // m_name, m_data의 값을 화면으로부터 입력
		InputValue(m_name);
		InputValue(m_data);
	}

	void PrintData() const { // const 함수, m_name, m_data의 값을 화면으로부터 출력
		cout << m_name;
		cout << m_data;
	}

	void Modify() { // m_name, m_data의 값을 화면으로부터 입력받은 값으로 수정
		cout << "m_name 값을 수정하세요 : ";
		InputValue(m_name);
		cout << "m_data 값을 수정하세요 : ";
		InputValue(m_data);
	}

	string GetName() const { // m_name에 대한 접근자 함수
		return m_name;
	}

	int GetData() const { // m_data에 대한 접근자 함수
		return m_data;
	}
};