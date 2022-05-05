// �̸�: �質��
// �й�: 2021041059

#include <iostream> // cout�̳� cin�� �����
#include <vector> // vector�� ����ϱ� ���� ����
#include <string> // ���ڿ��� ����ϱ� ���� ����
using namespace std;

void CountWords(string buffer); // �ܾ� ���� �Լ�
void PrintWords(); // �ܾ� ��� �Լ�
void RemoveAll(); // �޸� ���� �Լ�

struct WORD { // �ܾ�� �ܾ��� �󵵼��� �����ϴ� WORD ����ü
	string str; //�� �ܾ��� ����
	int count; // �� �ܾ��� ��� ��
};

// ���� ���� �ܾ�� �� �ܾ��� ���󵵼��� �����ϱ� ���ؼ� vector Ŭ������ ���
vector<WORD*> words; // WORD ����ü �����͸� �����ϴ� ���� ��ü

int main() {

	cout << "���ڿ� �Է�. ����: Ctrl+Z\n";
	string buffer; // ���ڿ� buffer ����
	while (cin >> buffer) { // ���ڿ� buffer�� �Է¹޴� ����
		if (buffer == "^Z") { // buffer�� ctrl+Z�� �� 
			words.push_back(new WORD); // �� ���� WORD ����ü ����
			words.back()->str = buffer; // ������ str�� buffer ����
			break; // Ż��
		}
		CountWords(buffer); // �ܾ� ����, vector �ȿ� �ش� �ܾ �ִ��� �˻� ��
							// �ش� �ܾ �߰ߵǸ� �ش� �ܾ��� �󵵼��� 1�� ������Ŵ
							// �ܾ �߰ߵ��� ������ vector�� �ܾ� �߰� �� �󵵼� 1�� ����
	}
	
	PrintWords(); // �ܾ����
	RemoveAll(); // ����
	return 0;
}

void CountWords(string buffer) { // �ܾ� ���� �Լ�

	int size = words.size(); // ���� ��ȿ�� ������ ���� �����ؼ� size ������ ���

	for (int i = 0; i < size; i++) {
		if (words[i]->str == buffer) { // vector words �ȿ� buffer�� �ִٸ�
			words[i]->count++; // �󵵼� 1 ����
			return;
		}
	}

	// ������ �ܾ ���ٸ� vector�� �ܾ� �߰� �� �󵵼��� 1�� ����
	words.push_back(new WORD); // �� ���� WORD ����ü ����
	words.back()->str = buffer; // ������ str�� buffer ����
	words.back()->count = 1; // count 
}

void PrintWords() { // �ܾ� ��� �Լ�
	int size = words.size();

	cout << "=======================\n";
	for (int i = 0; i < size; i++) {
		cout << words[i]->str << " : " << words[i]->count << '\n'; // string str�� count ���
	}
	cout << "=======================\n";
}

void RemoveAll() { // �޸� ���� �Լ�
	int size = words.size();
	for (int i = 0; i < size; i++) {
		delete words[i];  // words �޸� ����
	}
}