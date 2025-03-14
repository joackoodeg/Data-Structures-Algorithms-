#include <iostream>
#include <list>
using namespace std;

//Ascendente1. Escribir una funci´on void ascendente1(list<int> &L, list<list<int>> &LL)
//	que, dada una lista L, genera una lista de listas LL de tal forma de que cada sublista es ascendente.

void ascendente1(list<int> &L, list<list<int>> &LL){
	auto it = L.begin();
	
	while (it != L.end()) {
		list<int> subList;
		int prev = *it;
		
		while (it != L.end() && *it >= prev) {
			subList.push_back(*it);
			prev = *it;
			it++;
		}
		LL.push_back(subList);
	}
}
	
void showLL(const list<list<int>> &LL) {
	for (const list<int> &subList : LL) {
		for (const int &num : subList) {
			cout << num << " ";
		}
		cout << endl;
	}
}	

int main() {
	
	list<int>L{1,2,3,4,5,1,2,3,1,7,2,4};
	
	list<list<int>>LL;
	
	ascendente1(L,LL);
	
	showLL(LL);
	return 0;
}







