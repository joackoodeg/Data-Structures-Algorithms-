#include <iostream>
#include <map>
#include <list>
using namespace std;

bool es_camino(map<int,list<int>> G, list<int> &L) {
	if (L.empty()) {
		return true; // Un camino vacío es considerado válido.
	}
	
	auto it = L.begin();
	int current_vertex = *it;
	
	while (next(it) != L.end()) {
		int next_vertex = *next(it);
		
		auto adj_list = G.find(current_vertex);
		if (adj_list == G.end() || find(adj_list->second.begin(), adj_list->second.end(), next_vertex) == adj_list->second.end()) {
			return false; // No hay conexión entre los vértices, no es un camino válido.
		}
		
		current_vertex = next_vertex;
		it++;
	}
	
	return true; // Se recorrió toda la lista sin problemas, es un camino válido.
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







