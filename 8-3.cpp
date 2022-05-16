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

class Student { // �л� Ŭ����
protected: // Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
	string m_name;	// �л���
	int m_hakbun;	// �й�
	int m_subnum;	// ������ ���� �� 
	Subject* m_sub;	// ������ �����
	float m_aveGPA;	// ������ ������� ��� ����
public: // ��� �ٸ� Ŭ������ ���. Ŭ���� �ۿ��� ���� ���� ����
	void Initialize();	// ������� �ʱ�ȭ
	void Initialize(string, int, int, Subject*);	// ���ڰ����� ������� �ʱ�ȭ
	void Remove();		// �����޸� ����(m_sub)
	void InputValue(int&); // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	void InputValue(string&); //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	void InputData();	// ������� �� �Է�
	void PrintData();	// ������� �� ���
	void CalcAveGPA();	// ��� ���� ���

	//Subject Class�� ����Լ��� ������ �Լ� �߰�
	// ������ �Լ� : public ���� ������ ���� ��� �Լ�
    // ��� ������ ���� �����ϰų� �о�� ��, ��� ������ ���� ���� ��ȿ�� �˻� ����
	string GetName() {
		return m_name;
	}
	int GetHakbun() {
		return m_hakbun;
	}
	int GetSubNum() {
		return m_subnum;
	}
	float GetAveGPA() {
		return m_aveGPA;
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

void Student::InputValue(int& i) { // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	cin >> i;
	cin.ignore();
}

void Student::InputValue(string& str) { //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	getline(cin, str);
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

int main() {
	Subject sub[2]; // ���� ��ü ����
	sub[0].Initialize("��ǻ��", 3, "C"); // �ʱ�ȭ
	sub[1].Initialize("���빫��", 2, "A"); // �ʱ�ȭ
	Student st1, st2; // �л� ��ü ����
	st1.Initialize("TEST", 0, 2, new Subject[2]); // �ʱ�ȭ
	st2.Initialize("ȫ�浿", 2013909845, 2, sub); // �ʱ�ȭ
	st1.InputData(); // ���� �Է�
	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData(); // ���� ���
	cout << "\n" << "st2 ����" << "\n";
	st2.PrintData(); // ���� ���
	st1.Remove(); // �����޸� ����(m_sub)
}