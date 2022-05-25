// �̸�: �質��
// �й�: 2021041059

#include <iostream>
using namespace std;

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"

void main() {
	// ��ü �迭 ���� �� �ʱ�ȭ {} �ȿ� ������ ����
	Subject sub1[2] = { Subject("��ǻ��", 3, "C0"), Subject("���빫��", 2, "A0") }; // Subject �����ִ� ������ 2�� ȣ��
	// ������ ��ü �迭 ���� �� �ʱ�ȭ, ��ü�� ���� ����
	Subject* sub2[2] = { new Subject(), new Subject("����", 3, "C0") }; // Subject ����Ʈ ������ ȣ��, Subject �����ִ� ������ ȣ��

	Student st1; // st1 �л� ��ü ����, Student ����Ʈ ������ ȣ��, Subject ����Ʈ ������ ȣ��
	Student st2("ȫ�浿", 2013909845, 2, sub1); // st2 ��ü ����, Subject ����Ʈ ������ ȣ��, Student �����ִ� ������ ȣ��
	Student* st3 = new Student[2]; // ����Ʈ �����ڷ� �ʱ�ȭ�� st3 ������ ����, Student ����Ʈ ������ 2�� ȣ��
	cout << "\n" << "sub2[0] �Է�" << "\n";
		sub2[0]->InputData(); // �����ͷ� ��� ����
	cout << "\n" << "st1 �Է�" << "\n";
	st1.InputData(); // st1 ���� �Է�
	cout << "\n" << "st3 �Է�" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->InputData(); // �����ͷ� ��� ����, Subject ����Ʈ ������ �ݺ��� �� ������ ȣ��
	cout << "\n" << "sub1 ���� ���" << "\n";
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++) 
		sub1[i].PrintData(); // sub1 ���� ��� : [��ǻ��, 3, C0], [���빫��,2,A0]
	cout << "\n" << "sub2 ���� ���" << "\n";
	Subject::PrintTitle();
	for (int i = 0; i < 2; i++) 
		sub2[i]->PrintData(); // sub2 ���� ��� : �Է��� ����� ���� ���� ����
	cout << "\n" << "st1 ���� ���" << "\n";
	st1.PrintData(); // st1 ���� ���
	cout << "\n" << "st2 ���� ���" << "\n";
	st2.PrintData(); // st2 ���� ��� :  ȫ�浿�� sub1 ���� ������ ��������
	cout << "\n" << "st3 ���� ���" << "\n";
	for (int i = 0; i < 2; i++) 
		(st3 + i)->PrintData(); // st3 ���� ��� : �Է��� st3�� �������װ� ���� ���� ���

	// Student �Ҹ��� ȣ��
	// Subject �Ҹ��� ȣ��
	// Subject �Ҹ��� ȣ��
	// Student �Ҹ��� ȣ��
	// Subject �Ҹ��� ȣ��
	// Subject �Ҹ��� ȣ��
	// Subject �Ҹ��� ȣ��
}