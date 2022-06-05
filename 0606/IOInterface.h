// �̸�: �質��
// �й�: 2021041059

#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOInterface {
public: // ����Լ�

	virtual ~IOInterface() { // ���� �Ҹ��� 
		cout << "IOInterface�� �Ҹ��� ȣ��\n";
	}

	void InputValue(string& str) { // ���ڿ� �Է¹޴� �ζ��� �Լ�
		getline(cin, str);
	}

	void InputValue(int& i) { // ���� �Է¹޴� �ζ��� �Լ�
		cin >> i;
		cin.ignore();
	}

	virtual void InputData() = 0; // ���������Լ�

	virtual void PrintData() const = 0; // ���������Լ�

	virtual void Modify() = 0; // ���������Լ�
};