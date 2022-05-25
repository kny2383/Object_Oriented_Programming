// �̸�: �質��
// �й�: 2021041059

#include <iostream>
using namespace std;

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"

void Data(const Student& s) { // �������α׷��� �ִ� �����Լ�
	// const ��ü�� Get�Լ��� ȣ���� �� Get�Լ��� const�� �ƴϸ� ���� �߻���. 
	cout << s.GetName() << "�� ������ ������ ��" << s.GetSubNum() << "����";
	cout << "������ ������ ���������" << s.GetAveGPA() << "�Դϴ�.\n";
}
int main() {
	// �����ִ� ������ ȣ��
	Subject sub1("��ǻ��", 3, "C0"); // sub1 ����
	Subject sub2("����", 2, "A0"); // sub2 ����

	// static ����Լ� ȣ��
	Subject::PrintTitle(); // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���

	sub1.PrintData(); // sub1�� ��(�������, ������, ���, ����)�� ȭ�鿡 ���
	sub2.PrintData(); // sub2�� ��(�������, ������, ���, ����)�� ȭ�鿡 ���

	Student st1("ȫ�浿", 2013909845, 1, &sub1); // st1 ����
	st1.PrintData(); // st1�� �� ���
	Data(st1); // st1�� ���� ���
}