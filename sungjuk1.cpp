#pragma warning(disable : 4996) // C������ #define _CRT_SECURE_NO_WARNINGS
#include <iostream> // ��������� ������ ���� �ҽ��� Ȯ���ϵ��� �����ϴ� ��ó����
using namespace std; // �̸� �浹�� �߻��ϴ� ��츦 ����ϴ� namespace, std���� cout,cin,endl ���� ���� �Ǿ� �ִ�.

struct Subject { // ���� ���� ����ü
	char subName[30]; // ���� �̸�
	int hakjum; // ���� ����
	char grade[10]; // ���� ���
	double gpa; // ���� ����
};

struct Student { // �л� ����
	char stdName[30]; // �л� �̸�
	int stdNum; // �й�
	Subject sub[3]; // ����
	double aveGPA; // ������ ��� ����
};

struct Student student[2]; // �л� ����ü �� �� ����

void selectMenu(); // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

int main(void) { // ���� �޴� ȭ�� �����ִ� �Լ�
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. ���α׷� ����\n\n";
	selectMenu();
}

int menuNum; // ��� �Է� ���� ���� ���� 
int inputGrade(); // �л� ���� �Է� �Լ�
int allStudentGrade(); // �л� ���� �� ���� ���� ��� �Լ�

void selectMenu() { // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

	cout << "���ϴ� ����� �Է��ϼ��� : "; cin >> menuNum; // ����� �Է� �޴´�.
	cout << "\n";

	switch (menuNum)
	{
	case 1:
		inputGrade(); // �л� ���� �Է� �Լ�
		selectMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 2:
		allStudentGrade(); // ��ü �л� ���� ���� �Լ�
		selectMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 3:
		cout << "���α׷��� �����մϴ�.";
		exit(0); // ���α׷� ���� 
	}
}

int i, j;  // �ݺ����� ���� ���� ����

int inputGrade() { // �л� ���� �Է� �Լ�

	for (i = 0; i < 2; i++) // �� ���� �л� ������ �Է� �޴� ����
	{
		// ����ü�� ���� �Է� �ޱ�
		cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : "; cin >> student[i].stdName; 
		cout << "�й� : "; cin >> student[i].stdNum;
		cout << "\n\n";
		cout << "* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";

		for (j = 0; j < 3; j++) { // �� ���� ���� �Է� �ޱ�
			cout << "������� : "; cin >> student[i].sub[j].subName; // ����� �Է� �ޱ�
			cout << "���������� : "; cin >> student[i].sub[j].hakjum; // ���������� �Է� �ޱ�
			cout << "������<A+ ~ F> : "; cin >> student[i].sub[j].grade; // ������ �Է� �ޱ�
			cout << "\n";
		}
	}
	return 0;
}

void gpaConversion(int i, int j); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��� �����ڸ� �̿��� ���������� ���ϴ� �Լ�

double sumGPA[2] = {}; // ���� ������ ���ϴ� sumGPA �迭

int allStudentGrade() { // �л� ���� �� ���� ���� ��� �Լ�

	cout.width(10); // ����� ������ �� ����
	cout << "��ü �л�  ���� ����\n";
	cout << "========================================================================\n";

	for (i = 0; i < 2; i++) { // �л��� �� ���̿��� �� �� �ݺ�

		// ����ü�� �̿��� �л� ���� ���
		cout << "�̸� : " << student[i].stdName; 
		cout << " �й� : " << student[i].stdNum;
		cout << "\n========================================================================\n";
		cout << "           �����  ��������  ������  ��������\n";
		cout << "========================================================================\n";

		for (j = 0; j < 3; j++) {
			cout.width(15); // ����� ������ �� ����
			cout << student[i].sub[j].subName; // ���� �̸� ���
			cout.width(10); 
			cout << student[i].sub[j].hakjum; // ���������� ���
			cout.width(10); 
			cout << student[i].sub[j].grade; // ���� ��� ���
			cout.width(10); 

			gpaConversion(i, j); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��� �����ڸ� �̿��� ���������� ���ϴ� �Լ�

			cout.precision(2); // �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����
			cout << fixed;

			cout << student[i].sub[j].gpa; // �������� ���
			sumGPA[i] += student[i].sub[j].gpa; // ���� ������ ���ϴ� sumGPA �迭
			cout << "\n";
			cout << "========================================================================\n";
		}

		cout.width(50);
		cout << "�������     ";
		student[i].aveGPA = sumGPA[i] / 3.0 ; // ���� ������ ��� ���ؼ� ���� �� ��ŭ ���� ��� ����
		cout << student[i].aveGPA; // ��� ���� ���
		cout << "\n";
	}
	return 0;
}

void gpaConversion(int i, int j) { // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��� �����ڸ� �̿��� ���������� ���ϴ� �Լ�

	if (strcmp(student[i].sub[j].grade, "A+") == 0) // strcmp�� �̿��Ͽ� ����� Ȯ���Ѵ�.
	{
		strcpy(student[i].sub[j].grade, "4.5"); // strcpy�� �̿��Ͽ� ����� ������ ȯ���Ѵ�.
		double aa = atof(student[i].sub[j].grade); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��´�.
		student[i].sub[j].gpa = student[i].sub[j].hakjum * aa; // ���������� ������ ���� ���������� ���Ѵ�.
	}
	else if (strcmp(student[i].sub[j].grade, "A0") == 0)
	{
		strcpy(student[i].sub[j].grade, "4.0");
		double a = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * a;
	}
	else if (strcmp(student[i].sub[j].grade, "B+") == 0)
	{
		strcpy(student[i].sub[j].grade, "3.5");
		double bb = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * bb;
	}
	else if (strcmp(student[i].sub[j].grade, "B0") == 0)
	{
		strcpy(student[i].sub[j].grade, "3.0");
		double b = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * b;
	}
	else if (strcmp(student[i].sub[j].grade, "C+") == 0)
	{
		strcpy(student[i].sub[j].grade, "2.5");
		double cc = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * cc;
	}
	else if (strcmp(student[i].sub[j].grade, "C0") == 0)
	{
		strcpy(student[i].sub[j].grade, "2.0");
		double c = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * c;
	}
	else if (strcmp(student[i].sub[j].grade, "D+") == 0)
	{
		strcpy(student[i].sub[j].grade, "1.5");
		double dd = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * dd;
	}
	else if (strcmp(student[i].sub[j].grade, "D0") == 0)
	{
		strcpy(student[i].sub[j].grade, "1.0");
		double d = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * d;
	}
	else if (strcmp(student[i].sub[j].grade, "F") == 0)
	{
		strcpy(student[i].sub[j].grade, "0.0");
		double f = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * f;
	}
}