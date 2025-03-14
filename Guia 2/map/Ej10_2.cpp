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
	map<int, list<int>> capas; // Usamos listas en lugar de conjuntos
	queue<int> cola;
	map<int,bool>visitados;
	
	cola.push(x);
	visitados[x]=true;
	capas[0].push_back(x); // Usamos push_back en lugar de insert
	
	int nivel = 0;
	
	while (!cola.empty()) {
		nivel++;
		int elementosEnNivel = cola.size();
		for (int i = 0; i < elementosEnNivel; i++) {
			int actual = cola.front();
			cola.pop();
			
			for (int vecino : G[actual]) {
				if (visitados.find(vecino) == visitados.end()) {
					visitados[vecino]=true;
					capas[nivel].push_back(vecino); // Usamos push_back en lugar de insert
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
		{4, {5,6,7}},
		{5, {6}},
		{6, {7}},
		{7, {1}}
	};
	
	graph2dot(G);
	
	map<int,list<int>>Capas=calcularCapas(G,1);
	
	mostrarMapa(Capas);
	return 0;
}








