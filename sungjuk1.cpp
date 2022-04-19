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
	int stdNum; // 학번
	Subject sub[3]; // 과목
	double aveGPA; // 교과목 평균 평점
};

struct Student student[2]; // 학생 구조체 두 명 제한

void selectMenu(); // 입력받은 기능을 각각의 함수로 실행하는 함수

int main(void) { // 메인 메뉴 화면 보여주는 함수
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 프로그램 종료\n\n";
	selectMenu();
}

int menuNum; // 기능 입력 전역 변수 선언 
int inputGrade(); // 학생 성적 입력 함수
int allStudentGrade(); // 학생 정보 및 과목 정보 출력 함수

void selectMenu() { // 입력받은 기능을 각각의 함수로 실행하는 함수

	cout << "원하는 기능을 입력하세요 : "; cin >> menuNum; // 기능을 입력 받는다.
	cout << "\n";

	switch (menuNum)
	{
	case 1:
		inputGrade(); // 학생 성적 입력 함수
		selectMenu(); // 입력 후 메뉴 입력 화면으로 넘어가기
	case 2:
		allStudentGrade(); // 전체 학생 성적 보기 함수
		selectMenu(); // 입력 후 메뉴 입력 화면으로 넘어가기
	case 3:
		cout << "프로그램을 종료합니다.";
		exit(0); // 프로그램 종료 
	}
}

int i, j;  // 반복문을 위한 전역 변수

int inputGrade() { // 학생 성적 입력 함수

	for (i = 0; i < 2; i++) // 두 명의 학생 정보만 입력 받는 제한
	{
		// 구조체에 정보 입력 받기
		cout << "*" << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : "; cin >> student[i].stdName; 
		cout << "학번 : "; cin >> student[i].stdNum;
		cout << "\n\n";
		cout << "* 수강한 과목3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

		for (j = 0; j < 3; j++) { // 세 과목 정보 입력 받기
			cout << "교과목명 : "; cin >> student[i].sub[j].subName; // 과목명 입력 받기
			cout << "과목학점수 : "; cin >> student[i].sub[j].hakjum; // 과목학점수 입력 받기
			cout << "과목등급<A+ ~ F> : "; cin >> student[i].sub[j].grade; // 과목등급 입력 받기
			cout << "\n";
		}
	}
	return 0;
}

void gpaConversion(int i, int j); // 문자열로 된 점수를 실수형으로 변환하여 변수에 담고 연산자를 이용해 과목평점을 구하는 함수

double sumGPA[2] = {}; // 과목 평점을 더하는 sumGPA 배열

int allStudentGrade() { // 학생 정보 및 과목 정보 출력 함수

	cout.width(10); // 출력할 내용의 폭 지정
	cout << "전체 학생  성적 보기\n";
	cout << "========================================================================\n";

	for (i = 0; i < 2; i++) { // 학생이 두 명이여서 두 번 반복

		// 구조체를 이용해 학생 정보 출력
		cout << "이름 : " << student[i].stdName; 
		cout << " 학번 : " << student[i].stdNum;
		cout << "\n========================================================================\n";
		cout << "           과목명  과목학점  과목등급  과목평점\n";
		cout << "========================================================================\n";

		for (j = 0; j < 3; j++) {
			cout.width(15); // 출력할 내용의 폭 지정
			cout << student[i].sub[j].subName; // 과목 이름 출력
			cout.width(10); 
			cout << student[i].sub[j].hakjum; // 과목학점수 출력
			cout.width(10); 
			cout << student[i].sub[j].grade; // 과목 등급 출력
			cout.width(10); 

			gpaConversion(i, j); // 문자열로 된 점수를 실수형으로 변환하여 변수에 담고 연산자를 이용해 과목평점을 구하는 함수

			cout.precision(2); // 소수점 이하 2자리만 출력하도록 고정
			cout << fixed;

			cout << student[i].sub[j].gpa; // 과목평점 출력
			sumGPA[i] += student[i].sub[j].gpa; // 과목 평점을 더하는 sumGPA 배열
			cout << "\n";
			cout << "========================================================================\n";
		}

		cout.width(50);
		cout << "평균평점     ";
		student[i].aveGPA = sumGPA[i] / 3.0 ; // 과목 평점을 모두 더해서 과목 수 만큼 나눈 평균 평점
		cout << student[i].aveGPA; // 평균 평점 출력
		cout << "\n";
	}
	return 0;
}

void gpaConversion(int i, int j) { // 문자열로 된 점수를 실수형으로 변환하여 변수에 담고 연산자를 이용해 과목평점을 구하는 함수

	if (strcmp(student[i].sub[j].grade, "A+") == 0) // strcmp를 이용하여 등급을 확인한다.
	{
		strcpy(student[i].sub[j].grade, "4.5"); // strcpy를 이용하여 등급을 점수로 환산한다.
		double aa = atof(student[i].sub[j].grade); // 문자열로 된 점수를 실수형으로 변환하여 변수에 담는다.
		student[i].sub[j].gpa = student[i].sub[j].hakjum * aa; // 과목학점과 변수를 곱해 과목평점을 구한다.
	}
	else if (strcmp(student[i].sub[j].grade, "A0") == 0)
	{
		strcpy(student[i].sub[j].grade, "4.0");
		double a = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * a;
	}
	else if (strcmp(student[i].sub[j].grade, "B+") == 0)
	{
		strcpy(student[i].sub[j].grade, "3.5");
		double bb = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * bb;
	}
	else if (strcmp(student[i].sub[j].grade, "B0") == 0)
	{
		strcpy(student[i].sub[j].grade, "3.0");
		double b = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * b;
	}
	else if (strcmp(student[i].sub[j].grade, "C+") == 0)
	{
		strcpy(student[i].sub[j].grade, "2.5");
		double cc = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * cc;
	}
	else if (strcmp(student[i].sub[j].grade, "C0") == 0)
	{
		strcpy(student[i].sub[j].grade, "2.0");
		double c = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * c;
	}
	else if (strcmp(student[i].sub[j].grade, "D+") == 0)
	{
		strcpy(student[i].sub[j].grade, "1.5");
		double dd = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * dd;
	}
	else if (strcmp(student[i].sub[j].grade, "D0") == 0)
	{
		strcpy(student[i].sub[j].grade, "1.0");
		double d = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * d;
	}
	else if (strcmp(student[i].sub[j].grade, "F") == 0)
	{
		strcpy(student[i].sub[j].grade, "0.0");
		double f = atof(student[i].sub[j].grade);
		student[i].sub[j].gpa = student[i].sub[j].hakjum * f;
	}
}