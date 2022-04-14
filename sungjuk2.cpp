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

void PrintMenu(); // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

int main(void) { // ���� �޴� ȭ�� �����ִ� �Լ�

	PrintMenu();
}

int menuNum; // ��� �Է� ���� ���� ����  
int Num = 2; // �л� ��
int inputGrade(); // �л� ���� �Է� �Լ�
void PrintAllData(const Student* pSt, int StudentNum); // �л� ���� �� ���� ���� ��� �Լ�
Student* StdSearch(Student* pSt, int StudentNum);
void searchStd();

void PrintMenu() { // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : "; cin >> menuNum; // ����� �Է� �޴´�.
	cout << "\n";

	switch (menuNum)
	{
	case 1:
		inputGrade(); // �л� ���� �Է� �Լ�
		PrintMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 2:
		PrintAllData(student, Num); // ��ü �л� ���� ���� �Լ�
		PrintMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 3:
		searchStd(); // StdSearch() �Լ��� �����ϴ� �Լ�
		PrintMenu();
	case 4:
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

void CalcGPA(Subject& sub); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��� �����ڸ� �̿��� ���������� ���ϴ� �Լ�
double sumGPA[2] = {}; // ���� ������ ���ϴ� sumGPA �迭
double CalcAveGPA(Subject* sub); // ���� ��� ���� ���ϴ� �Լ�
double AveGPA = 0;
void PrintOneData(const Student& rSt);

void PrintAllData(const Student* pSt, int StudentNum) { // �л� ���� �� ���� ���� ��� �Լ�

	// pSt : �л������� ��� Student ������ ����
	// StudentNum : ��ü �л��� 

	cout.width(10); // ����� ������ �� ����
	cout << "��ü �л�  ���� ����\n";
	cout << "========================================================================\n";

	for (i = 0; i < StudentNum; i++) { // �л��� �� ���̿��� �� �� �ݺ�

		Student* pSt = &student[i];
		PrintOneData(*pSt);
	}
}

void reGPA(Subject& sub); // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�

void PrintOneData(const Student& rSt) { // rSt : �л������� ��� Student ���۷��� ����

	cout << "�̸� : " << rSt.stdName;
	cout << " �й� : " << rSt.stdNum;
	cout << "\n========================================================================\n";
	cout << "           �����  ��������  ������  ��������\n";
	cout << "========================================================================\n";

	for (j = 0; j < 3; j++) {
		cout.width(15); // ����� ������ �� ����
		cout << rSt.sub[j].subName; // ���� �̸� ���
		cout.width(10);
		cout << rSt.sub[j].hakjum; // ���������� ���
		cout.width(10);
		cout << rSt.sub[j].grade; // ���� ��� ���
		cout.width(10);

		CalcGPA(student[i].sub[j]); // �������� ���ϴ� �Լ�
		cout.precision(2); // �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����
		cout << fixed;
		cout << rSt.sub[j].gpa; // �������� ���

		AveGPA = CalcAveGPA(student[i].sub); // ���� ��� ���� ���ϴ� �Լ�
		cout << "\n";
		cout << "========================================================================\n";
	}
	cout.width(50);
	cout << "�������     ";
	cout << AveGPA; // ��� ���� ���
	cout << "\n";

	for (j = 0; j < 3; j++) {
		reGPA(student[i].sub[j]); // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�
	}

	sumGPA[i] = 0; // �л� ���� ��½� CalcAveGPA() �Լ� �������� ���� ��� ������ �� ��� ������ �̺�Ʈ ��Ȱ��ȭ�� ���� �ʱ�ȭ
}

void CalcGPA(Subject& sub) { // sub : ������ ������ ��� Subject ���۷��� ����

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

void reGPA(Subject& sub) { // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�
	if (strcmp(student[i].sub[j].grade, "4.5") == 0) // strcmp�� �̿��Ͽ� ���� ������ Ȯ��
	{
		strcpy(student[i].sub[j].grade, "A+"); // strcpy�� �̿��Ͽ� ���� ������ ������� ȯ��
	}
	else if (strcmp(student[i].sub[j].grade, "4.0") == 0)
	{
		strcpy(student[i].sub[j].grade, "A0");
	}
	else if (strcmp(student[i].sub[j].grade, "3.5") == 0)
	{
		strcpy(student[i].sub[j].grade, "B+");
	}
	else if (strcmp(student[i].sub[j].grade, "3.0") == 0)
	{
		strcpy(student[i].sub[j].grade, "B0");
	}
	else if (strcmp(student[i].sub[j].grade, "2.5") == 0)
	{
		strcpy(student[i].sub[j].grade, "C+");
	}
	else if (strcmp(student[i].sub[j].grade, "2.0") == 0)
	{
		strcpy(student[i].sub[j].grade, "C0");
	}
	else if (strcmp(student[i].sub[j].grade, "1.5") == 0)
	{
		strcpy(student[i].sub[j].grade, "D+");
	}
	else if (strcmp(student[i].sub[j].grade, "1.0") == 0)
	{
		strcpy(student[i].sub[j].grade, "D0");
	}
	else if (strcmp(student[i].sub[j].grade, "0.0") == 0)
	{
		strcpy(student[i].sub[j].grade, "F");
	}
}

double CalcAveGPA(Subject* sub) { // ���� ��� ���� ���ϴ� �Լ�

	sumGPA[i] += student[i].sub[j].gpa; // ���� ������ ���ϴ� sumGPA �迭
	student[i].aveGPA = sumGPA[i] / 3.0; // ���� ������ ��� ���ؼ� ���� �� ��ŭ ���� ��� ����
	AveGPA = student[i].aveGPA;

	return AveGPA;
}

char name[10]; // �˻��� �̸� ����

Student* StdSearch(Student* pSt, int StudentNum) { // Ư�� �л��� �̸��� �˻��ؼ� ������ �ִ� �ּ� �����ϴ� �Լ�
	// pSt: �л������� ��� Student ������ ����
	// ���ϰ� : �ش� �л��� ������ �ִ� ���� �ּ�

	cout << "�˻� �� �л� �̸� : "; cin >> name;
	cout << "\n";

	for (i = 0; i < StudentNum; i++) { // �˻��� ������ ���

		if (strcmp(name, pSt[i].stdName) == 0) { // �˻��� �̸��� ����ü�� ����� �̸� ��

			return &pSt[i]; // �ش� �л� ������ �ִ� �ּҸ� ����
		}
	}

	for (i = 0; i < StudentNum; i++) { // �˻��� ������ ���

		if (strcmp(name, pSt[i].stdName) != 0) { // �˻��� �̸��� ����ü�� ����� �̸� ��

			cout << "��ϵ��� ���� �����Դϴ�. �ٽ� �Է����ּ���\n\n";
			return NULL;
		}
	}
}

void searchStd() { // StdSearch() �Լ��� �����ϴ� �Լ�

	Student* SearchStd; // �л� �̸� Ž�� ����� ���� ����ü
	SearchStd = StdSearch(student, Num);
	if (SearchStd != NULL)
		PrintOneData(*SearchStd);
}