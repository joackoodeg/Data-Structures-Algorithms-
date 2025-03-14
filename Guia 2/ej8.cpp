#include <iostream>
#include <list>
#include <vector>
using namespace std;

//Ascendente2. Escribir una funci´on void ascendente2(list<int> &L, vector<list<int>> &VL)
//	que, dada una lista L, genera un vector de listas VL de tal forma de que cada sublista es ascendente.

void ascendente2(list<int> &L, vector<list<int>> &VL){
	auto it = L.begin();
	
	while (it != L.end()) {
		list<int> subList;
		int prev = *it;
		
		while (it != L.end() && *it >= prev) {
			subList.push_back(*it);
			prev = *it;
			it++;
		}
	VL.push_back(subList);
	}
}
	
void showVL(const vector<list<int>> &VL) {
	for (const list<int> &subList : VL) {
		for (const int &num : subList) {
			cout << num << " ";
		}
		cout << endl;
	}
}	
	

int main() {
	list<int>L{1,2,3,4,5,1,2,3,1,7,2,4};
	vector<list<int>> VL;
	ascendente2(L,VL);
	showVL(VL);
	return 0;
}







