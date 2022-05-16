// �̸�: �質��
// �й�: 2021041059

#include <iostream>
using namespace std;

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"

// friend �Լ�: Ŭ������ ��� �Լ��� �ƴ� ���� �Լ��ε��� private, protected ����� ���� ������ �ӽ÷� ���Ǵ� �Լ�
void ShowData(const Student &); // Student.h�� ����� friend �Լ�

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

	ShowData(st1); // �������α׷��� �ִ� �����Լ�
	ShowData(st2); // �������α׷��� �ִ� �����Լ�
	st1.Remove(); // �����޸� ����(m_sub)
	
	return 0;
}

void ShowData(const Student &s) { // �������α׷��� �ִ� �����Լ�
	cout << s.m_name << "�� ������ ������ ��" << s.m_subnum << "����";
	cout << "������ ������ ���������" << s.m_aveGPA << "�Դϴ�.\n";
}