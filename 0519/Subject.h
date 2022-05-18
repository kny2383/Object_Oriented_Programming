// �̸�: �質��
// �й�: 2021041059

#pragma once // ��ó���� ��ȣ�� ����Ͽ� ���� ���ӽ����̽��� �߸��Ǵ� ���� ������
#include <string> // ���ڿ� ���
using namespace std;

class Subject { // ���� Ŭ����
protected:
	string m_name;	// �����
	int m_hakjum;	// ����
	string m_grade;	// ���
	float m_GPA;	// ����
public:
	Subject();	// ����Ʈ ������ (������� �ʱ�ȭ)
	Subject(string, int, string);	// �����ִ� ������ (���ڰ����� ������� �ʱ�ȭ)
	Subject(const Subject& sub); // ���� ������ (�ٸ� Subject Ŭ������ ��������� ������ �ʱ�ȭ)
	void InputValue(int&); // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	void InputValue(string&); //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	void InputData();	// ������� �� �Է�
	void PrintTitle();	// ��������� ���� title Text ���
	void PrintData();	// ������� �� ���
	void CalcGPA();		// ���� ���
	void Modify(); // ȭ�鿡�� �ԷµǴ� �����ͷ� Subject Class�� ������� �� ����
	~Subject(); // �Ҹ��� (��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� �Լ�)

	//Subject Class�� ����Լ��� ������ �Լ� �߰�
	// ������ �Լ� : public ���� ������ ���� ��� �Լ�
	string GetName() {
		return m_name;
	}
	int GetHakjum() {
		return m_hakjum;
	}
	string GetGrade() {
		return m_grade;
	}
	float GetGPA() {
		return m_GPA;
	}

	void SetName(string subName) {
		m_name = subName;
	}
	void SetHakjum(int subHakjum) {
		m_hakjum = subHakjum;
	}
	void SetGrade(string subGrade) {
		m_grade = subGrade;
	}
	void SetGPA(float subGPA) {
		m_GPA = subGPA;
	}
};