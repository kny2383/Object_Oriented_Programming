// sub ���� �Ҵ� ���� �ذ��ؾ���

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
	int Hakbun; // �й�
	Subject *sub; // ����
	int SubNum; // ���� ��
	double aveGPA; // ������ ��� ����
};

int i, j;  // �ݺ����� ���� ���� ����
int StdNum;
Student* St = new Student[StdNum]; // �л� ����ü ���� �Ҵ�


void PrintMenu(); // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

int main(void) { // ���� �޴� ȭ�� �����ִ� �Լ�

	PrintMenu();
}

int menuNum; // ��� �Է� ���� ���� ����  
void InputData(Student* pSt, int StudentNum); // �л� ���� �Է� �Լ�
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
		cout << "�л� �� : "; cin >> StdNum;
		InputData(St,StdNum); // �л� ���� �Է� �Լ�
		PrintMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 2:
		PrintAllData(St, StdNum); // ��ü �л� ���� ���� �Լ�
		PrintMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 3:
		searchStd(); // StdSearch() �Լ��� �����ϴ� �Լ�
		PrintMenu();
	case 4:
		cout << "���α׷��� �����մϴ�.";
		exit(0); // ���α׷� ���� 
	}
}

void InputData(Student *pSt, int StudentNum) { // �л� ���� �Է� �Լ�

	// pSt : ������ �л����� ������ �Ű�����
	// StudentNum : ��ü �л� ��

	for (i = 0; i < StudentNum; i++)
	{
		// ����ü�� ���� �Է� �ޱ�
		cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : "; cin >> pSt[i].stdName;
		cout << "�й� : "; cin >> pSt[i].Hakbun;
		cout << "���� �� : "; cin >> pSt[i].SubNum;
		Subject* sub = new Subject[pSt[i].SubNum]; // ���� �� �����Ҵ� 
		cout << "\n\n";

		cout << "* ������ ����" << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";

		for (j = 0; j < pSt[i].SubNum; j++) { // ���� ���� �Է� �ޱ�
			cout << "������� : "; cin >> sub->subName; // ����� �Է� �ޱ�
			cout << "���������� : "; cin >> sub->hakjum; // ���������� �Է� �ޱ�
			cout << "������<A+ ~ F> : "; cin >> sub->grade; // ������ �Է� �ޱ�
			cout << "\n";
		}
	}
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

		Student* pSt = &St[i];
		PrintOneData (*(pSt+i));
	}
}

void reGPA(Subject& sub); // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�

void PrintOneData(const Student& rSt) { // rSt : �л������� ��� Student ���۷��� ����

	cout << "�̸� : " << rSt.stdName;
	cout << " �й� : " << rSt.Hakbun;
	cout << "\n========================================================================\n";
	cout << "           �����  ��������  ������  ��������\n";
	cout << "========================================================================\n";

	for (j = 0; j < rSt.SubNum; j++) {
		cout.width(15); // ����� ������ �� ����
		cout << rSt.sub[j].subName; // ���� �̸� ���
		cout.width(10);
		cout << rSt.sub->hakjum; // ���������� ���
		cout.width(10);
		cout << rSt.sub[j].grade; // ���� ��� ���
		cout.width(10);

		CalcGPA(*rSt.sub); // �������� ���ϴ� �Լ�
		cout.precision(2); // �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����
		cout << fixed;
		cout << rSt.sub[j].gpa; // �������� ���

		AveGPA = CalcAveGPA(rSt.sub); // ���� ��� ���� ���ϴ� �Լ�
		cout << "\n";
		cout << "========================================================================\n";
	}
	cout.width(50);
	cout << "�������     ";
	cout << AveGPA; // ��� ���� ���
	cout << "\n";

	for (j = 0; j < rSt.SubNum; j++) {
		reGPA(rSt.sub[j]); // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�
	}

	sumGPA[i] = 0; // �л� ���� ��½� CalcAveGPA() �Լ� �������� ���� ��� ������ �� ��� ������ �̺�Ʈ ��Ȱ��ȭ�� ���� �ʱ�ȭ
}

void CalcGPA(Subject& sub) { // sub : ������ ������ ��� Subject ���۷��� ����

	if (strcmp(St[i].sub[j].grade, "A+") == 0) // strcmp�� �̿��Ͽ� ����� Ȯ���Ѵ�.
	{
		strcpy(St[i].sub[j].grade, "4.5"); // strcpy�� �̿��Ͽ� ����� ������ ȯ���Ѵ�.
		double aa = atof(St[i].sub[j].grade); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��´�.
		St[i].sub[j].gpa = St[i].sub[j].hakjum * aa; // ���������� ������ ���� ���������� ���Ѵ�.
	}
	else if (strcmp(St[i].sub[j].grade, "A0") == 0)
	{
		strcpy(St[i].sub[j].grade, "4.0");
		double a = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * a;
	}
	else if (strcmp(St[i].sub[j].grade, "B+") == 0)
	{
		strcpy(St[i].sub[j].grade, "3.5");
		double bb = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * bb;
	}
	else if (strcmp(St[i].sub[j].grade, "B0") == 0)
	{
		strcpy(St[i].sub[j].grade, "3.0");
		double b = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * b;
	}
	else if (strcmp(St[i].sub[j].grade, "C+") == 0)
	{
		strcpy(St[i].sub[j].grade, "2.5");
		double cc = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * cc;
	}
	else if (strcmp(St[i].sub[j].grade, "C0") == 0)
	{
		strcpy(St[i].sub[j].grade, "2.0");
		double c = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * c;
	}
	else if (strcmp(St[i].sub[j].grade, "D+") == 0)
	{
		strcpy(St[i].sub[j].grade, "1.5");
		double dd = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * dd;
	}
	else if (strcmp(St[i].sub[j].grade, "D0") == 0)
	{
		strcpy(St[i].sub[j].grade, "1.0");
		double d = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * d;
	}
	else if (strcmp(St[i].sub[j].grade, "F") == 0)
	{
		strcpy(St[i].sub[j].grade, "0.0");
		double f = atof(St[i].sub[j].grade);
		St[i].sub[j].gpa = St[i].sub[j].hakjum * f;
	}
}

void reGPA(Subject& sub) { // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�
	if (strcmp(St[i].sub[j].grade, "4.5") == 0) // strcmp�� �̿��Ͽ� ���� ������ Ȯ��
	{
		strcpy(St[i].sub[j].grade, "A+"); // strcpy�� �̿��Ͽ� ���� ������ ������� ȯ��
	}
	else if (strcmp(St[i].sub[j].grade, "4.0") == 0)
	{
		strcpy(St[i].sub[j].grade, "A0");
	}
	else if (strcmp(St[i].sub[j].grade, "3.5") == 0)
	{
		strcpy(St[i].sub[j].grade, "B+");
	}
	else if (strcmp(St[i].sub[j].grade, "3.0") == 0)
	{
		strcpy(St[i].sub[j].grade, "B0");
	}
	else if (strcmp(St[i].sub[j].grade, "2.5") == 0)
	{
		strcpy(St[i].sub[j].grade, "C+");
	}
	else if (strcmp(St[i].sub[j].grade, "2.0") == 0)
	{
		strcpy(St[i].sub[j].grade, "C0");
	}
	else if (strcmp(St[i].sub[j].grade, "1.5") == 0)
	{
		strcpy(St[i].sub[j].grade, "D+");
	}
	else if (strcmp(St[i].sub[j].grade, "1.0") == 0)
	{
		strcpy(St[i].sub[j].grade, "D0");
	}
	else if (strcmp(St[i].sub[j].grade, "0.0") == 0)
	{
		strcpy(St[i].sub[j].grade, "F");
	}
}

double CalcAveGPA(Subject* sub) { // ���� ��� ���� ���ϴ� �Լ�

	sumGPA[i] += St[i].sub[j].gpa; // ���� ������ ���ϴ� sumGPA �迭
	St[i].aveGPA = sumGPA[i] / 3.0; // ���� ������ ��� ���ؼ� ���� �� ��ŭ ���� ��� ����
	AveGPA = St[i].aveGPA;

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
	SearchStd = StdSearch(St, StdNum);
	if (SearchStd != NULL)
		PrintOneData(*SearchStd);
}