// �̸�: �質��
// �й�: 2021041059

#include <iostream>	
#include <string> // ���ڿ� ���
using namespace std;

class Subject { // ���� Ŭ����
protected: // Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
	string m_name;	// �����
	int m_hakjum;	// ����
	string m_grade;	// ���
	float m_GPA;	// ����
public: // ��� �ٸ� Ŭ������ ���. Ŭ���� �ۿ��� ���� ���� ����
	void Initialize();	// ������� �ʱ�ȭ
	void Initialize(string, int, string);	// ���ڰ����� ������� �ʱ�ȭ
	void InputValue(int&); // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	void InputValue(string&); //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	void InputData();	// ������� �� �Է�
	void PrintTitle();	// ��������� ���� title Text ���
	void PrintData();	// ������� �� ���
	void CalcGPA();		// ���� ���
};

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

void Subject::InputValue(int& i) { // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	cin >> i;
	cin.ignore();
}

void Subject::InputValue(string& str) { //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	getline(cin, str);
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

void main() {
	Subject sub1, sub2, sub3[2], *sub4; 
	int i; // �ݺ��� �� ����� ����
	sub1.Initialize(); // �ʱ�ȭ�� �⺻�������θ� ��
	sub2.Initialize("������", 3, "A+"); // ���ڰ����� ������� �ʱ�ȭ
	for (i = 0; i < 2; i++)
		sub3[i].Initialize("��ǻ��", 3, "C ");  // ���ڰ����� ������� �ʱ�ȭ
	sub4 = new Subject[2]; // Subject�� �����Ҵ��� sub4
	sub1.InputData(); // sub1�� ȭ�鿡�� �Է�
	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintTitle(); // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
	sub1.PrintData(); // ��������� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
	cout << "\n" << "sub2 ����" << "\n";
	sub2.PrintTitle(); // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
	sub2.PrintData(); // ��������� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
	cout << "\n" << "sub3 ����" << "\n";
	sub3[0].PrintTitle(); // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
	for (i = 0; i < 2; i++)
		sub3[i].PrintData(); // ��������� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
	for (i = 0; i < 2; i++)
		(sub4 + i)->InputData(); // // ��������� ���� ȭ�鿡�� �Է� ����
	cout << "\n" << "sub4 ����" << "\n";
	sub4->PrintTitle(); // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
	for (i = 0; i < 2; i++)
		(sub4 + i)->PrintData(); // ��������� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
	delete[] sub4; // �����Ҵ� ����
}