#include <iostream>
#include <map>
#include <list>
#include <set>
using namespace std;

void genCompConexa(map<int,list<int>> &G, set<int> &visitados, int label, list<int>&cc){
	visitados.insert(label);
	cc.push_back(label);
	list<int>& adyacentes = G[label];
	for(auto vecino: adyacentes){
		if(visitados.find(vecino) == visitados.end()){
			genCompConexa(G,visitados,vecino,cc);
		}
	}
}

list<list<int>> comp_conexas(map<int,list<int>> &G){
	list<list<int>>CC;
	set<int>visitados;
	
	while(visitados.size()<G.size()){
		int label;
		for(auto vertice: G){
			if(visitados.find(vertice.first)==visitados.end()){ //si no esta visitado
				label = vertice.first;
				break;
			}
		}
		//generar componentye conexa.
		list<int>cc;
		genCompConexa(G,visitados,label,cc);
		
		CC.push_back(cc);
		
	}
	
	return CC;
}

int main() {
	map<int,list<int>>G = {
		{1,{2}},
		{2,{1}},
		{3,{4}},
		{4,{3}}
	};
	
	list<list<int>> CC = comp_conexas(G);
	
	for(auto sublist: CC){
		for(auto i: sublist){
			cout<<i<<" ";
		}cout<<endl;
	}
	
	return 0;
}







