#include <iostream>
#include <list>
using namespace std;

//Junta. Escribir una funci´on void junta(list<int> &L, int c) que, dada una lista L, agrupa de
//	a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como argumento la lista
//	L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despu´es de aplicar el algoritmo junta(L,3) debe quedar
//	L=(6,11,10,14,4) (notar que se agrupan los ´ultimos elementos, pese a no completar los tres
//					  requeridos). El algoritmo debe tener un tiempo de ejecuci´on O(n).

void junta(list<int> &L, int c){
	auto it=L.begin();
	
	while(it!=L.end()){
		
		auto current=it;
		int suma=0;
		
		for(int i=0;i<c;i++) { 
		suma += *current;
		current ++;
		}
		it = L.erase(it,current); 
		L.insert(it,suma);
		
		if (distance(it, L.end()) < c) {
			suma=0;
			for(int i=0; i<distance(it, L.end());i++){
				suma += *current;
				current ++;
			}
			it = L.erase(it,current); 
			L.insert(it,suma);
		}
	}
	
}

int main() {
	
	list<int> L={1,3,2,4,5,2,2,3,5,7,4,3,2,2};
	
	junta(L,3);
	
	for(auto i:L){cout<<i<<" ";}cout<<endl;
	
	
	return 0;
}







