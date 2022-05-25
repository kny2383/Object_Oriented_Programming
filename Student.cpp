// �̸�: �質��
// �й�: 2021041059

#include "Student.h" // ������Ͽ� ����
#include <iostream>
using namespace std;

// �����ڿ� �Ҹ��ڴ� ���� ���� ����.
Student::Student() { // ����Ʈ �����ڷ� ��������� �� �ʱ�ȭ
	// ����Ʈ �����ڶ� �Ű� ���� ���� ������, �⺻ �������̴�.
	// ��ü�� ������ �� ������ �������� ������ �׻� ����Ʈ �����ڷ� �ʱ�ȭ�ȴ�.
	m_name = ""; // �л���
	m_hakbun = 0; // �й�
	m_subnum = 0; // �����
	m_sub = NULL; // ������ �����
	m_aveGPA = 0.0f; // ������ ������� ��� ����
	cout << "Student ����Ʈ ������\n";
}

// �����ִ� ������ (�����ڴ� �����ε��� �����ϴ�)
// �����, ����, ����� ���ڰ�����, ������ ���� ����Ͽ� �־� ��(���� ��� �Լ� ȣ��)
Student::Student(string stdName, int stdHakbun, int subnum, Subject* stdSub) { 
	m_name = stdName; // �л���
	m_hakbun = stdHakbun; // �й�
	m_subnum = subnum; // �����
	m_sub = new Subject[m_subnum]; // ���� ���� -> ���� �޸� �Ҵ�
	for (int i = 0; i < m_subnum; i++) { // ������ �Լ� ���(Ŭ������ ��� ������ ���� ������ �����ִ� ���)
		m_sub[i].SetName(stdSub[i].GetName());
		m_sub[i].SetHakjum(stdSub[i].GetHakjum());
		m_sub[i].SetGrade(stdSub[i].GetGrade());
		m_sub[i].SetGPA(stdSub[i].GetGPA());
	}
	CalcAveGPA(); // ������ ������� ��� ����
	cout << "Student �����ִ� ������\n";
}

// ���� ������ : ���� Ŭ������ �ٸ� ��ü�� ���� ���� ������ �ʱ�ȭ
Student::Student(const Student& std) {  // �ٸ� Subject Ŭ������ ��������� ������ �ʱ�ȭ
	m_name = std.m_name; 
	m_hakbun = std.m_hakbun;
	m_subnum = std.m_subnum;
	m_sub = new Subject[m_subnum]; // ���� ���� -> ���� �޸� �Ҵ�
	for (int i = 0; i < m_subnum; i++) { // ������ �Լ� ���(Ŭ������ ��� ������ ���� ������ �����ִ� ���)
		m_sub[i].SetName(std.m_sub[i].GetName());
		m_sub[i].SetHakjum(std.m_sub[i].GetHakjum());
		m_sub[i].SetGrade(std.m_sub[i].GetGrade());
		m_sub[i].SetGPA(std.m_sub[i].GetGPA());
	}
	m_aveGPA = std.m_aveGPA;
	cout << "Student ���� ������\n";
}

Subject * Student::SubSearch(string subname) const { // ���� �˻� �Լ�
	
	for (int i = 0; i < m_subnum; i++) { // �������ŭ �ݺ�
		if (subname == m_sub[i].GetName()) { // ����� ��
			return &m_sub[i]; // �ּ� ����
		}
		else { // �ش� ������ ���� ���
			cout << "�˻��� �������� �����ϴ�.\n";
			return NULL;
		}
	}
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

	cout << "���� �� : "; 
	InputValue(m_subnum); // ���� �� �Է�

	m_sub = new Subject[m_subnum]; // ���� �� ��ŭ ���� �޸� �Ҵ�
	// �������� �Է�
	for (int i = 0; i < m_subnum; i++) {
		m_sub[i].InputData(); 
	}

	CalcAveGPA(); // ��� ���� ���
}

void Student::PrintData() const { // ������� �� ���
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

void Student::StdModify() { // �л� ���� ����
	cout << "<" << m_name << ", " << m_hakbun << ">�� ������ �����ϼ���\n";

	cout << "�̸� : "; InputValue(m_name);
	cout << "�й� : "; InputValue(m_hakbun);
}

void Student::Modify() { // ���� ����

	string Type; // �޴� �Է� �޴� string
	//�����ϰ��� ���� �Է�
	cout << "\n������ ������ �����ϼ��� <�л����� / �������� / ���> : ";
	InputValue(Type);
	cout << '\n';

	//�л� ������ �Է��� ���
	if (Type == "�л� ����" || Type == "�л�����") {
		StdModify(); // �л� ���� ���� 
	}
	//���� ������ �Է��� ���
	else if (Type == "���� ����" || Type == "��������") {
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify(); // ���� ���� ����
		}
		CalcAveGPA(); // ������� ������ ���� ���� �� ������� ����
	}
	else if (Type == "���") {
		StdModify(); // �л� ���� ����
		for (int i = 0; i < m_subnum; i++) {
			m_sub[i].Modify(); // ���� ���� ����
		}
		CalcAveGPA(); // ������� ������ ���� ���� �� ������� ����
	}
	//�߸� �Է��� ���
	else {
		cout << "<�����ϰ��� �ϴ� ������ ��Ȯ�� �Է����ּ���.>\n\n";
	}
}

// �Ҹ��� : ��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� �Լ�
Student::~Student() { // ���� �Ҵ� ���� �޸� ����
	cout << "Student �Ҹ���\n";
	delete[] m_sub;
	m_sub = NULL;
}