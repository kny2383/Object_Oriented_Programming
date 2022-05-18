// �̸�: �質��
// �й�: 2021041059

#pragma once // ��ó���� ��ȣ�� ����Ͽ� ���� ���ӽ����̽��� �߸��Ǵ� ���� ������
#include "Subject.h" // Student Class�� ���������� Subject Class�� �����
#include <string>
using namespace std;

class Student { // �л� Ŭ����
protected: // Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
	string m_name;	// �л���
	int m_hakbun;	// �й�
	int m_subnum;	// ������ ���� �� 
	Subject* m_sub;	// ������ �����
	float m_aveGPA;	// ������ ������� ��� ����
public: // ��� �ٸ� Ŭ������ ���. Ŭ���� �ۿ��� ���� ���� ����
	Student();	// ����Ʈ ������ (������� �ʱ�ȭ)
	Student(string, int, int, Subject*); // �����ִ� ������ (���ڰ����� ������� �ʱ�ȭ)
	Student(const Student& std); // �ٸ� Student Ŭ������ ��������� ������ �ʱ�ȭ
	void InputValue(int&); // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	void InputValue(string&);  //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	void InputData();	// ������� �� �Է�
	void PrintData();	// ������� �� ���
	void CalcAveGPA();	// ��� ���� ���
	void StdModify(); // �л� �̸� �� �й� ����
	void Modify(); // ������� �� ����
	~Student(); // �Ҹ��� (��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� �Լ�)

	//Subject Class�� ����Լ��� ������ �Լ� �߰�
	// ������ �Լ� : public ���� ������ ���� ��� �Լ�
	string GetName() {
		return m_name;
	}
	int GetHakbun() {
		return m_hakbun;
	}
	int GetSubNum() {
		return m_subnum;
	}
	float GetAveGPA() {
		return m_aveGPA;
	}
	// friend �Լ�
	friend void ShowData(const Student& s);
};