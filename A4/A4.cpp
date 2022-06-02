#include "Class.h"
#include <string>
#include <iostream>

using namespace std;

IntList::~IntList()
{
	this->destroy();
}
void IntList::insertNode(int i)
{
	ListNode* l1 = new ListNode;
	l1->value = i;
	l1->next = nullptr;
	if (head == nullptr)
	{
		head = l1;
	}
	else
	{
		ListNode* counter = head;
		while (counter->next != nullptr)
		{
			counter = counter->next;
		}
		counter->next = l1;
		counter = nullptr;
	}

}
void IntList::deleteNode(int i)
{
	ListNode* counter = head;
	if (counter->value == i)
	{
		head = counter->next;
		delete[] counter;
	}
	else
	{
		while (counter->next != nullptr)
		{
			if (counter->next->value != i)
			{
				counter = counter->next;
			}
			else
			{
				ListNode* temp = counter->next->next;
				delete[] counter->next;
				counter->next = temp;
			}
		}

	}
}
void IntList::print()
{
	ListNode* counter = head;
	while (counter != nullptr)
	{
		cout << counter->value << " " << endl;
		counter = counter->next;
	}
}
void IntList::reverse()
{
	ListNode* temp = head;
	ListNode* temp2 = nullptr;
	if (head != nullptr)
	{
		head = head->next;
		temp->next = nullptr;
	}
	while (head->next != nullptr)
	{
		temp2 = head->next;
		head->next = temp;
		temp = head;
		head = temp2;
	}
	head->next = temp;
	temp = nullptr;
	temp2 = nullptr;
}
void IntList::destroy()
{
	cout << "Deleted" << endl;
	delete[] head;
	head = nullptr;
}
int IntList::getlistSize()
{
	if (head != nullptr)
	{
		ListNode* temp = head;
		int counter = 1;
		while (temp->next != nullptr)
		{
			temp = temp->next;
			counter++;
		}
		return counter;
	}
	return 0;
}
void IntList::removeByPos(int i)
{
	if (this->getlistSize() <= i)
	{
		cout << "Error; no such element exists at position " << i << " (YOU NEED TO TREAT A LINKED LIST LIKE AN ARRAY WHEN ACCESSING ELEMENTS)." << endl;
		return;
	}
	else
	{
		int counter = 0;
		ListNode* temp = head;
		if (i == 0)
		{
			head = head->next;
			delete[] temp;
		}
		else
		{
			while ((counter + 1) < i)
			{
				temp = temp->next;
				counter++;
			}
			ListNode* temp2 = temp->next->next;
			delete[] temp->next;
			temp->next = temp2;
		}

	}

}