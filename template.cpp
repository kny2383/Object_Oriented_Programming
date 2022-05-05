// �̸� : �質��
// �й� : 2021041059

#include <iostream> 
#include <algorithm> // algoritm ��� ���Ͽ� �ִ� swap()�Լ� ����ϱ� ���� ����
using namespace std;

void selectMenu();// �޴� ���� �Լ�
template <class T> // �Լ��� Ŭ������ �Ϲ�ȭ�ϴ� C++ ���� , ������ �Ű� ������ Ÿ�Ը� �ٸ���, �ڵ� �κ��� ������ �Լ��� �Ϲ�ȭ ��Ŵ
void Sort(T *arr, T size); // ���� �Լ�
int menu = 0; // �޴� ����
int intNum[5]; // ���� �迭
double douNum[5]; // �Ǽ� �迭

int main() {

	selectMenu(); // �޴� ���� �Լ�
}

void selectMenu() { // �޴� ���� �Լ�

	cout << "1. ���� ����" << endl;
	cout << "2. �Ǽ� ����" << endl;
	cout << "3. ����" << endl;
	cout << "�޴� ���� : "; cin >> menu;
	
	switch (menu) {
		case 1 :
			cout << "5���� ������ �Է��ϼ��� : "; 
			for (int i = 0; i < 5; i++) // �迭 �Է�
			{
				cin >> intNum[i];
			}
			cout << "���� ��� : ";
			Sort<int>(intNum, 5);
			selectMenu();
		case 2 :
			cout << "5���� �Ǽ��� �Է��ϼ��� : ";
			for (int i = 0; i < 5; i++) // �迭 �Է�
			{
				cin >> douNum[i];
			}
			cout << "���� ��� : ";
			Sort<double>(douNum, 5);
			selectMenu();
		case 3 :
			exit(0);

	}

}

template <class T> // ���׸� Ÿ�� T ����
// ���׸��̶� �Լ��� Ŭ������ �Ϲ�ȭ��Ű�� �Ű� ���� Ÿ���� �����Ͽ� Ʋ�� ��� ������ �Լ��� �����ϴ� ���

void Sort(T *arr, T size) { // arr�� �迭�̸� size�� �迭�� ũ��

	int temp; // �迭�� ���� �ӽ� ���� �س��� ����
	for (int i = 0; i < size-1; i++) { // �������� ���
		temp = i; // ������ temp = 0
		for (int j = i+1; j < size; j++) {
			if (arr[temp] > arr[j]) // �������� ����
			{
				temp = j;
			}
		}
		swap(arr[temp], arr[i]); // algoritm ��� ���Ͽ� �ִ� swap()�Լ� : �� ���� �ٲ��ش�.
	}
	for (int i = 0; i < size; i++) { // �迭 ���
		cout << arr[i] << " ";
	}
	cout << endl;
}

		