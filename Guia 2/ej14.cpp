#include <iostream>
#include <list>
using namespace std;

void merge(list<int> &L1, list<int> &L2, list<int>& L){
	list<int>::iterator itL1 = L1.begin();
	list<int>::iterator itL2 = L2.begin();
	
	while(itL1 != L1.end() && itL2 != L1.end() ){
		
		if(*itL1<*itL2){
			L.push_back(*itL1);
			++itL1;
		}else {
			L.push_back(*itL2);
			++itL2;
		}
	}
	
	// Agregar los elementos restantes de L1 (si los hay)
	while (itL1 != L1.end()) {
		L.push_back(*itL1);
		++itL1;
	}
	
	// Agregar los elementos restantes de L2 (si los hay)
	while (itL2 != L2.end()) {
		L.push_back(*itL2);
		++itL2;
	}
}
	

int main() {
	
	list<int>L1{1, 3, 6, 11};
	list<int>L2{2, 4, 6, 10};
	list<int>L;
	
	merge(L1,L2,L);
	for(auto i:L){cout<<i<<" ";}cout<<endl;
	
	return 0;
}






