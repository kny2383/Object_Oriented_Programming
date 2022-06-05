// �̸�: �質��
// �й�: 2021041059

#include "GradeManager.h" // ������Ͽ� ����
#include "Student.h"
#include <iostream>
using namespace std;

int menuNum; // ��� �Է� ���� ���� ����
string stdname; // �л� �̸� ���� ����

GradeManager::GradeManager() { // ����Ʈ ������
	m_std = 0; // �л� ��ü
	m_stdnum = 0; // ��ü �л� ��
}

GradeManager::GradeManager(int m_stdNum) { // �����ִ� ������
	m_stdnum = m_stdNum; // ���ڰ����� 
	m_std = new Student[m_stdnum]; // m_std�� m_stdnum ��ŭ �����Ҵ�
}

GradeManager::~GradeManager() { // �Ҹ���. �����Ҵ� ���� m_std ����
	delete m_std; // ����
}

void GradeManager::PrintMenu() { // ��ü �޴� ���
	cout << endl;
	cout << "===== �޴� =====" << endl;
	cout << "1. �л� ���� �Է�" << endl; 
	cout << "2. ��ü ���� ����" << endl; 
	cout<< "3. �л� �˻�" << endl;
	cout << "4. �л� ��� ����" << endl;
	cout << "5. �л� ���� ����" << endl;
	cout << "6. ���α׷� ����" << endl;
	cout << endl;
	cout << "���ϴ� ����� �Է��ϼ���(��ȣ�Է�) : ";
	cin >> menuNum; // �޴� �Է� ����
}

void GradeManager::Execute() {
	while (1) {
		PrintMenu(); // ��ü �޴� ��� �Լ�

		if (menuNum == 1) {
			cin.ignore();
			for (int i = 0; i < m_stdnum; i++) {
				m_std[i].Student::InputData(); // ���� �Է� �ޱ�
			}
		}
		else if (menuNum == 2) {
			for (int i = 0; i < m_stdnum; i++) {
				m_std[i].Student::PrintData(); // ���� ��� 
			}
		}
		else if (menuNum == 3) {
			cout << "ã������ �л��� �̸��� �Է��ϼ��� : ";
			cin >> stdname; // �л� �̸� �Է� �ޱ�
			Student* std = StdSearch(stdname); // �Է� ���� �л� �˻�
		}
		else if (menuNum == 4) {
			PrintAllStdList(); // ��ü �л� ��� ���
		}
		else if (menuNum == 5) {
			Modify(); // ���ϴ� �л��� ���� ����
		}
		else if (menuNum == 6) {
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		}
		//��µ� �޴��� ���� ��ȣ�� �������� ���
		else {
			cout << "���� �޴� ��ȣ�� �����ϼ̽��ϴ�." << endl;
		}
	}
}

Student* GradeManager::StdSearch(string stdname) const { // �л� �˻�
	for (int i = 0; i < m_stdnum; i++) { // �л� �� ��ŭ �ݺ�
		if (stdname == m_std[i].GetName()) { // �л� �̸� ��
			return &m_std[i]; // �ּ� ����
		}
		else { // �ش� �л��� ���� ���
			cout << "ã���ô� �л��� ����." << endl;
			return NULL;
		}
	}
}

void GradeManager::PrintAllStdList() const {
	cout << "========================================" << endl;
	cout.width(15);
	cout << "�̸�";
	cout.width(15);
	cout << "�й�";
	cout << endl;
	cout << "========================================" << endl;
	for (int i = 0; i < m_stdnum; i++) {
		cout.width(15);
		cout << m_std[i].GetName(); // �л� �̸� ���
		cout.width(15);
		cout << m_std[i].GetHakbun(); // �л� �й� ���
		cout << endl;
	}
	cout << "========================================" << endl;
}

void GradeManager::Modify() {
	Student* std = NULL; // ã�����ϴ� �л� �̸�

	cout << "������ �л��� �̸��� �Է��ϼ��� : ";
	cin >> stdname; 
	std = StdSearch(stdname); // �л������� �ִ� �޸� �ּ� ���� ��
	  // �Է��� ���� �̸��� �����ϴ� ����� ��ġ�ϴ��� ��
	cin.ignore();
	if (std != NULL) { // ���� ������
		std->Student::Modify(); // �˻��� �л� ���� ����
	}
	else {
		cout << "�˻��� �л��� �����ϴ�. �ٽ� �˻��ϼ���.\n";
	}
}