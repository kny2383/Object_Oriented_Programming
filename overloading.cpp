// �̸� : �質��
// �й� : 2021041059

#include <iostream>
#include <cstring> // strcmp() �Լ� ����� ���� ����
using namespace std;

void GetMin(int a, int b) { // ���� �ּҰ� ã�� �Լ�

	if (a > b)
		cout << "�ּҰ��� " << b << "�Դϴ�" << endl;
	else
		cout << "�ּҰ��� " << a << "�Դϴ�" << endl;
}

void GetMin(double a, double b) { // �Ǽ� �ּҰ� ã�� �Լ�

	if (a > b)
		cout << "�ּҰ��� " << b << "�Դϴ�" << endl;
	else
		cout << "�ּҰ��� " << a << "�Դϴ�" << endl;
}

void GetMin(char a[10], char b[10]) { // ���ڿ� �ּҰ� ã�� �Լ�

	if (strcmp(a, b) > 0) { // ���ڿ� a�� ���ڿ� b�� ���ϴ� �Լ� strcmp() , 0���� ũ�� a�� �� ū ���̴�.
		cout << "�ּҰ��� " << b << "�Դϴ�" << endl;
	}
	else
		cout << "�ּҰ��� " << a << "�Դϴ�" << endl;
}

void GetMin(int *a, int size) { // a�� �迭 �̸� , size�� �迭�� ũ��

	int min = a[0]; // ó�� �ּҰ��� �迭�� ù��° ������ �����Ѵ�.

	for (int i = 0; i < size-1; i++) { // 0���� size-1���� �ּҰ��� ã�´�
		if (min > a[i+1]) 
			min = a[i+1];
	}
	cout << "�ּҰ��� " << min << "�Դϴ�" << endl;
}

int main() { 

	// GetMin()�Լ��� ���� ������ �̸��� ����ϸ� �Լ� �̸��� �����Ͽ� ����� �ʿ� ����, �Լ� ȣ���� �߸��ϴ� �Ǽ��� ���� ���� �ִ�.

	// �ߺ��� �Լ����� �̸��� �����ϰ� �Ű� ���� Ÿ���� �� �ٸ��� ������ ������ �����ϴ�.

	int a, b = 0; // ���� ���� �ʱ�ȭ
	cout << "�ΰ��� ������ �Է��ϼ��� : "; cin >> a >> b;
	GetMin(a,b);

	double c, d = 0; // �Ǽ� ���� �ʱ�ȭ
	cout << "�ΰ��� �Ǽ��� �Է��ϼ��� : "; cin >> c >> d;
	GetMin(c,d);

	char e[10]; // ���ڿ� ���� e,f
	char f[10];
	cout << "�ΰ��� ���ڿ��� �Է��ϼ��� : "; cin >> e >> f;
	GetMin(e, f);

	int size = 0; // �迭�� ũ�� �ʱ�ȭ
	cout << "�迭�� ũ�⸦ �Է��ϼ��� : "; cin >> size;
	int* g = new int[size]; // ũ�⸸ŭ g �迭 �����Ҵ�
	cout << "�迭�� ���� : "; 
	for (int i = 0; i < size; i++)
	{
		cin >> g[i]; // �迭 �Է� �ޱ�
	}
	GetMin(g,size);
}