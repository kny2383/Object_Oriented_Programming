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
	Student std; // std��� �л� ��ü ����
	std.InputData(); // std�� ������� �� �Է�
	IOInterface* IO[2] = { new Subject("������",3,"A+"), &std }; // std�� ������ ���� ������ �Է��� ������ ���� ���� 
	for (int i = 0; i < 2; i++) { 
		cout << "\n * " << i + 1 << "��° ������ : " << "\n";
		IO[i]->PrintData(); // �Ļ�Ŭ������ ����Լ��� ȣ��Ǿ�� �� / ���� ���
	}
}