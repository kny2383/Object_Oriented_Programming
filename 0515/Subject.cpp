// �̸�: �質��
// �й�: 2021041059

#include "Student.h" // ������Ͽ� ����
#include <iostream>

void Subject::Initialize() { // ��������� �� �ʱ�ȭ
	m_name = ""; // �����
	m_hakjum = 0; // ����
	m_grade = ""; // ���
	m_GPA = 0.0f; // ����
}

// �����ε��� �̿��� �Ǵٸ� �ʱ�ȭ ���
// �����, ����, ����� ���ڰ�����, ������ ���� ����Ͽ� �־� ��(���� ��� �Լ� ȣ��)
void Subject::Initialize(string subName, int subHakjum, string subGrade) {
	m_name = subName; // �����
	m_hakjum = subHakjum; // ����
	m_grade = subGrade; // ���
	CalcGPA(); // ���� ��� �Լ� ȣ��
}

// ���� ����Ÿ�� ����ڷκ��� �Է¹��� �� ����ϴ� �ڵ带 ���� �����ε� �� �ζ����Լ�

void Subject::InputValue(string& str) { //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	getline(cin, str); 
}

void Subject::InputValue(int& i) { // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	cin >> i;
	cin.ignore();
}

void Subject::InputData() { // ��������� ���� ȭ�鿡�� �Է� ����
	// InputValue() �Լ� �̿��Ͽ� ���� ������ �Է�
	cout << "������� : ";
	InputValue(m_name);
	cout << "�������� : ";
	InputValue(m_hakjum);
	cout << "������(A+ ~ F) : ";
	InputValue(m_grade);
	cout << "\n";

	CalcGPA();
}

void Subject::PrintTitle() { // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "���";
	cout.width(15);
	cout << "����\n";
	cout << "===============================================================\n";
}

void Subject::PrintData() { // ��������� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
	// �������� ���
	cout.width(15);
	cout << m_name;
	cout.width(15);
	cout << m_hakjum;
	cout.width(15);
	cout << m_grade;
	cout.width(15);
	cout << m_GPA << '\n';
}

void Subject::CalcGPA() { // ���� ���
	float result;

	//�ش� ������ grade�� ���Ͽ� �ش��ϴ� ������ ����
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

	m_GPA = result * m_hakjum; // ���� ����
}