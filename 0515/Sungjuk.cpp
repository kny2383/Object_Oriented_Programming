// �̸�: �質��
// �й�: 2021041059

#include <iostream>	
using namespace std;

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"

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