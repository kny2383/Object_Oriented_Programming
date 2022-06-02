// 이름: 김나영
// 학번: 2021041059

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	Subject sub("컴퓨터", 3, "C0");
	cout << "------------------------------- \n";

	// IOInterface Class에서 상속받은 GetData() 호출;
	cout << "m_data : " << sub.IOInterface::GetData() << "\n";

	// Subject Class에서 재정의된 GetName() 호출;
	cout << "교과목 이름 : " << sub.GetName() << "\n";
	
	//IOInterface Class의 GetName() 호출;
	cout << "부모클래스의 이름 : " << sub.IOInterface::GetName() << "\n";
	cout << "------------------------------- \n\n";

	Student std("홍길동", 2013909845, 1, &sub);
	cout << " -------------------------------\n";

	//IOInterface Class에서 상속받은 GetData() 호출;
	cout << "m_data : " << std.IOInterface::GetData() << "\n";

	//Student Class에서 재정의된 GetName() 호출;
	cout << "학생 이름 : " << std.GetName() << "\n";
	
	//IOInterface Class의 GetName() 호출;
	cout << "부모클래스의 이름 : " << std.IOInterface::GetName() << "\n";
	cout << " -------------------------------\n\n";
}