#include <iostream>
#include <list>
#include <string>

using namespace std;

void show_list(list<int>& L) {
	for(auto i: L){cout<<i<<" ";}cout<<endl;
}

void show_list(list<string>& L) {
	for(auto i: L){cout<<i<<" ";}cout<<endl;
}

/// Problema de Josephus
list<string> josephus(list<string>& nombres, int n) {
	//buscar
	list<string>eliminados;
	auto it=nombres.begin();
	while(!nombres.empty()){
		for(int i=0;i<n;i++) { 
			++it;
			if(it==nombres.end()){
				it=nombres.begin();
			}
		}
		
		eliminados.push_back(*it);
		it=nombres.erase(it);
		
		//parche para que no quede apuntando al final
		if(it==nombres.end()){
			it=nombres.begin();
		}
	}
	return eliminados;
}


int main(int argc, char *argv[]) {
	list<string> nombres = {"roberto", "maria", "juana", "pepe", "daniel", "rosa"};
	
	list<string> resultado = josephus(nombres, 2);
	
	show_list(resultado);	
	
	return 0;
}





