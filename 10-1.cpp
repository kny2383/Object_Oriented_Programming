// �̸�: �質��
// �й�: 2021041059

#include <iostream>
using namespace std;

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"

int main() {
	// Student ����Ʈ ������ ȣ��
	Student std; 
	std.InputData(); // ������� �� �Է�
	std.PrintData(); // ������� �� ���
	Subject* sub = std.SubSearch("������"); // �������̶�� ���� ����
	// ������� ���������� Ž���� ���
	// �ش� ���������� �ִ� �޸� �ּҸ� ����
	if (sub != NULL) {
		sub->PrintTitle(); // ��������� ���� title Text ���
		sub->PrintData(); // ������� �� ���
	}
}