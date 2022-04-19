// 04/12 ������ 
// sub[1]�� ��µǰ� ù��° �л� ���� ��½� sub[0]�� ��� �ȵ�

// 04/13 ������
// 04/12 �������� ����

// 04/14 �� ������ �ذ�
// PrintAllData()�Լ����� �迭�� ������ �� '->' ���� '.' ����ϴϱ� �ذ��.

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
	Subject* sub = nullptr; // ����
	int SubNum; // ���� ��
	double aveGPA; // ������ ��� ����
};

int i, j;  // �ݺ����� ���� ���� ����
int StdNum;
int menuNum; // ��� �Է� ���� ���� ����  

Student* St = nullptr; // �л� �� �����Ҵ� �ʱ�ȭ

void PrintMenu(); // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�
void InputData(Student* pSt, int StudentNum); // �л� ���� �Է� �Լ�
void PrintAllData(const Student* pSt, int StudentNum); // �л� ���� �� ���� ���� ��� �Լ�
Student* StdSearch(Student* pSt, int StudentNum); // �л� ���� �˻� �Լ�
void PrintOneData(const Student& rSt); // �л� ���� ��� �Լ�

// �л������� ���� �����ϰ� �޴� �ζ��� �Լ�
inline void InputValue(char* str) { 
	cin >> str;
}

inline void InputValue(int& i) {
	cin >> i;
}

int main(void) { // ���� �޴� ȭ�� �����ִ� �Լ�

	PrintMenu();
}

void PrintMenu() { // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ���α׷� ����\n\n";
	cout << "���ϴ� ����� �Է��ϼ��� : "; 
	InputValue(menuNum); // ����� �Է� �޴´�.
	cout << endl;

	switch (menuNum)
	{
	case 1:
		cout << "�л� �� : ";
		InputValue(StdNum);
		St = new Student[StdNum]; // �л� �� �����Ҵ�
		InputData(St, StdNum); // �л� ���� �Է� �Լ�
		PrintMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 2:
		PrintAllData(St, StdNum); // ��ü �л� ���� ���� �Լ�
		PrintMenu(); // �Է� �� �޴� �Է� ȭ������ �Ѿ��
	case 3:
		Student * SearchStd; // �л� �̸� Ž�� ����� ���� ����ü
		SearchStd = StdSearch(St, StdNum);
		if (SearchStd != NULL)
			PrintOneData(*SearchStd);
		PrintMenu();
	case 4:
		cout << "���α׷��� �����մϴ�.";
		exit(0); // ���α׷� ���� 
	}

	if (St != nullptr) // �����Ҵ� ����
	{
		for (int i = 0; i < StdNum; i++)
		{
			if (St[i].sub != nullptr)
				delete[] St[i].sub; // ���� �޸� �����Ҵ� ����
		}

		delete[] St; // �л� �޸� �����Ҵ� ����
	}
}

void InputData(Student *pSt, int StudentNum) { // �л� ���� �Է� �Լ�

	// pSt : ������ �л����� ������ �Ű�����
	// StudentNum : ��ü �л� ��

	for (i = 0; i < StudentNum; i++)
	{
		// ����ü�� ���� �Է� �ޱ�
		cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : "; InputValue(pSt[i].stdName);
		cout << "�й� : "; InputValue(pSt[i].Hakbun); 
		cout << "���� �� : "; InputValue(pSt[i].SubNum);
		pSt[i].sub = new Subject[pSt[i].SubNum]; // ���� �� �����Ҵ� 
		cout << "\n\n";

		cout << "* ������ ����" << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";

		for (j = 0; j < pSt[i].SubNum; j++) { // ���� ���� �Է� �ޱ�
			cout << "������� : "; InputValue(pSt[i].sub[j].subName); // ����� �Է� �ޱ�
			cout << "���������� : "; InputValue(pSt[i].sub[j].hakjum); // ���������� �Է� �ޱ�
			cout << "������<A+ ~ F> : "; InputValue(pSt[i].sub[j].grade); // ������ �Է� �ޱ�
			cout << endl;
		}
	}
}

void CalcGPA(Subject& sub); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��� �����ڸ� �̿��� ���������� ���ϴ� �Լ�
double *sumGPA = new double[StdNum]; // ���� ������ ���ϴ� sumGPA ���� �޸� �迭
double CalcAveGPA(Subject* sub); // ���� ��� ���� ���ϴ� �Լ�
double AveGPA = 0;

void PrintAllData(const Student* pSt, int StudentNum) { // �л� ���� �� ���� ���� ��� �Լ�

	// pSt : �л������� ��� Student ������ ����
	// StudentNum : ��ü �л��� 

	cout.width(10); // ����� ������ �� ����
	cout << "��ü �л�  ���� ����\n";
	cout << "========================================================================\n";

	for (int i = 0; i < StudentNum; i++) { // �л��� �� ���̿��� �� �� �ݺ�

		PrintOneData (pSt[i]);
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
		cout << rSt.sub[j].subName; // ����� ���
		cout.width(10);
		cout << rSt.sub[j].hakjum; // �������� ���
		cout.width(10);
		cout << rSt.sub[j].grade; // ������ ���
		cout.width(10);

		CalcGPA(rSt.sub[j]); // �������� ���ϴ� �Լ�

		cout.precision(2); // �Ҽ��� ���� 2�ڸ��� ����ϵ��� ����
		cout << fixed;
		cout << rSt.sub[j].gpa; // �������� ���

		AveGPA = CalcAveGPA(rSt.sub); // ���� ��� ���� ���ϴ� �Լ�
		cout << endl;
		cout << "========================================================================\n";
	}
	cout.width(50);
	cout << "�������     ";
	cout << AveGPA; // ��� ���� ���
	cout << endl;

	for (j = 0; j < rSt.SubNum; j++) {
		reGPA(rSt.sub[j]); // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�
	}

	sumGPA[i] = 0; // �л� ���� ��½� CalcAveGPA() �Լ� �������� ���� ��� ������ �� ��� ������ �̺�Ʈ ��Ȱ��ȭ�� ���� �ʱ�ȭ
}

void CalcGPA(Subject& sub) { // sub : ������ ������ ��� Subject ���۷��� ����

	if (strcmp(sub.grade, "A+") == 0) // strcmp�� �̿��Ͽ� ����� Ȯ���Ѵ�.
	{
		
		strcpy(sub.grade, "4.5"); // strcpy�� �̿��Ͽ� ����� ������ ȯ���Ѵ�.
		double aa = atof(sub.grade); // ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��´�.
		sub.gpa = sub.hakjum * aa; // ���������� ������ ���� ���������� ���Ѵ�.
	}
	else if (strcmp(sub.grade, "A0") == 0)
	{
		strcpy(sub.grade, "4.0");
		double a = atof(sub.grade);
		sub.gpa = sub.hakjum * a;
	}
	else if (strcmp(sub.grade, "B+") == 0)
	{
		strcpy(sub.grade, "3.5");
		double bb = atof(sub.grade);
		sub.gpa = sub.hakjum * bb;
	}
	else if (strcmp(sub.grade, "B0") == 0)
	{
		strcpy(sub.grade, "3.0");
		double b = atof(sub.grade);
		sub.gpa = sub.hakjum * b;
	}
	else if (strcmp(sub.grade, "C+") == 0)
	{
		strcpy(sub.grade, "2.5");
		double cc = atof(sub.grade);
		sub.gpa = sub.hakjum * cc;
	}
	else if (strcmp(sub.grade, "C0") == 0)
	{
		strcpy(sub.grade, "2.0");
		double c = atof(sub.grade);
		sub.gpa = sub.hakjum * c;
	}
	else if (strcmp(sub.grade, "D+") == 0)
	{
		strcpy(sub.grade, "1.5");
		double dd = atof(sub.grade);
		sub.gpa = sub.hakjum * dd;
	}
	else if (strcmp(sub.grade, "D0") == 0)
	{
		strcpy(sub.grade, "1.0");
		double d = atof(sub.grade);
		sub.gpa = sub.hakjum * d;
	}
	else if (strcmp(sub.grade, "F") == 0)
	{
		strcpy(sub.grade, "0.0");
		double f = atof(sub.grade);
		sub.gpa = sub.hakjum * f;
	}
}

void reGPA(Subject& sub) { // CalcGPA() �Լ��� ���� �л� ���� ����� �� �˻� �� ���� ����� ������ ������ ������ ���� �ϱ� ���� �Լ�
	if (strcmp(sub.grade, "4.5") == 0) // strcmp�� �̿��Ͽ� ���� ������ Ȯ��
	{
		strcpy(sub.grade, "A+"); // strcpy�� �̿��Ͽ� ���� ������ ������� ȯ��
	}
	else if (strcmp(sub.grade, "4.0") == 0)
	{
		strcpy(sub.grade, "A0");
	}
	else if (strcmp(sub.grade, "3.5") == 0)
	{
		strcpy(sub.grade, "B+");
	}
	else if (strcmp(sub.grade, "3.0") == 0)
	{
		strcpy(sub.grade, "B0");
	}
	else if (strcmp(sub.grade, "2.5") == 0)
	{
		strcpy(sub.grade, "C+");
	}
	else if (strcmp(sub.grade, "2.0") == 0)
	{
		strcpy(sub.grade, "C0");
	}
	else if (strcmp(sub.grade, "1.5") == 0)
	{
		strcpy(sub.grade, "D+");
	}
	else if (strcmp(sub.grade, "1.0") == 0)
	{
		strcpy(sub.grade, "D0");
	}
	else if (strcmp(sub.grade, "0.0") == 0)
	{
		strcpy(sub.grade, "F");
	}
}

double CalcAveGPA(Subject* sub) { // ���� ��� ���� ���ϴ� �Լ�

	sumGPA[i] += sub[j].gpa; // ���� ������ ���ϴ� sumGPA �迭
	//cout << "St[i].SubNum: " << St->SubNum << endl;  //menu 2�� ��½� subnum �̻��� �� ����. -> St[i].SubNum ���� ' -> '�� �ٲ�
	St -> aveGPA = sumGPA[i] / St -> SubNum; // ���� ������ ��� ���ؼ� ���� �� ��ŭ ���� ��� ����
	AveGPA = St -> aveGPA;

	return AveGPA;
}

char name[10]; // �˻��� �̸� ����

Student* StdSearch(Student* pSt, int StudentNum) { // Ư�� �л��� �̸��� �˻��ؼ� ������ �ִ� �ּ� �����ϴ� �Լ�
	// pSt: �л������� ��� Student ������ ����
	// ���ϰ� : �ش� �л��� ������ �ִ� ���� �ּ�

	cout << "�˻� �� �л� �̸� : "; InputValue(name); cout << endl;
	
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
