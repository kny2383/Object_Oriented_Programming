// �̸�: �質��
// �й�: 2021041059

#include "Subject.h" // ������Ͽ� ����
#include <iostream>
using namespace std;

// �����ڿ� �Ҹ��ڴ� ���� ���� ����.
Subject::Subject() { // ����Ʈ �����ڷ� ��������� �� �ʱ�ȭ
	// ����Ʈ �����ڶ� �Ű� ���� ���� ������, �⺻ �������̴�.
	// ��ü�� ������ �� ������ �������� ������ �׻� ����Ʈ �����ڷ� �ʱ�ȭ�ȴ�.
	m_name = ""; // �����
	m_hakjum = 0; // ����
	m_grade = ""; // ���
	m_GPA = 0.0f; // ����
	cout << "Subject ����Ʈ ������\n";
}

// �����ִ� ������ (�����ڴ� �����ε��� �����ϴ�)
// �����, ����, ����� ���ڰ�����, ������ ���� ����Ͽ� �־� ��(���� ��� �Լ� ȣ��)
Subject::Subject(string subName, int subHakjum, string subGrade) {
	m_name = subName; // �����
	m_hakjum = subHakjum; // ����
	m_grade = subGrade; // ���
	CalcGPA(); // ���� ��� �Լ� ȣ��
	cout << "Subject �����ִ� ������\n";
}

// ���� ������ : ���� Ŭ������ �ٸ� ��ü�� ���� ���� ������ �ʱ�ȭ
Subject::Subject(const Subject& sub) { // �ٸ� Subject Ŭ������ ��������� ������ �ʱ�ȭ
	m_name = sub.m_name; // �����
	m_hakjum = sub.m_hakjum; // ����
	m_grade = sub.m_grade; // ���
	m_GPA = sub.m_GPA;
	cout << "Subject ���� ������\n";
}

// �Ҹ��� : ��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� �Լ�
Subject::~Subject() {
	cout << "Subject �Ҹ���\n";
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

void Subject::PrintData() const { // ��������� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
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

void Subject::Modify() { // ������� �� ����
	cout << "< " << m_name << ", " << m_hakjum << ", " << m_grade << ">�� ������ �����ϼ���.\n";

	// ȭ�鿡�� �ԷµǴ� �����ͷ� Subject Class�� ������� �� ����
	cout << "������� : "; InputValue(m_name);
	cout << "���� : "; InputValue(m_hakjum);
	cout << "��� : "; InputValue(m_grade);

	CalcGPA(); // ��������� �����Ǹ� ������ ����Ǿ�� ��.
}
