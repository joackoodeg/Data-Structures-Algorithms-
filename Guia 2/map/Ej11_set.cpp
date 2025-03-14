#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <set>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

void colorearGrafo(map<int, list<int>>& G, map<int, int>& colores) {
	for(auto par: G){
		set<int>coloresVecinos;
		int vertice=par.first;
		
		for(int vecino: par.second){
			if(colores.find(vecino) != colores.end()){
				coloresVecinos.insert(colores[vecino]);
			}
		}
		
		//busca el minimo color
		int color=1;
		while(coloresVecinos.find(color)!= coloresVecinos.end()){
			color++;
		}
		
		colores[vertice]=color;
	}
}

int main() {
	map<int, list<int>> G;
	G[1] = {2, 3};
	G[2] = {1, 4};
	G[3] = {1, 5};
	G[4] = {2};
	G[5] = {3, 6};
	G[6] = {5};
	
	graph2dot(G);
	map<int, int> colores;
	colorearGrafo(G, colores);
	
	for (const auto& par : colores) {
		cout << "Vértice " << par.first << " - Color " << par.second << endl;
	}
	return 0;
}







