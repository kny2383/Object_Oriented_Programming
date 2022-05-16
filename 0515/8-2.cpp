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

	// Subject Class�� ����Լ��� ������ �Լ� �߰�
	// ������ �Լ� : public ���� ������ ���� ��� �Լ�
	// ��� ������ ���� �����ϰų� �о�� ��, ��� ������ ���� ���� ��ȿ�� �˻� ����
	string GetName() {
		return m_name; // m_name ����
	}
	int GetHakjum() {
		return m_hakjum; // m_hakjum ����
	}
	string GetGrade() {
		return m_grade; // m_grade ����
	}
	float GetGPA() {
		return m_GPA; // m_GPA ����
	}
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
	Subject sub2, sub3; //  
	int i; // �ݺ��� �� ����� ����
	sub2.Initialize("������", 3, "A+"); // ���ڰ����� ������� �ʱ�ȭ
	sub3.Initialize("��ǻ��", 3, "C ");  // ���ڰ����� ������� �ʱ�ȭ
	
	// ������ �Լ� TEST ��� �ڵ�
	cout << "\n" << "sub2 �̸�: " << sub2.GetName() << "\n"; 
	cout << "\n" << "sub2 ����: " << sub2.GetHakjum() << "\n";
	cout << "\n" << "sub2 ���: " << sub2.GetGrade() << "\n";
	cout << "\n" << "sub2 ����: " << sub2.GetGPA() << "\n";

	cout << "\n" << "sub3 �̸�: " << sub3.GetName() << "\n";
	cout << "\n" << "sub3 ����: " << sub3.GetHakjum() << "\n";
	cout << "\n" << "sub3 ���: " << sub3.GetGrade() << "\n";
	cout << "\n" << "sub3 ����: " << sub3.GetGPA() << "\n";
}