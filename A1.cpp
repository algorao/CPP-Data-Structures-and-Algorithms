/*
Include preprocessor directives to utilize specific functions such as cout, the string class, and more
*/
#include <iostream>
#include <string>

using namespace std;
const int SIZE = 7;
//Creating a 'Day' class
class Day
{
private:
	string day;
	int dayNum;
public:
	string daysOfWeek[SIZE] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	void setDay(string);
	string getDay();
	string getNextDay();
	string getPrevDay();
	string calculateDay(int);
};
void Day::setDay(string s)
{
	day = s;
	for (int i = 0; i < SIZE; i++)
	{
		if (day == daysOfWeek[i])
		{
			dayNum = i;
			return;
		}
	}
	cout << "You haven't entered a valid day; please re-enter a day: ";
	getline(cin, day);
	setDay(day);
}

string Day::getDay()
{
	return day;
}

string Day::getNextDay()
{
	if (dayNum < 6)
	{
		return daysOfWeek[dayNum + 1];
	}
	else
	{
		return daysOfWeek[0];
	}
}

string Day::getPrevDay()
{
	if (dayNum != 0)
	{
		return daysOfWeek[dayNum - 1];
	}
	else
	{
		return daysOfWeek[6];
	}
}

string Day::calculateDay(int n)
{
	int modNum = (n % 7);
	int newDay = ((modNum + dayNum) % 7);
	return daysOfWeek[newDay];


}
int main()
{
	/*
	This is a sample instance that has been created; you can mess around with object instantiation and see what happens for yourself.
	*/
	Day d;
	d.setDay("Sunda");
	Day* dPointer = &d; // Class pointer which points to the already instantiated object 'd' (Of course you can always just use the object itself, but why not mess around? :) )
	string next = dPointer->getPrevDay();
	string newDay = dPointer->calculateDay(12);
	cout << next << '\n' << newDay << endl;
	dPointer = nullptr;
}