#include <iostream>
#include <string>
using namespace std;

void TowersofHanoi(int, string, string, string);
int main()
{
	TowersofHanoi(3, "A", "B", "C");
}

void TowersofHanoi(int i, string to, string goal, string temp)
{
	if (i != 1)
	{
		TowersofHanoi(i - 1, to, temp, goal);
		cout << to << " to " << goal << endl;
		TowersofHanoi(i - 1, temp, goal, to);

	}

	else
	{
		cout << to << " to " << goal << endl;
	}
}