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

		Triad(); // конструктор за умовчанням
		Triad(int, int, int); // конструктор ініціалізації
		Triad(const Triad&); //копіювання
		~Triad();
		void augmentationA();
		void augmentationB();
		void augmentationC();


		Triad& operator = (const Triad&); // присвоєння
		friend istream& operator >> (istream&, Triad&); //введення з клавіатури
		friend ostream& operator << (ostream&, const Triad&); //вивід на екран
		operator string() const; //приведення типу – перетворення у літерний рядок

		Triad& operator ++(); // префіксний інкремент
		Triad operator ++(int); // постфіксний інкремент
		Triad& operator --(); // префіксний декремент
		Triad operator --(int); // постфіксний декремент
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

	Time(); // конструктор за умовчанням
	Time(int, int, int); // конструктор ініціалізації
	Time(const Time&); //копіювання
	~Time();

	Time& operator = (const Time&); // присвоєння
	friend istream& operator >> (istream&, Time&); //введення з клавіатури
	friend ostream& operator << (ostream&, const Time&); //вивід на екран
	operator string() const; //приведення типу – перетворення у літерний рядок

	Time& operator ++(); // префіксний інкремент
	Time operator ++(int); // постфіксний інкремент
	Time& operator --(); // префіксний декремент
	Time operator --(int); // постфіксний декремент
};