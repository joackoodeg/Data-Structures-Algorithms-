#include <iostream>
#include <list>
using namespace std;

void merge(list<int> &L1, list<int> &L2, list<int> &L) {
	list<int>::iterator it1 = L1.begin();
	list<int>::iterator it2 = L2.begin();
	
	while (it1 != L1.end() && it2 != L2.end()) {
		if (*it1 < *it2) {
			L.push_back(*it1);
			++it1;
		} else {
			L.push_back(*it2);
			++it2;
		}
	}
	
	// Agregar los elementos restantes de L1 (si los hay)
	while (it1 != L1.end()) {
		L.push_back(*it1);
		++it1;
	}
	
	// Agregar los elementos restantes de L2 (si los hay)
	while (it2 != L2.end()) {
		L.push_back(*it2);
		++it2;
	}
}

int main() {
	list<int> L1 = {1, 3, 6, 11};
	list<int> L2 = {2, 4, 6, 10};
	list<int> mergedList;
	
	merge(L1, L2, mergedList);
	
	cout << "Merged List: ";
	for (int num : mergedList) {
		cout << num << " ";
	}
	cout <<endl;
	
	return 0;
}





