// �̸�: �質��
// �й�: 2021041059

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"
#include "GradeManager.h"
#include <iostream>
#include <string>
using namespace std;

void main() {
	int stdnum;
	cout << "�Է��� �л� ���� �Է� : ";
	cin >> stdnum;
	// Student::InputValue(stdnum);
	cout << endl;
	GradeManager GradeMgr(stdnum); // stdnum �л� �� ��ŭ GradeManager ��ü ����
	GradeMgr.Execute(); // ����ڰ� �Է��� �޴� ��ȣ�� ���� ���� �ؾ� �� �Լ� ȣ��
}