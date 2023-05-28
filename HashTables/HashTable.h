#pragma once
#include <iostream>
#include <string>
using namespace std;



template <class T, class K>
class HashTable
{
protected:

	enum state { empty, full, deleted };
	template <class T, class K>
	class Item
	{
	public:
		T data;
		K key;
		state flag;
		Item() {}
		Item(T d, K  k, state f) { data = d; key = k; flag = f; }
	};

	int size;
	Item<T, K>* arr;
	bool prime(int n)
	{
		if (n <= 1)
			return false;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0)
				return false;
		}
	}

	int hash(K key, int i)
	{
		return ((h1(key) + (h2(key)*i)) % size);
	}

	virtual int h1(K key) = 0;	//position in table
	virtual int h2(K key) = 0;	//step size for probing
public:
	HashTable(int m = 10) {
		while (!prime(m)) { m++; }	//increments m until it is prime
		size = m;
		arr = new Item<T, K>[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].flag = empty;		//sets all values in table to empty
		}
	}

	~HashTable() {
		delete[] arr;
	}
	void add(K& key, T& dat);
	int remove(K key);
	int search(K key)
	{
		for ()
		{
			if (arr[i].key == key)
			{
				return h1(key);
			}
			else { return -1; }
		}
	}

	T* entryData(K i)
	{
		int ind = search(i);
		if (ind == -1)
			return NULL;
		else
			return &(arr[ind].data);
	}
	void print();
};
