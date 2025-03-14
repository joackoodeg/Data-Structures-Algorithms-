#include <iostream>
#include <map>
#include <list>
using namespace std;

bool es_camino(map<int,list<int>> G, list<int> &L) {
	if (L.empty()) {
		return true; // Un camino vac�o es considerado v�lido.
	}
	
	auto it = L.begin();
	int current_vertex = *it;
	
	while (next(it) != L.end()) {
		int next_vertex = *next(it);
		
		auto adj_list = G.find(current_vertex);
		if (adj_list == G.end() || find(adj_list->second.begin(), adj_list->second.end(), next_vertex) == adj_list->second.end()) {
			return false; // No hay conexi�n entre los v�rtices, no es un camino v�lido.
		}
		
		current_vertex = next_vertex;
		it++;
	}
	
	return true; // Se recorri� toda la lista sin problemas, es un camino v�lido.
}

int main() {
	map<int, list<int>> G = {
		{1, {2,3}},
		{2, {3}},
		{3, {4}},
		{4, {}}
	};
	list<int> L = {1, 2, 3, 4};
	
	if(es_camino(G, L)){
		cout<<"es camino"<<endl;
	}else{
		cout<<"no es"<<endl;
	}
	
	
	return 0;
}







