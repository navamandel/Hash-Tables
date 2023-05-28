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

	HashTable(int m = 10) {     //ctor
		while (!prime(m)) { m++; }	//increments m until it is prime
		size = m;
		arr = new Item<T, K>[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].flag = empty;		//sets all values in table to empty
		}
	}

	~HashTable() {    //dtor
		delete[] arr;
	}

	//Adds a new entry to the table
	void add(K& key, T& dat) {
		for (int i = 0; i < size; i++) {
			int index = hash(key, i);    //finds the index using the hash function
			if (arr[index].flag != full) {    //makes sure place is not already taken
				arr[index] = new Item(dat, key, full);
			}
		}
	}

	//Removes existing entry from the table
	int remove(K key) {
		if (search(key) != -1) {
			arr[search(key)].flag = deleted;
			return 1
		}
		return -1

	}

	//Serches for an entry for any given key and returns the position in the table
	int search(K key)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].key == key)
			{
				return h1(key);
			}
			else { return -1; }
		}
	}

	//Updates the data of the entry
	void update(T curr) {
		data = curr;
	}

	//Returns the point of the data
	T* entryData(K i)
	{
		int ind = search(i);
		if (ind == -1)
			return NULL;
		else
			return &(arr[ind].data);
	}

	//Prints the contents of the table
	void print() {
		for (int i = 0; i < size; i++) {
			cout << arr[i].key << "   " << arr[i].data << endl;
		}
	}
};
