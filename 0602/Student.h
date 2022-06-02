// �̸�: �質��
// �й�: 2021041059

#pragma once // ��ó���� ��ȣ�� ����Ͽ� ���� ���ӽ����̽��� �߸��Ǵ� ���� ������
#include "Subject.h" // Student Class�� ���������� Subject Class�� �����
#include "IOInterface.h" // IOInterface�� ����� ���� 
#include <string>
using namespace std;

// IOInterface�� ����� ����
// class �Ļ�Ŭ�����̸� : ���ٺ����� �⺻Ŭ�����̸�
class Student : public IOInterface { // �л� Ŭ����
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
	~Student(); // �Ҹ��� (��ü�� �Ҹ�Ǵ� �������� �ڵ����� ȣ��Ǵ� �Լ�)
	// const ��� �Լ� : ��ü�� ���� �������� �ʱ�� ����ϴ� ��� �Լ�
	Subject* SubSearch(string subname) const;  // ���� Ž��
	void InputValue(int&); // �޴�, �л���, ����� �Է� �޴� �ζ��� �Լ�
	void InputValue(string&);  //  �̸�, �й�, ����� �Է� �޴� �ζ��� �Լ�
	void InputData();	// ������� �� �Է�
	void PrintData() const;	// ������� �� ���
	void CalcAveGPA();	// ��� ���� ���
	void StdModify(); // �л� �̸� �� �й� ����
	void Modify(); // ������� �� ����
	

	//Subject Class�� ����Լ��� ������ �Լ� �߰�
	// ������ �Լ� : public ���� ������ ���� ��� �Լ�
	// const ��ü�� Get�Լ��� ȣ���� �� Get�Լ��� const�� �ƴϸ� ���� �߻���. 
	string GetName() const {
		return m_name;
	}
	int GetHakbun() const {
		return m_hakbun;
	}
	int GetSubNum() const {
		return m_subnum;
	}
	float GetAveGPA() const{
		return m_aveGPA;
	}
	// friend �Լ�
	friend void ShowData(const Student& s);
};