// 이름: 김나영
// 학번: 2021041059

// 클래스를 헤더 파일과 cpp 파일로 분리하여 작성
// 클래스 선언부는 헤더파일.h에 저장한다.
#include "Subject.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

// 파생 클래스 생성자는 항상 내부적으로 기본 클래스 생성자를 호출
// 파생 클래스의 생성자에서 기본 클래스의 생성자가 명시적으로 호출되지 않는다면
// 자동으로 기본 클래스의 디폴트 생성자가 호출되는게 원칙이다.
// 아래의 main() 함수가 오류가 나는 이유는 기본 클래스(IOInterface class)에 디폴트 생성자가 없어서 이다.
void main() {
	Student std;
	cout << std.GetData() << "\n"; // IOInterface Class에서 상속받은 멤버함수 호출
}
