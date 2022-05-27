/*
	Will be updating this assignment shortly; would like to optimize a few things
*/
#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
	int day, month, year;
public:
	int monthVals[2][12] = { {1,2,3,4,5,6,7,8,9,10,11,12},
							{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
	Date(int, int, int);
	Date();
	void setMonth(int);
	void setDay(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear()const;
	bool isLeap();
	int numDaysMonth();
	int numberOfDaysPassed();
	int numberOfDaysLeft();
	void incrementDate(int);
};
Date::Date(int m, int d, int y)
{
	day = d;
	month = m;
	year = y;
}
void Date::setMonth(int m)
{
	if (m <= 12 && m >= 1)
	{
		month = m;
		return;
	}
	else
	{
		int m;
		cout << "Error! Please enter a valid month: ";
		cin >> m;
		this->setMonth(m);
	}
}

void Date::setDay(int d)
{
	if (d <= 12 && d >= 1)
	{
		day = d;
		return;
	}
	else
	{
		int d;
		cout << "Error! Please enter a valid day: ";
		cin >> d;
		this->setMonth(d);
	}
}

void Date::setYear(int y)
{
	if (y >= 0)
	{
		year = y;
		return;
	}
	else
	{
		int y;
		cout << "Error! Please enter a valid year: ";
		cin >> y;
		this->setMonth(y);
	}
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

bool Date::isLeap()
{
	if (((year % 4) == 0) && ((year % 100) != 0))
	{
		return true;
	}
	return false;
}

int Date::numDaysMonth()
{
	bool leap = isLeap();
	if (leap)
	{
		monthVals[1][1] = 29;
	}
	return monthVals[1][month - 1];
}

int Date::numberOfDaysPassed()
{
	int counter = 1;
	int sum = 0;
	if (this->isLeap())
	{
		this->monthVals[1][1] = 29;
	}
	while (counter < month)
	{
		sum += this->monthVals[1][counter - 1];
		counter++;
	}
	sum += day;
	return sum;
}

int Date::numberOfDaysLeft()
{
	int numDaysPassed = numberOfDaysPassed();
	int yearNum = 365;
	if (isLeap())
	{
		yearNum = 366;
	}
	int numDaysLeft = yearNum - numDaysPassed;
	return numDaysLeft;
}
/*
	This function will take a number and 3 scenarios will appear:

	1. (num + day) will be able to fit within the current month. If so, we just change the day (no change in month/year)
	2. (num + day) will not fit into the current month, so we just recursively call this function until it can fit within some other month (no change in the year)
	3. (num + day) will not fit into the current month AND year, so we replicate step 2 but also ensure that the year is incremented
*/
void Date::incrementDate(int num)
{
	if (isLeap())
	{
		monthVals[1][1] = 29;
	}
	else
	{
		monthVals[1][1] = 28;
	}
	if ((num + day) <= monthVals[1][month - 1])
	{
		day += num;
		cout << year << "  " << month << "    " << day;
	}
	else if ((num + day) > monthVals[1][month - 1])
	{
		num = ((num + day) - monthVals[1][month - 1]);

		if (month == 12)
		{
			year++;
			month = 1;
			day = 0;
			incrementDate(num);
		}
		else
		{
			month++;
			day = 0;
			incrementDate(num);
		}
	}

}
int main()
{

	/*
		Please play around w/ these values!
	*/
	Date d(1, 18, 2004);
	cout << d.getDay() << endl;
	cout << d.numberOfDaysPassed() << endl;
	cout << d.numberOfDaysLeft() << endl;
	cout << d.numDaysMonth() << endl;
	d.incrementDate(455);


}