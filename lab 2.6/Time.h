#pragma once
#include <string >
#include <sstream>
using namespace std;

class Time
{
public:
	class Triad
	{
	private:
		int a;
		int b;
		int c;
	public:
		int getA() const { return a; }
		int getB() const { return b; }
		int getC() const { return c; }
		void setA(int a) { this->a = a; }
		void setB(int b) { this->b = b; }
		void setC(int c) { this->c = c; }

		Triad(); // ����������� �� ����������
		Triad(int, int, int); // ����������� �����������
		Triad(const Triad&); //���������
		~Triad();
		void augmentationA();
		void augmentationB();
		void augmentationC();


		Triad& operator = (const Triad&); // ���������
		friend istream& operator >> (istream&, Triad&); //�������� � ���������
		friend ostream& operator << (ostream&, const Triad&); //���� �� �����
		operator string() const; //���������� ���� � ������������ � ������� �����

		Triad& operator ++(); // ���������� ���������
		Triad operator ++(int); // ����������� ���������
		Triad& operator --(); // ���������� ���������
		Triad operator --(int); // ����������� ���������
	};
private:
	Triad triad;
public:
	Triad getTriad() const { return triad; }
	void setTriad(Triad triad) { this->triad = triad; }

	void IncreaseSecond(int second);
	void IncreaseMinute(int minute);
	bool secondCheck(int);
	bool minuteCheck(int);

	Time(); // ����������� �� ����������
	Time(int, int, int); // ����������� �����������
	Time(const Time&); //���������
	~Time();

	Time& operator = (const Time&); // ���������
	friend istream& operator >> (istream&, Time&); //�������� � ���������
	friend ostream& operator << (ostream&, const Time&); //���� �� �����
	operator string() const; //���������� ���� � ������������ � ������� �����

	Time& operator ++(); // ���������� ���������
	Time operator ++(int); // ����������� ���������
	Time& operator --(); // ���������� ���������
	Time operator --(int); // ����������� ���������
};