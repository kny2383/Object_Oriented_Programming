// �̸�: �質��
// �й�: 2021041059

#pragma once
#include <iostream>
#include <string>
using namespace std;

class IOInterface {
protected: // �������
	string m_name;
	int m_data;
public: // ����Լ�

	IOInterface() { // ����Ʈ ������ 
		cout << "IOInterface�� ����Ʈ ������ ȣ��\n";
		m_name = "";
		m_data = 0;
	}

	IOInterface(string m_name, int m_data) { // �����ִ� ������
		cout << "IOInterface�� �����ִ� ������ ȣ��\n";
		this->m_name = m_name; 
		this->m_data = m_data;
	}

	~IOInterface() { // �Ҹ��� 
		cout << "IOInterface�� �Ҹ��� ȣ��\n";
	}

	void InputValue(string& str) { // ���ڿ� �Է¹޴� �ζ��� �Լ�
		getline(cin, str);
	}

	void InputValue(int& i) { // ���� �Է¹޴� �ζ��� �Լ�
		cin >> i;
		cin.ignore();
	}

	void InputData() { // m_name, m_data�� ���� ȭ�����κ��� �Է�
		InputValue(m_name);
		InputValue(m_data);
	}

	void PrintData() const { // const �Լ�, m_name, m_data�� ���� ȭ�����κ��� ���
		cout << m_name;
		cout << m_data;
	}

	void Modify() { // m_name, m_data�� ���� ȭ�����κ��� �Է¹��� ������ ����
		cout << "m_name ���� �����ϼ��� : ";
		InputValue(m_name);
		cout << "m_data ���� �����ϼ��� : ";
		InputValue(m_data);
	}

	string GetName() const { // m_name�� ���� ������ �Լ�
		return m_name;
	}

	int GetData() const { // m_data�� ���� ������ �Լ�
		return m_data;
	}
};