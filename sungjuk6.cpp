// 이름 : 김나영
// 학번 : 2021041059

#pragma warning(disable : 4996) // C에서의 #define _CRT_SECURE_NO_WARNINGS
#include <iostream> // 헤더파일을 컴파일 전에 소스에 확장하도록 지시하는 전처리기
#include <string> // 문자열을 다루는 string 클래스
using namespace std; // 이름 충돌이 발생하는 경우를 대비하는 namespace, std에는 cout,cin,endl 등이 정의 되어 있다.


struct Subject { //과목 정보 구조체
	string subName; // 과목 이름
	int hakjum; // 과목 학점
	string grade; // 과목 등급
	float gpa; // 과목 평점
};
struct Student { // 학생 정보
	string stdName; // 학생 이름
	int hakbun; // 학번
	Subject* sub; // 과목
	int SubNum; // 과목 수
	float aveGPA; // 교과목 평균 평점
};

inline void PrintMenu(); // 입력받은 기능을 각각의 함수로 실행하는 함수
void InputData(Student* std, int StudentNum); // 학생 성적 입력 함수
inline void InputValue(string& str); //  이름, 학번, 과목명 입력 받는 인라인 함수
inline void InputValue(int& i); // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
float calcGPA(Subject& sub);// 문자열로 된 점수를 실수형으로 변환하여 변수에 담고 연산자를 이용해 과목평점을 구하는 함수
float calcAveGPA(Subject* sub, int subNum); // 과목 평균 평점 구하는 함수
void PrintAllStdList(Student* pSt, int StudentNum); // 전체 학생 이름 학번 출력 함수
void PrintAllData(const Student* pst, int StudentNum); // 학생 정보 및 과목 정보 출력 함수
void PrintOneData(const Student& rst); // 학생 정보 출력 함수
Student* StdSearch(Student* pst, int StudentNum); // 학생 정보 검색 함수
void ModifyStdInfo(Student* pst); // 학생 이름 학번 수정 함수
Subject* SubSearch(const Student* pst); // 특정한 과목을 탐색하는 함수

int menuNum; // 기능 입력 전역 변수 선언  

int main() {
	Student* St = NULL, * findStd = NULL; // 학생 구조체, 학생 검색 구조체 초기화 
	int StdNum = 0; // 학생 수

	cout.precision(2);
	cout << fixed;

	while (1) {
		PrintMenu();

		//학생 정보 입력
		if (menuNum == 1) {
			cout << "학생 수 : ";
			InputValue(StdNum); // 학생 수 입력
			//학생 수 만큼 동적 메모리 할당
			St = new Student[StdNum];
			InputData(St, StdNum); // 학생 성적 입력
		}
		//전체학생 정보 출력
		else if (menuNum == 2) {
			PrintAllData(St, StdNum); // 전체 학생 성적 보기 함수
		}
		//원하는 학생의 정보 출력
		else if (menuNum == 3) {
			Student* SearchStd = NULL;
			//학생 이름 입력 후 프로그램에 저장된 학생 이름과 비교하는 함수 호출
			SearchStd = StdSearch(St, StdNum);

			//찾고 있던 학생의 정보가 있을 경우, 해당 학생의 정보 출력
			if (SearchStd) {
				PrintOneData(*SearchStd);
			}
			//찾고 있던 학생의 정보가 없을 경우, 아래의 메세지 출력
			else {
				cout << "<해당 이름을 가진 학생의 정보가 등록되어있지 않습니다.>\n\n";
			}
			StdSearch(St, StdNum);
		}
		//전체 학생 정보 출력
		else if (menuNum == 4) {
			PrintAllStdList(St, StdNum); // 전체 학생 이름 출력 함수
		}
		//특정 학생의 정보 수정
		else if (menuNum == 5) {
			findStd = StdSearch(St, StdNum);
			if (findStd != NULL) {
				ModifyStdInfo(findStd); // 학생 이름 학번 수정 함수
			}
			else {
				cout << "<프로그램 내에 해당 학생의 이름이 없습니다.>\n";
			}

		}
		//프로그램 종료
		else if (menuNum == 6) {
			cout << "프로그램을 종료합니다.\n";
			break;
		}
		//출력된 메뉴에 없는 번호를 선택했을 경우
		else {
			cout << "<없는 메뉴 번호를 선택하셨습니다.>\n";
		}
	}
	//할당했던 동적 메모리 해제
	delete[] St;

	return 0;
}
void PrintMenu() { //입력받은 기능을 각각의 함수로 실행하는 함수

	cout << "==========메뉴==========\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n" << "\n";

	cout << "원하는 기능을 입력하세요 : ";
	InputValue(menuNum); // 기능을 입력받는다.
	cout << "\n";
}
void InputData(Student* pSt, int StudentNum) { // 학생 성적 입력 함수

	// pSt : 수정할 학생정보 포인터 매개변수
	// StudentNum : 전체 학생 수

	for (int i = 0; i < StudentNum; i++) {
		cout << "\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(pSt[i].stdName); // 이름 입력 받기
		cout << "학번 : ";
		InputValue(pSt[i].hakbun); // 학번 입력 받기
		cout << "\n\n";
		cout << "과목 수 : ";
		InputValue(pSt[i].SubNum); // 과목 수 입력 받기
		pSt[i].sub = new Subject[pSt[i].SubNum]; // 과목 수 동적 할당

		float sumGPA = 0.0;

		cout << "* 수강한 과목" << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (int j = 0; j < pSt[i].SubNum; j++) {
			cout << "교과목명 : ";
			InputValue(pSt[i].sub[j].subName);
			cout << "과목학점 : ";
			InputValue(pSt[i].sub[j].hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(pSt[i].sub[j].grade);
			cout << "\n";

			pSt[i].sub[j].gpa = calcGPA(pSt[i].sub[j]);
		}
		cout << "\n\n";
		
		//해당 학생의 과목 평균 평점 계산
		pSt[i].aveGPA = calcAveGPA(pSt[i].sub, pSt[i].SubNum);
	}
}

// 개별 데이타를 사용자로부터 입력받을 때 사용하는 코드를 묶어 오버로드 된 인라인함수

void InputValue(string& str) { //  이름, 학번, 과목명 입력 받는 인라인 함수
	getline(cin, str);
}
void InputValue(int& i) { // 메뉴, 학생수, 과목수 입력 받는 인라인 함수
	cin >> i;
	cin.ignore();
}

float calcGPA(Subject& sub) { // sub : 교과목 정보가 담긴 Subject 레퍼런스 변수
	float result;
	// 과목의 등급을 비교해서 평점을 result에 저장
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

	return result * sub.hakjum; // 과목학점과 변수를 곱해 과목평점을 구한다.
}

float calcAveGPA(Subject* sub, int subNum) { // 과목 평균 평점 구하는 함수

	float sumGPA = 0.0;
	for (int i = 0; i < subNum; i++) {
	
		//모든 과목의 평점 저장
		sumGPA += sub[i].gpa;
	}
	//계산된 과목 평균 평점 전달
	return sumGPA / subNum;
}

void PrintAllStdList(Student* pSt, int StudentNum) { 
	cout << "===============================================================\n";
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << "이름\n";
	cout << "===============================================================\n";

	//프로그램에 저장된 학생들의 학번과 이름을 출력
	for (int i = 0; i < StudentNum; i++) {
		cout.width(15);
		cout << pSt[i].hakbun;
		cout.width(15);
		cout << pSt[i].stdName << '\n';
	}
	cout << "===============================================================\n\n";
}

void PrintAllData(const Student* pst, int StudentNum) { // 학생 정보 및 과목 정보 출력 함수

	// pSt : 학생정보가 담긴 Student 포인터 변수
	// StudentNum : 전체 학생수 
	cout << "               전체 학생 성적 보기" << '\n';
	cout << "===============================================================\n";

	for (int i = 0; i < StudentNum; i++) {
		PrintOneData(pst[i]);
	}
}

void PrintOneData(const Student& rSt) { // rSt : 학생정보가 담긴 Student 레퍼런스 변수
	//출력될 정보들을 화면에 표시
	cout << "이름 : " << rSt.stdName << "  학번 : " << rSt.hakbun << "\n";
	cout << "===============================================================\n";
	cout.width(15); // 출력할 내용의 폭 지정
	cout << "과목명"; 
	cout.width(15);
	cout << "과목학점";
	cout.width(15);
	cout << "과목등급";
	cout.width(15);
	cout << "과목평점\n";
	cout << "===============================================================\n";

	//해당 학생이 수강하는 과목 정보 출력
	//해당 학생이 수강하는 과목의 성적 출력
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
	cout << "평균평점 : ";
	//해당 학생의 과목 평균 평점 출력
	cout << rSt.aveGPA << "\n\n"; 
}


Student* StdSearch(Student* pSt, int StudentNum) { // 특정 학생의 이름을 검색해서 정보가 있는 주소 리턴하는 함수
	// pSt: 학생정보가 담긴 Student 포인터 변수
	// 리턴값 : 해당 학생의 정보가 있는 곳의 주소

	string searchName; // 검색할 학생 이름 string
	cout << "검색할 학생 이름 : ";
	InputValue(searchName);

	for (int i = 0; i < StudentNum; i++) { // 검색에 성공한 경우
		//해당 학생의 이름과 찾고자 하는 학생 이름 비교
		if (searchName == pSt[i].stdName) {
			
			return &pSt[i]; // 해당 학생 정보가 있는 주소를 리턴
		}
		//계속 일치하는 학생 찾기
		else;
	}
	//검색한 이름이 프로그램에 없는 학생이라면 NULL 값 전달
	return NULL;
}

void ModifyStdInfo(Student* pSt) { // 학생 정보 수정 함수
	// pSt는 수정할 학생정보 포인터매개변수

	string Type; // 메뉴 입력 받는 string
	Subject* findSub = NULL;

	//수정하고픈 정보 입력
	cout << "\n수정할 정보를 선택하세요 <학생정보 / 과목정보> : ";
	InputValue(Type);
	cout << '\n';

	//학생 정보를 입력한 경우
	if (Type == "학생 정보" || Type == "학생정보") {
		//포인터 구조체이기에 -> 이용
		cout << "< " << pSt->stdName << ", " << pSt->hakbun << ">의 정보를 수정하세요.\n";

		//검색한 학생의 이름과 학번 수정
		cout << "이름 : ";
		InputValue(pSt->stdName);
		cout << "학번 : ";
		InputValue(pSt->hakbun);
		cout << "\n";
	}
	//과목 정보를 입력한 경우
	else if (Type == "과목 정보" || Type == "과목정보") {
		//수정하고픈 과목 찾기
		findSub = SubSearch(pSt);

		//해당 학생이 수강한 과목 중에 찾는 과목이 존재한다면
		if (findSub != NULL) {
			//과목 정보 수정
			cout << "<" << findSub->subName << ", " << findSub->hakjum << ", " << findSub->grade << ">의 정보를 수정하세요.\n";
			cout << "교과목명 : ";
			InputValue(findSub->subName);
			cout << "과목학점 : ";
			InputValue(findSub->hakjum);
			cout << "과목등급(A+ ~ F) : ";
			InputValue(findSub->grade);
			cout << "\n";

			//수정한 정보를 바탕으로 GPA, AveGPA 수정
			findSub->gpa = calcGPA(*findSub);
			pSt->aveGPA = calcAveGPA(pSt->sub, pSt->SubNum);
		}
		//해당 학생의 수강 과목 중에 찾는 과목이 없으면
		else {
			cout << "<해당 학생은 찾고자 하는 과목을 수강하지 않습니다.>\n\n";
		}
	}
	//잘못 입력한 경우
	else {
		cout << "<수정하고자 하는 정보를 정확히 입력해주세요.>\n\n";
	}
}

Subject* SubSearch(const Student* pst) { // 특정한 과목을 탐색하는 함수
	string searchSub; // 검색할 과목 이름 string

	//수정하고픈 과목 이름 입력
	cout << "검색할 과목 이름 : ";
	InputValue(searchSub);

	//해당 학생이 수강한 과목들을 비교
	for (int i = 0; i < pst->SubNum; i++) {
		//검색한 과목과 같은 이름 존재
		if (searchSub == pst->sub[i].subName) {
			return &(pst->sub[i]);
		}
		else;
	}
	return NULL;
}