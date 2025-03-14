#include <iostream>
#include <set>
#include <list>
using namespace std;

void showSet(set<int>&A){
	for(auto i: A){
		cout<<i<<" ";
	}cout<<endl;
}

void set_union(set<int> &A,set<int> &B,set<int> &C){
	C=A;
	C.insert(B.begin(),B.end());
}
	
void set_difference(set<int> &A,set<int> &B,set<int> &C){
	//Elementos que estan en A y NO en B
	C.clear();
		
	for(auto elem: A){
		if(B.count(elem)==0) //No esta en B
		{
			C.insert(elem);
		}
	}
}
	
/*
void diffsym(list<set<int> > &L, set<int> &ad){
	auto it1= L.begin();
	
	for(auto it2=next(it1); it2!=L.end(); it2++){
		set<int>aux1,aux2;
		
		set_difference(*it1,*it2,aux1);
		
		set_difference(*it2,*it1,aux2);
		
		set_union(aux1,aux2,ad);
		
		++it1;
	}

}
*/
/*
void diffsym(list<set<int> > &L, set<int> &ad){
	set<int>allElements;
	
	for(const set<int>&s: L){
		for(int elem: s){
			if(allElements.count(elem)>0){
				ad.erase(elem);
			}else{
				ad.insert(elem);
			}
			allElements.insert(elem);
		}
	}
}
*/	
	
void diffsym(list<set<int>>& L, set<int>& ad) {
	ad.clear(); // Limpiamos el conjunto ad
		
	// Iteramos sobre la lista de conjuntos
	for (const set<int>& s : L) {
		// Iteramos sobre los elementos del conjunto s
		for (int elem : s) {
			// Contamos cuántas veces aparece el elemento en la lista de conjuntos
			int count = 0;
			for (const set<int>& otherSet : L) {
				if (otherSet.count(elem) > 0) {
					count++;
				}
			}
				
			// Si el elemento aparece exactamente una vez, lo agregamos a ad
			if (count == 1) {
				ad.insert(elem);
			}
		}
	}
}

int main() {
	
	set<int> A = {1,2,4,5,7};
	set<int> B = {6,7,8,9,2};
	set<int> C = {8,10,4,7,44};
	
	list<set<int>> L = {A,B,C};
	
	set<int>ad;
	
	diffsym(L,ad);
	showSet(ad);
	
	return 0;
}







