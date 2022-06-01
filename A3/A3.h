#include <string>
#include <iostream>
using namespace std;
class DynamicStringArray
{
private:
	int size;
	string* dynamicArray;
public:
	DynamicStringArray();
	DynamicStringArray(const DynamicStringArray&);
	int getSize() { return size; };
	void addEntry(string);
	void deleteEntry(string);
	string getEntry(int);
	~DynamicStringArray();
	DynamicStringArray& operator=(const DynamicStringArray&);
};


