#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

bool es_vecino(list<int>& L, int nodo){
	auto it=L.begin();
	while(it!=L.end()){
		if(*it==nodo){
			return true;
		}
		++it;
	}
	return false;
}
	
bool isHamilt(map<int,list<int>> G, list<int> &L){
	auto it=L.begin();
	map<int,bool>visitados;
	
	while(it!=L.end()){
		auto itM=G.find(*it);
		if(!visitados[*it]){
			visitados[*it]=true;
			++it;
			if(!es_vecino(itM->second, *it) && it!=L.end()){
				return false;
			}
		}else{
			return false;
		}
	}
	return true;
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
	list<int> L = {1,2,3,4,5,6,7};
	
	if(isHamilt(G,L)){
		cout<<"es camino"<<endl;
	}else{
		cout<<"No es"<<endl;
	}
	
	return 0;
}
		
		
		
		
		
		
		
		
