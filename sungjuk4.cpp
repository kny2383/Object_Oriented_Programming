// 04/12 문제점 
// sub[1]만 출력되고 첫번째 학생 정보 출력시 sub[0]이 출력 안됨

// 04/13 문제점
// 04/12 문제점과 동일

// 04/14 위 문제점 해결
// PrintAllData()함수에서 배열을 참조할 때 '->' 말고 '.' 사용하니까 해결됨.

#pragma warning(disable : 4996) // C에서의 #define _CRT_SECURE_NO_WARNINGS
#include <iostream> // 헤더파일을 컴파일 전에 소스에 확장하도록 지시하는 전처리기
using namespace std; // 이름 충돌이 발생하는 경우를 대비하는 namespace, std에는 cout,cin,endl 등이 정의 되어 있다.

struct Subject { // 과목 정보 구조체
	char subName[30]; // 과목 이름
	int hakjum; // 과목 학점
	char grade[10]; // 과목 등급
	double gpa; // 과목 평점
};

struct Student { // 학생 정보
	char stdName[30]; // 학생 이름
	int Hakbun; // 학번
	Subject* sub = nullptr; // 과목
	int SubNum; // 과목 수
	double aveGPA; // 교과목 평균 평점
};

int i, j;  // 반복문을 위한 전역 변수
int StdNum;
int menuNum; // 기능 입력 전역 변수 선언  

Student* St = nullptr; // 학생 수 동적할당 초기화

void PrintMenu(); // 입력받은 기능을 각각의 함수로 실행하는 함수
void InputData(Student* pSt, int StudentNum); // 학생 성적 입력 함수
void PrintAllData(const Student* pSt, int StudentNum); // 학생 정보 및 과목 정보 출력 함수
Student* StdSearch(Student* pSt, int StudentNum); // 학생 정보 검색 함수
void PrintOneData(const Student& rSt); // 학생 정보 출력 함수

// 학생정보를 보다 간편하게 받는 인라인 함수
inline void InputValue(char* str) { 
	cin >> str;
}

inline void InputValue(int& i) {
	cin >> i;
}

int main(void) { // 메인 메뉴 화면 보여주는 함수

	PrintMenu();
}

void PrintMenu() { // 입력받은 기능을 각각의 함수로 실행하는 함수

	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : "; 
	InputValue(menuNum); // 기능을 입력 받는다.
	cout << endl;

	switch (menuNum)
	{
	case 1:
		cout << "학생 수 : ";
		InputValue(StdNum);
		St = new Student[StdNum]; // 학생 수 동적할당
		InputData(St, StdNum); // 학생 성적 입력 함수
		PrintMenu(); // 입력 후 메뉴 입력 화면으로 넘어가기
	case 2:
		PrintAllData(St, StdNum); // 전체 학생 성적 보기 함수
		PrintMenu(); // 입력 후 메뉴 입력 화면으로 넘어가기
	case 3:
		Student * SearchStd; // 학생 이름 탐색 결과를 받을 구조체
		SearchStd = StdSearch(St, StdNum);
		if (SearchStd != NULL)
			PrintOneData(*SearchStd);
		PrintMenu();
	case 4:
		cout << "프로그램을 종료합니다.";
		exit(0); // 프로그램 종료 
	}

	if (St != nullptr) // 동적할당 해제
	{
		for (int i = 0; i < StdNum; i++)
		{
			if (St[i].sub != nullptr)
				delete[] St[i].sub; // 과목 메모리 동적할당 해제
		}

		delete[] St; // 학생 메모리 동적할당 해제
	}
}

void InputData(Student *pSt, int StudentNum) { // 학생 성적 입력 함수

	// pSt : 수정할 학생정보 포인터 매개변수
	// StudentNum : 전체 학생 수

	for (i = 0; i < StudentNum; i++)
	{
		// 구조체에 정보 입력 받기
		cout << "*" << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : "; InputValue(pSt[i].stdName);
		cout << "학번 : "; InputValue(pSt[i].Hakbun); 
		cout << "과목 수 : "; InputValue(pSt[i].SubNum);
		pSt[i].sub = new Subject[pSt[i].SubNum]; // 과목 수 동적할당 
		cout << "\n\n";

		cout << "* 수강한 과목" << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

		for (j = 0; j < pSt[i].SubNum; j++) { // 과목 정보 입력 받기
			cout << "교과목명 : "; InputValue(pSt[i].sub[j].subName); // 과목명 입력 받기
			cout << "과목학점수 : "; InputValue(pSt[i].sub[j].hakjum); // 과목학점수 입력 받기
			cout << "과목등급<A+ ~ F> : "; InputValue(pSt[i].sub[j].grade); // 과목등급 입력 받기
			cout << endl;
		}
	}
}

void CalcGPA(Subject& sub); // 문자열로 된 점수를 실수형으로 변환하여 변수에 담고 연산자를 이용해 과목평점을 구하는 함수
double *sumGPA = new double[StdNum]; // 과목 평점을 더하는 sumGPA 동적 메모리 배열
double CalcAveGPA(Subject* sub); // 과목 평균 평점 구하는 함수
double AveGPA = 0;

void PrintAllData(const Student* pSt, int StudentNum) { // 학생 정보 및 과목 정보 출력 함수

	// pSt : 학생정보가 담긴 Student 포인터 변수
	// StudentNum : 전체 학생수 

	cout.width(10); // 출력할 내용의 폭 지정
	cout << "전체 학생  성적 보기\n";
	cout << "========================================================================\n";

	for (int i = 0; i < StudentNum; i++) { // 학생이 두 명이여서 두 번 반복

		PrintOneData (pSt[i]);
	}
}

void reGPA(Subject& sub); // CalcGPA() 함수로 인해 학생 정보 재출력 및 검색 시 과목 등급이 점수로 나오는 문제를 방지 하기 위한 함수

void PrintOneData(const Student& rSt) { // rSt : 학생정보가 담긴 Student 레퍼런스 변수

	cout << "이름 : " << rSt.stdName;
	cout << " 학번 : " << rSt.Hakbun;
	cout << "\n========================================================================\n";
	cout << "           과목명  과목학점  과목등급  과목평점\n";
	cout << "========================================================================\n";

	for (j = 0; j < rSt.SubNum; j++) {
		cout.width(15); // 출력할 내용의 폭 지정
		cout << rSt.sub[j].subName; // 과목명 출력
		cout.width(10);
		cout << rSt.sub[j].hakjum; // 과목학점 출력
		cout.width(10);
		cout << rSt.sub[j].grade; // 과목등급 출력
		cout.width(10);

		CalcGPA(rSt.sub[j]); // 교과평점 구하는 함수

		cout.precision(2); // 소수점 이하 2자리만 출력하도록 고정
		cout << fixed;
		cout << rSt.sub[j].gpa; // 과목평점 출력

		AveGPA = CalcAveGPA(rSt.sub); // 과목 평균 평점 구하는 함수
		cout << endl;
		cout << "========================================================================\n";
	}
	cout.width(50);
	cout << "평균평점     ";
	cout << AveGPA; // 평균 평점 출력
	cout << endl;

	for (j = 0; j < rSt.SubNum; j++) {
		reGPA(rSt.sub[j]); // CalcGPA() 함수로 인해 학생 정보 재출력 및 검색 시 과목 등급이 점수로 나오는 문제를 방지 하기 위한 함수
	}

	sumGPA[i] = 0; // 학생 정보 출력시 CalcAveGPA() 함수 실행으로 인해 평균 평점이 두 배로 나오는 이벤트 비활성화를 위한 초기화
}

void CalcGPA(Subject& sub) { // sub : 교과목 정보가 담긴 Subject 레퍼런스 변수

	if (strcmp(sub.grade, "A+") == 0) // strcmp를 이용하여 등급을 확인한다.
	{
		
		strcpy(sub.grade, "4.5"); // strcpy를 이용하여 등급을 점수로 환산한다.
		double aa = atof(sub.grade); // 문자열로 된 점수를 실수형으로 변환하여 변수에 담는다.
		sub.gpa = sub.hakjum * aa; // 과목학점과 변수를 곱해 과목평점을 구한다.
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

void reGPA(Subject& sub) { // CalcGPA() 함수로 인해 학생 정보 재출력 및 검색 시 과목 등급이 점수로 나오는 문제를 방지 하기 위한 함수
	if (strcmp(sub.grade, "4.5") == 0) // strcmp를 이용하여 과목 점수를 확인
	{
		strcpy(sub.grade, "A+"); // strcpy를 이용하여 과목 점수를 등급으로 환산
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

double CalcAveGPA(Subject* sub) { // 과목 평균 평점 구하는 함수

	sumGPA[i] += sub[j].gpa; // 과목 평점을 더하는 sumGPA 배열
	//cout << "St[i].SubNum: " << St->SubNum << endl;  //menu 2번 출력시 subnum 이상한 수 나옴. -> St[i].SubNum 에서 ' -> '로 바꿈
	St -> aveGPA = sumGPA[i] / St -> SubNum; // 과목 평점을 모두 더해서 과목 수 만큼 나눈 평균 평점
	AveGPA = St -> aveGPA;

	return AveGPA;
}

char name[10]; // 검색할 이름 변수

Student* StdSearch(Student* pSt, int StudentNum) { // 특정 학생의 이름을 검색해서 정보가 있는 주소 리턴하는 함수
	// pSt: 학생정보가 담긴 Student 포인터 변수
	// 리턴값 : 해당 학생의 정보가 있는 곳의 주소

	cout << "검색 할 학생 이름 : "; InputValue(name); cout << endl;
	
	for (i = 0; i < StudentNum; i++) { // 검색에 성공한 경우

		if (strcmp(name, pSt[i].stdName) == 0) { // 검색한 이름과 구조체에 저장된 이름 비교

			return &pSt[i]; // 해당 학생 정보가 있는 주소를 리턴
		}
	}

	for (i = 0; i < StudentNum; i++) { // 검색에 실패한 경우

		if (strcmp(name, pSt[i].stdName) != 0) { // 검색한 이름과 구조체에 저장된 이름 비교

			cout << "등록되지 않은 정보입니다. 다시 입력해주세요\n\n";
			return NULL;
		}
	}
}
