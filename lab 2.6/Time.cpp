#include "Time.h"
#include <sstream>
#include <iostream>

using namespace std;

bool Time::secondCheck(int s)
{
	if (s < 0 || s >= 60)
	{
		cout << "Wrong arguments to Init! = " << endl;
		return false;
	}
	else
		return true;
}

bool Time::minuteCheck(int s)
{
	if (s < 0 || s >= 60)
	{
		cout << "Wrong arguments to Init! = " << endl;
		return false;
	}
	else
		return true;
}

void Time::IncreaseSecond(int second)
{
	int a1;
	if (second + triad.getC() >= 60)
	{
		triad.augmentationB();
		if (triad.getB() >= 60)
		{
			triad.augmentationA();
			triad.setB(0);
		}
		a1 = second + triad.getC() - 60;
	}
	else
	{
		a1 = second + triad.getC();
	}
	triad.setC(0);
	for (int i = 0; i < a1; i++)
	{
		triad.augmentationC();
	}
}

void Time::IncreaseMinute(int minute)
{
	int a1;
	if (minute + triad.getB() >= 60)
	{
		triad.augmentationA();
		if (triad.getA() >= 24)
		{
			cout << "Error, 24hour = one day" << endl;
			triad.setA(0);
		}
		a1 = minute + triad.getB() - 60;
		triad.setB(a1);
	}
	else
	{
		a1 = minute + triad.getB();
	}
	triad.setB(0);
	for (int i = 0; i < a1; i++)
	{
		triad.augmentationB();
	}
}

Time::Time()
{
	triad = Triad(0, 0, 0);
}

Time::Time(int a, int b, int c)
{
	triad = Triad(a, b, c);
}
Time::Time(const Time& q)
{
	triad = q.triad;
}

Time::~Time()
{}

Time& Time::operator = (const Time& q)
{
	triad = q.triad;
	return *this;
}

Time::operator string () const
{
	stringstream ss;
	cout << triad;
	return ss.str();
}

ostream& operator << (ostream& output, const Time& q)
{
	output << string(q);
	return output;
}
istream& operator >> (istream& input, Time& q)
{
	cout << ""; input >> q.triad;
	cout << endl;
	return input;
}
Time& Time::operator ++()
{
	triad++;
	return *this;
}
Time& Time::operator --()
{
	triad--;
	return *this;
}
Time Time::operator ++(int)
{
	Time t(*this);
	triad++;
	return t;
}
Time Time::operator --(int)
{
	Time t(*this);
	triad--;
	return t;
}

void Time::Triad::augmentationA()
{
	a += 1;
}

void Time::Triad::augmentationB()
{
	b += 1;
}

void Time::Triad::augmentationC()
{
	c += 1;
}

Time::Triad::Triad()
{
	a = 0;
	b = 0;
	c = 0;
}
Time::Triad::Triad(int aa, int bb, int cc)
{
	a = aa;
	b = bb;
	c = cc;
}

Time::Triad::Triad(const Triad& q)
{
	a = q.a;
	b = q.a;
	c = q.c;
}
Time::Triad::~Triad()
{}

Time::Triad& Time::Triad::operator = (const Time::Triad& q)
{
	a = q.a;
	b = q.b;
	c = q.c;
	return *this;
}
Time::Triad::operator string () const
{
	stringstream ss;
	ss << " hour = " << a << endl;
	ss << " minute = " << b << endl;
	ss << " second = " << c << endl;
	return ss.str();
}

ostream& operator << (ostream& output, const Time::Triad& q)
{
	output << string(q);
	return output;
}
istream& operator >> (istream& input, Time::Triad& q)
{
	cout << " hour = "; input >> q.a;
	cout << " minute = "; input >> q.b;
	cout << " second = "; input >> q.c;
	cout << endl;
	return input;
}
Time::Triad& Time::Triad::operator ++()
{
	a++;
	return *this;
}

Time::Triad Time::Triad::operator ++(int)
{
	Triad t(*this);
	c++;
	return t;
}

Time::Triad& Time::Triad::operator --()
{
	a--;
	return *this;
}

Time::Triad Time::Triad::operator --(int)
{
	Triad t(*this);
	c--;
	return t;
}