// �̸�: �質��
// �й�: 2021041059

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

void main() {
	Subject sub("��ǻ��", 3, "C0"); // sub ��ü ����
	Student std("ȫ�浿", 20138342, 1, &sub); // std ��ü ����

	std.PrintData(); // ���� ���� ������ ���
	std.Modify(); // Student Class�� ������� �� ����
	std.PrintData(); // ���� ���� ������ ���
}