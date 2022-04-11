#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
	Time s;
	cout << "Time:" << endl;
	cin >> s;

	int c, b;
	do
	{
		cout << "IncreaseSecond = "; cin >> c;

	} while (!s.secondCheck(c));

	s.IncreaseSecond(c);
	cout << s << endl;
	do
	{
		cout << "IncreaseMinute = "; cin >> b;

	} while (!s.minuteCheck(b));
	s.IncreaseMinute(b);

	cout << s << endl;

	return 0;
}