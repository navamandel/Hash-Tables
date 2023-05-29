/*
* Rachel Wolfe  and Nava Mandel 582813107
* Data Structures II, Homework 2
*/

#include "HashTable.h"
#include "HSubject.h"

using namespace std;


int main()
{
	char ch;
	int n;
	HSubject hs(1000);
	string subject, title;

	cout << "Hash Table\n";
	cout << "\nChoose one of the following" << endl;
	cout << "n: New hash table" << endl;
	cout << "a: Add a subject and a title" << endl;
	cout << "d: Del a subject " << endl;
	cout << "t: Print all titles of the subject " << endl;
	cout << "s: Print N first appearances of a subect " << endl;
	cout << "p: Print all non-empty entries " << endl;
	cout << "e: Exit" << endl;
	do
	{
		cout << "Choose one of the above options\n";
		cin >> ch;
		switch (ch)
		{

		case 'n':hs.startNewTable(); break;
		case 'a':cout << "Enter a subject and a title\n";
			cin >> subject >> title;
			hs.addSubjectAndTitle(subject, title);
			break;
		case 'd':cout << "Enter a subject to remove\n";
			cin >> subject;
			hs.remove(subject); break;
		case 't':cout << "Enter subject to print\n";
			cin >> subject;
			hs.printS(subject); break;
		case 's':cout << "Enter a subject and N\n"; cin >> subject >> n;
			hs.printN(subject, n); break;
		case 'e':cout << "Bye\n"; break;
		case 'p':hs.print(); break;
		default: cout << "ERROR\n";  break;
		}
	} while (ch != 'e');
	return 0;
}