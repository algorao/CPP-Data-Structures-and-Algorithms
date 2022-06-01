#include "Class.h"
DynamicStringArray::DynamicStringArray() : size(0), dynamicArray(nullptr) {}
DynamicStringArray::DynamicStringArray(const DynamicStringArray& p)
{
	size = p.size;
	if (size != 0)
	{
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = p.dynamicArray[i];
		}
	}
	else
	{
		dynamicArray = nullptr;
	}
}
DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& p)
{
	size = p.size;
	if (size != 0)
	{
		dynamicArray = new string[size];
		for (int i = 0; i < size; i++)
		{
			dynamicArray[i] = p.dynamicArray[i];
		}
	}
	else
	{
		dynamicArray = nullptr;
	}
	return *this;
}
DynamicStringArray::~DynamicStringArray()
{
	cout << "Deleted" << endl;
	delete[] dynamicArray;
	dynamicArray = nullptr;
}
void DynamicStringArray::addEntry(string s)
{
	string* ndynamicArray = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		ndynamicArray[i] = dynamicArray[i];
	}
	ndynamicArray[size] = s;
	size += 1;
	delete[] dynamicArray;
	dynamicArray = ndynamicArray;
	ndynamicArray = nullptr;
}

void DynamicStringArray::deleteEntry(string s)
{
	int element = -1;
	for (int i = 0; i < size; i++)
	{
		if (s == dynamicArray[i])
		{
			element = i;
			break;
		}
	}
	if (element != -1)
	{
		string* ndynamicArray = new string[size - 1];
		int counter = 0;
		for (int i = 0; i < size; i++)
		{
			if (element != i)
			{
				ndynamicArray[counter] == dynamicArray[i];
				counter++;
			}
		}
		size -= 1;
		delete[] dynamicArray;
		dynamicArray = ndynamicArray;
		ndynamicArray = nullptr;
	}
	else
	{
		cout << "Error! This string doesn't exist!" << endl;
	}
}

string DynamicStringArray::getEntry(int i)
{
	if (dynamicArray == nullptr)
	{
		return "0";
	}
	else
	{
		return dynamicArray[i];
	}
}
