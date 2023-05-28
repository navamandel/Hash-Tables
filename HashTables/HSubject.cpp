#include "HashTable.h"
#include "HSubject.h"

using namespace std;

void HSubject::printS(string ky) {

}

void HSubject::printN(string ky, int N) {

}

void HSubject::print() {

}

void HSubject::startNewTable() {
	for (int i = 0; i < size; i++) {
		arr[i].data.clear();
		arr[i].key.clear();
		arr[i].flag = empty;
	}
}

void HSubject::addSubjectAndTitle(string s, string t) {

}