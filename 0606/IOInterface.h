// 이름: 김나영
// 학번: 2021041059

#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOInterface {
public: // 멤버함수

	virtual ~IOInterface() { // 가상 소멸자 
		cout << "IOInterface의 소멸자 호출\n";
	}

	void InputValue(string& str) { // 문자열 입력받는 인라인 함수
		getline(cin, str);
	}

	void InputValue(int& i) { // 정수 입력받는 인라인 함수
		cin >> i;
		cin.ignore();
	}

	virtual void InputData() = 0; // 순수가상함수

	virtual void PrintData() const = 0; // 순수가상함수

	virtual void Modify() = 0; // 순수가상함수
};