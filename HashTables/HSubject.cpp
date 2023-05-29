#pragma once
#include <iostream>
#include "HashTable.h"
#include "HSubject.h"
using namespace std;

void HSubject::printS(string ky) {
	
	int i = search(ky);
	if (i == -1)
		cout << "Error\n";
	
	else
	{
		cout << "Subject " << arr[i].key << " "
			<< arr[i].data.size() << " topics: \n";
		printD(arr[i]);
	}
}

void HSubject::printN(string ky, int N) {

	int index = search(ky);
	if (index == -1)
		cout << "Error\n";
	
	else
	{
		list<string>::iterator iter = arr[index].data.begin();
		for (int i = 0; i < N; i++, iter++)
		{
			if (iter != arr[index].data.end())
				cout << *iter << " \n";
		}
	}
}

void HSubject::printD(Item<list<string>, string> d)
{
	for (string da : d.data)
		cout << da << " ";

	cout << "\n";
}

void HSubject::print() {

	cout << "All subjects and titles: \n";

	int count = 0;
	vector<string> strings;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].flag == full)
		{
			strings.push_back(arr[i].key);
			count++;
		}
	}
	sort(strings.begin(), strings.end());
	for (int i = 0; i < count; i++)
	{
		int index = search(strings[i]);
		cout << arr[index].key << ": ";

		for (string str : arr[index].data)
			cout << str << " ";

		cout << endl;
	}
}

void HSubject::startNewTable() {
	for (int i = 0; i < size; i++) {
		arr[i].data.clear();
		arr[i].key.clear();
		arr[i].flag = empty;
	}
	return;
}

void HSubject::addSubjectAndTitle(string s, string t) {
	
	int i = search(s);
	if (i == -1)
	{
		list<string> lst;
		lst.push_front(t);
		add(s, lst);
	}
	else
		arr[i].data.push_front(t);
}