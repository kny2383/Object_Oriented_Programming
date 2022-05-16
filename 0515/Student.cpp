// �̸�: �質��
// �й�: 2021041059

#include "Student.h" // ������Ͽ� ����
#include <iostream>
using namespace std;

void Student::Initialize() { // ��������� �� �ʱ�ȭ
	m_name = ""; // �л���
	m_hakbun = 0; // �й�
	m_subnum = 0; // �����
	m_sub = NULL; // ������ �����
	m_aveGPA = 0.0f; // ������ ������� ��� ����
}

void Student::Initialize(string stdName, int stdHakbun, int subnum, Subject* stdSub) { // ���ڰ����� ������� �ʱ�ȭ
	m_name = stdName; // �л���
	m_hakbun = stdHakbun; // �й�
	m_subnum = subnum; // �����
	m_sub = stdSub; // ������ �����
	CalcAveGPA(); // ������ ������� ��� ����
}

void Student::Remove() { // �����޸� ����(m_sub)
	delete[] m_sub;
}

void Student::InputValue(string& str) { //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	getline(cin, str);
}

void Student::InputValue(int& i) { // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	cin >> i;
	cin.ignore();
}

void Student::InputData() { // ������� �� �Է�
	// �л����� �Է�
	cout << "�̸� : ";
	InputValue(m_name); // �̸� �Է�
	cout << "�й� : ";
	InputValue(m_hakbun); // �й� �Է�

	// �������� �Է�
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData(); 
	}

	CalcAveGPA(); // ��� ���� ���
}

void Student::PrintData() { // ������� �� ���
	// �л� ���� title
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�̸� : ";
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << "�й� : ";
	cout.width(15);
	cout << m_hakbun << '\n';

	// ���� ���� title
	m_sub->PrintTitle();
	// ���� ���� ���
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].PrintData();
	}
	cout << "===============================================================\n";

	//�ش� �л��� ���� ��� ���� ���
	cout.width(45);
	cout << "������� : ";
	cout << m_aveGPA << '\n';
}

void Student::CalcAveGPA() { // ��� ���� ���
	float sumGPA = 0.0;

	for (int i = 0; i < m_subnum; i++) {
		//��� ������ ���� ����
		sumGPA += m_sub[i].GetGPA();
	}
	//���� ���� ��� ���� ����
	m_aveGPA = sumGPA / m_subnum;
}