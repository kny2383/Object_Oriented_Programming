// �̸�: �質��
// �й�: 2021041059

// Ŭ������ ��� ���ϰ� cpp ���Ϸ� �и��Ͽ� �ۼ�
// Ŭ���� ����δ� �������.h�� �����Ѵ�.
#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Subject sub("��ǻ��", 3, "C0");
	cout << "------------------------------- \n";

	// IOInterface Class���� ��ӹ��� GetData() ȣ��;
	cout << "m_data : " << sub.IOInterface::GetData() << "\n";

	// Subject Class���� �����ǵ� GetName() ȣ��;
	cout << "������ �̸� : " << sub.GetName() << "\n";
	
	//IOInterface Class�� GetName() ȣ��;
	cout << "�θ�Ŭ������ �̸� : " << sub.IOInterface::GetName() << "\n";
	cout << "------------------------------- \n\n";

	Student std("ȫ�浿", 2013909845, 1, &sub);
	cout << " -------------------------------\n";

	//IOInterface Class���� ��ӹ��� GetData() ȣ��;
	cout << "m_data : " << std.IOInterface::GetData() << "\n";

	//Student Class���� �����ǵ� GetName() ȣ��;
	cout << "�л� �̸� : " << std.GetName() << "\n";
	
	//IOInterface Class�� GetName() ȣ��;
	cout << "�θ�Ŭ������ �̸� : " << std.IOInterface::GetName() << "\n";
	cout << " -------------------------------\n\n";
}