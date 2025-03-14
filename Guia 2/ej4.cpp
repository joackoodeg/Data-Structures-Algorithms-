#include <iostream>
#include <list>
using namespace std;

//Invierte. Escribir una funci´on void invert(list<int> &L), que invierte el orden de la lista L.
//	Este algoritmo debe implementarse in place y debe ser O(n). Restricci´on: no utilizar el m´etodo
//	size()

void invert(list<int> &L){
	auto it=L.begin();
	auto it2=prev(L.end());
		while((it!=it2)and(it2!=prev(it))){ // o it!=next(it2)		swap(*it,*it2);		it++;it2--;	}
}

int main() {
	
	list<int> l(15,0);
	for(list<int>::iterator it=l.begin(); it!=l.end(); ++it ) { 
		*it = rand()%100+1;
	}
	
	for(auto it: l){cout<<it<<" ";} cout<<endl;
	
	invert(l);
	
	for(auto it: l){cout<<it<<" ";} cout<<endl;
	
	return 0;
}






