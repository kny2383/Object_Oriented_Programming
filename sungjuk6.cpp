// �̸� : �質��
// �й� : 2021041059

#pragma warning(disable : 4996) // C������ #define _CRT_SECURE_NO_WARNINGS
#include <iostream> // ��������� ������ ���� �ҽ��� Ȯ���ϵ��� �����ϴ� ��ó����
#include <string> // ���ڿ��� �ٷ�� string Ŭ����
using namespace std; // �̸� �浹�� �߻��ϴ� ��츦 ����ϴ� namespace, std���� cout,cin,endl ���� ���� �Ǿ� �ִ�.


struct Subject { //���� ���� ����ü
	string subName; // ���� �̸�
	int hakjum; // ���� ����
	string grade; // ���� ���
	float gpa; // ���� ����
};
struct Student { // �л� ����
	string stdName; // �л� �̸�
	int hakbun; // �й�
	Subject* sub; // ����
	int SubNum; // ���� ��
	float aveGPA; // ������ ��� ����
};

inline void PrintMenu(); // �Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�
void InputData(Student* std, int StudentNum); // �л� ���� �Է� �Լ�
inline void InputValue(string& str); //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
inline void InputValue(int& i); // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
float calcGPA(Subject& sub);// ���ڿ��� �� ������ �Ǽ������� ��ȯ�Ͽ� ������ ��� �����ڸ� �̿��� ���������� ���ϴ� �Լ�
float calcAveGPA(Subject* sub, int subNum); // ���� ��� ���� ���ϴ� �Լ�
void PrintAllStdList(Student* pSt, int StudentNum); // ��ü �л� �̸� �й� ��� �Լ�
void PrintAllData(const Student* pst, int StudentNum); // �л� ���� �� ���� ���� ��� �Լ�
void PrintOneData(const Student& rst); // �л� ���� ��� �Լ�
Student* StdSearch(Student* pst, int StudentNum); // �л� ���� �˻� �Լ�
void ModifyStdInfo(Student* pst); // �л� �̸� �й� ���� �Լ�
Subject* SubSearch(const Student* pst); // Ư���� ������ Ž���ϴ� �Լ�

int menuNum; // ��� �Է� ���� ���� ����  

int main() {
	Student* St = NULL, * findStd = NULL; // �л� ����ü, �л� �˻� ����ü �ʱ�ȭ 
	int StdNum = 0; // �л� ��

	cout.precision(2);
	cout << fixed;

	while (1) {
		PrintMenu();

		//�л� ���� �Է�
		if (menuNum == 1) {
			cout << "�л� �� : ";
			InputValue(StdNum); // �л� �� �Է�
			//�л� �� ��ŭ ���� �޸� �Ҵ�
			St = new Student[StdNum];
			InputData(St, StdNum); // �л� ���� �Է�
		}
		//��ü�л� ���� ���
		else if (menuNum == 2) {
			PrintAllData(St, StdNum); // ��ü �л� ���� ���� �Լ�
		}
		//���ϴ� �л��� ���� ���
		else if (menuNum == 3) {
			Student* SearchStd = NULL;
			//�л� �̸� �Է� �� ���α׷��� ����� �л� �̸��� ���ϴ� �Լ� ȣ��
			SearchStd = StdSearch(St, StdNum);

			//ã�� �ִ� �л��� ������ ���� ���, �ش� �л��� ���� ���
			if (SearchStd) {
				PrintOneData(*SearchStd);
			}
			//ã�� �ִ� �л��� ������ ���� ���, �Ʒ��� �޼��� ���
			else {
				cout << "<�ش� �̸��� ���� �л��� ������ ��ϵǾ����� �ʽ��ϴ�.>\n\n";
			}
			StdSearch(St, StdNum);
		}
		//��ü �л� ���� ���
		else if (menuNum == 4) {
			PrintAllStdList(St, StdNum); // ��ü �л� �̸� ��� �Լ�
		}
		//Ư�� �л��� ���� ����
		else if (menuNum == 5) {
			findStd = StdSearch(St, StdNum);
			if (findStd != NULL) {
				ModifyStdInfo(findStd); // �л� �̸� �й� ���� �Լ�
			}
			else {
				cout << "<���α׷� ���� �ش� �л��� �̸��� �����ϴ�.>\n";
			}

		}
		//���α׷� ����
		else if (menuNum == 6) {
			cout << "���α׷��� �����մϴ�.\n";
			break;
		}
		//��µ� �޴��� ���� ��ȣ�� �������� ���
		else {
			cout << "<���� �޴� ��ȣ�� �����ϼ̽��ϴ�.>\n";
		}
	}
	//�Ҵ��ߴ� ���� �޸� ����
	delete[] St;

	return 0;
}
void PrintMenu() { //�Է¹��� ����� ������ �Լ��� �����ϴ� �Լ�

	cout << "==========�޴�==========\n";
	cout << "1. �л� ���� �Է�\n";
	cout << "2. ��ü �л� ���� ����\n";
	cout << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n";
	cout << "5. �л� ���� ����\n";
	cout << "6. ���α׷� ����\n" << "\n";

	cout << "���ϴ� ����� �Է��ϼ��� : ";
	InputValue(menuNum); // ����� �Է¹޴´�.
	cout << "\n";
}
void InputData(Student* pSt, int StudentNum) { // �л� ���� �Է� �Լ�

	// pSt : ������ �л����� ������ �Ű�����
	// StudentNum : ��ü �л� ��

	for (int i = 0; i < StudentNum; i++) {
		cout << "\n* " << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue(pSt[i].stdName); // �̸� �Է� �ޱ�
		cout << "�й� : ";
		InputValue(pSt[i].hakbun); // �й� �Է� �ޱ�
		cout << "\n\n";
		cout << "���� �� : ";
		InputValue(pSt[i].SubNum); // ���� �� �Է� �ޱ�
		pSt[i].sub = new Subject[pSt[i].SubNum]; // ���� �� ���� �Ҵ�

		float sumGPA = 0.0;

		cout << "* ������ ����" << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";
		for (int j = 0; j < pSt[i].SubNum; j++) {
			cout << "������� : ";
			InputValue(pSt[i].sub[j].subName);
			cout << "�������� : ";
			InputValue(pSt[i].sub[j].hakjum);
			cout << "������(A+ ~ F) : ";
			InputValue(pSt[i].sub[j].grade);
			cout << "\n";

			pSt[i].sub[j].gpa = calcGPA(pSt[i].sub[j]);
		}
		cout << "\n\n";
		
		//�ش� �л��� ���� ��� ���� ���
		pSt[i].aveGPA = calcAveGPA(pSt[i].sub, pSt[i].SubNum);
	}
}

// ���� ����Ÿ�� ����ڷκ��� �Է¹��� �� ����ϴ� �ڵ带 ���� �����ε� �� �ζ����Լ�

void InputValue(string& str) { //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	getline(cin, str);
}
void InputValue(int& i) { // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	cin >> i;
	cin.ignore();
}

float calcGPA(Subject& sub) { // sub : ������ ������ ��� Subject ���۷��� ����
	float result;
	// ������ ����� ���ؼ� ������ result�� ����
	if (sub.grade == "A+")
		result = 4.5;
	else if (sub.grade == "A0")
		result = 4.0;
	else if (sub.grade == "B+")
		result = 3.5;
	else if (sub.grade == "B0")
		result = 3.0;
	else if (sub.grade == "C+")
		result = 2.5;
	else if (sub.grade == "C0")
		result = 2.0;
	else if (sub.grade == "D+")
		result = 1.5;
	else if (sub.grade == "D0")
		result = 1.0;
	else
		result = 0.0;

	return result * sub.hakjum; // ���������� ������ ���� ���������� ���Ѵ�.
}

float calcAveGPA(Subject* sub, int subNum) { // ���� ��� ���� ���ϴ� �Լ�

	float sumGPA = 0.0;
	for (int i = 0; i < subNum; i++) {
	
		//��� ������ ���� ����
		sumGPA += sub[i].gpa;
	}
	//���� ���� ��� ���� ����
	return sumGPA / subNum;
}

void PrintAllStdList(Student* pSt, int StudentNum) { 
	cout << "===============================================================\n";
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << "�̸�\n";
	cout << "===============================================================\n";

	//���α׷��� ����� �л����� �й��� �̸��� ���
	for (int i = 0; i < StudentNum; i++) {
		cout.width(15);
		cout << pSt[i].hakbun;
		cout.width(15);
		cout << pSt[i].stdName << '\n';
	}
	cout << "===============================================================\n\n";
}

void PrintAllData(const Student* pst, int StudentNum) { // �л� ���� �� ���� ���� ��� �Լ�

	// pSt : �л������� ��� Student ������ ����
	// StudentNum : ��ü �л��� 
	cout << "               ��ü �л� ���� ����" << '\n';
	cout << "===============================================================\n";

	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pst[i]);
	}
}

void PrintOneData(const Student& rSt) { // rSt : �л������� ��� Student ���۷��� ����
	//��µ� �������� ȭ�鿡 ǥ��
	cout << "�̸� : " << rSt.stdName << "  �й� : " << rSt.hakbun << "\n";
	cout << "===============================================================\n";
	cout.width(15); // ����� ������ �� ����
	cout << "�����"; 
	cout.width(15);
	cout << "��������";
	cout.width(15);
	cout << "������";
	cout.width(15);
	cout << "��������\n";
	cout << "===============================================================\n";

	//�ش� �л��� �����ϴ� ���� ���� ���
	//�ش� �л��� �����ϴ� ������ ���� ���
	for (int i = 0; i < rSt.SubNum; i++) {
		cout.width(15);
		cout << rSt.sub[i].subName;
		cout.width(15);
		cout << rSt.sub[i].hakjum;
		cout.width(15);
		cout << rSt.sub[i].grade;
		cout.width(15);
		cout << rSt.sub[i].gpa << '\n';
	}
	cout << "===============================================================\n";

	cout.width(45);
	cout << "������� : ";
	//�ش� �л��� ���� ��� ���� ���
	cout << rSt.aveGPA << "\n\n"; 
}


Student* StdSearch(Student* pSt, int StudentNum) { // Ư�� �л��� �̸��� �˻��ؼ� ������ �ִ� �ּ� �����ϴ� �Լ�
	// pSt: �л������� ��� Student ������ ����
	// ���ϰ� : �ش� �л��� ������ �ִ� ���� �ּ�

	string searchName; // �˻��� �л� �̸� string
	cout << "�˻��� �л� �̸� : ";
	InputValue(searchName);

	for (int i = 0; i < StudentNum; i++) { // �˻��� ������ ���
		//�ش� �л��� �̸��� ã���� �ϴ� �л� �̸� ��
		if (searchName == pSt[i].stdName) {
			
			return &pSt[i]; // �ش� �л� ������ �ִ� �ּҸ� ����
		}
		//��� ��ġ�ϴ� �л� ã��
		else;
	}
	//�˻��� �̸��� ���α׷��� ���� �л��̶�� NULL �� ����
	return NULL;
}

void ModifyStdInfo(Student* pSt) { // �л� ���� ���� �Լ�
	// pSt�� ������ �л����� �����͸Ű�����

	string Type; // �޴� �Է� �޴� string
	Subject* findSub = NULL;

	//�����ϰ��� ���� �Է�
	cout << "\n������ ������ �����ϼ��� <�л����� / ��������> : ";
	InputValue(Type);
	cout << '\n';

	//�л� ������ �Է��� ���
	if (Type == "�л� ����" || Type == "�л�����") {
		//������ ����ü�̱⿡ -> �̿�
		cout << "< " << pSt->stdName << ", " << pSt->hakbun << ">�� ������ �����ϼ���.\n";

		//�˻��� �л��� �̸��� �й� ����
		cout << "�̸� : ";
		InputValue(pSt->stdName);
		cout << "�й� : ";
		InputValue(pSt->hakbun);
		cout << "\n";
	}
	//���� ������ �Է��� ���
	else if (Type == "���� ����" || Type == "��������") {
		//�����ϰ��� ���� ã��
		findSub = SubSearch(pSt);

		//�ش� �л��� ������ ���� �߿� ã�� ������ �����Ѵٸ�
		if (findSub != NULL) {
			//���� ���� ����
			cout << "<" << findSub->subName << ", " << findSub->hakjum << ", " << findSub->grade << ">�� ������ �����ϼ���.\n";
			cout << "������� : ";
			InputValue(findSub->subName);
			cout << "�������� : ";
			InputValue(findSub->hakjum);
			cout << "������(A+ ~ F) : ";
			InputValue(findSub->grade);
			cout << "\n";

			//������ ������ �������� GPA, AveGPA ����
			findSub->gpa = calcGPA(*findSub);
			pSt->aveGPA = calcAveGPA(pSt->sub, pSt->SubNum);
		}
		//�ش� �л��� ���� ���� �߿� ã�� ������ ������
		else {
			cout << "<�ش� �л��� ã���� �ϴ� ������ �������� �ʽ��ϴ�.>\n\n";
		}
	}
	//�߸� �Է��� ���
	else {
		cout << "<�����ϰ��� �ϴ� ������ ��Ȯ�� �Է����ּ���.>\n\n";
	}
}

Subject* SubSearch(const Student* pst) { // Ư���� ������ Ž���ϴ� �Լ�
	string searchSub; // �˻��� ���� �̸� string

	//�����ϰ��� ���� �̸� �Է�
	cout << "�˻��� ���� �̸� : ";
	InputValue(searchSub);

	//�ش� �л��� ������ ������� ��
	for (int i = 0; i < pst->SubNum; i++) {
		//�˻��� ����� ���� �̸� ����
		if (searchSub == pst->sub[i].subName) {
			return &(pst->sub[i]);
		}
		else;
	}
	return NULL;
}