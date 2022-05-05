// 이름: 김나영
// 학번: 2021041059

#include <iostream> // cout이나 cin이 선언됨
#include <vector> // vector를 사용하기 위해 선언
#include <string> // 문자열을 사용하기 위해 선언
using namespace std;

void CountWords(string buffer); // 단어 세는 함수
void PrintWords(); // 단어 출력 함수
void RemoveAll(); // 메모리 해제 함수

struct WORD { // 단어와 단어의 빈도수를 저장하는 WORD 구조체
	string str; //각 단어의 내용
	int count; // 각 단어의 사용 빈도
};

// 여러 개의 단어와 각 단어의 사용빈도수를 보관하기 위해서 vector 클래스를 사용
vector<WORD*> words; // WORD 구조체 포인터를 저장하는 벡터 객체

int main() {

	cout << "문자열 입력. 종료: Ctrl+Z\n";
	string buffer; // 문자열 buffer 선언
	while (cin >> buffer) { // 문자열 buffer을 입력받는 동안
		if (buffer == "^Z") { // buffer가 ctrl+Z일 때 
			words.push_back(new WORD); // 맨 끝에 WORD 구조체 삽입
			words.back()->str = buffer; // 마지막 str에 buffer 대입
			break; // 탈출
		}
		CountWords(buffer); // 단어 세기, vector 안에 해당 단어가 있는지 검색 후
							// 해당 단어가 발견되면 해당 단어의 빈도수를 1씩 증가시킴
							// 단어가 발견되지 않으면 vector에 단어 추가 후 빈도수 1로 설정
	}
	
	PrintWords(); // 단어출력
	RemoveAll(); // 해제
	return 0;
}

void CountWords(string buffer) { // 단어 세는 함수

	int size = words.size(); // 실제 유효한 원소의 개수 리턴해서 size 변수에 담기

	for (int i = 0; i < size; i++) {
		if (words[i]->str == buffer) { // vector words 안에 buffer가 있다면
			words[i]->count++; // 빈도수 1 증가
			return;
		}
	}

	// 동일한 단어가 없다면 vector에 단어 추가 후 빈도수를 1로 설정
	words.push_back(new WORD); // 맨 끝에 WORD 구조체 삽입
	words.back()->str = buffer; // 마지막 str에 buffer 대입
	words.back()->count = 1; // count 
}

void PrintWords() { // 단어 출력 함수
	int size = words.size();

	cout << "=======================\n";
	for (int i = 0; i < size; i++) {
		cout << words[i]->str << " : " << words[i]->count << '\n'; // string str과 count 출력
	}
	cout << "=======================\n";
}

void RemoveAll() { // 메모리 해제 함수
	int size = words.size();
	for (int i = 0; i < size; i++) {
		delete words[i];  // words 메모리 해제
	}
}