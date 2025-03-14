#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
#include <queue>
#include <set>
using namespace aed;
using namespace std;

void mostrarMapa(map<int, list<int>>& G) {
	for (const auto& par : G) {
		int clave = par.first;
		list<int> valores = par.second;
		
		cout << "Nivel: " << clave << " - Valores: ";
		for (int valor : valores) {
			cout << valor << " ";
		}
		cout << endl;
	}
}

map<int, list<int>> calcularCapas(map<int, list<int>>& G, int x) {
	map<int, list<int>> capas; 
	queue<int> cola;
	set<int> visitados;
	
	cola.push(x);
	visitados.insert(x);
	capas[0].push_back(x); 
	
	int nivel = 0;
	
	while (!cola.empty()) {
		nivel++;
		int elementosEnNivel = cola.size();
		for (int i = 0; i < elementosEnNivel; i++) {
			int actual = cola.front();
			cola.pop();
			
			for (int vecino : G[actual]) {
				if (visitados.find(vecino) == visitados.end()) {
					visitados.insert(vecino);
					capas[nivel].push_back(vecino); 
					cola.push(vecino);
				}
			}
		}
	}
	
	return capas;
}

int main() {
	map<int, list<int>> G = {
		{1, {2}},
		{2, {3}},
		{3, {4}},
		{4, {5}},
		{5, {6}},
		{6, {7}},
		{7, {1}}
	};
	
	graph2dot(G);
	
	map<int,list<int>>Capas=calcularCapas(G,1);
	
	mostrarMapa(Capas);
	return 0;
}







