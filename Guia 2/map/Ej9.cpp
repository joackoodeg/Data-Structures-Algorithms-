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
	
bool es_camino(map<int,list<int>> G, list<int> &L){
	auto it=L.begin();
		
	while(it!=L.end()){
		auto itM=G.find(*it);
		++it;
		if(!es_vecino(itM->second, *it) && it!=L.end()){
			return false;
		}
	}
	return true;
}

bool has_duplicates(list<int>&L){
	for(auto it=L.begin(); it!=L.end(); ++it ) { 
		for(auto it2=next(it); it2!=L.end(); ++it2 ) { 
			if(*it==*it2){
				return true;
			}
		}
	}
	return false;
}
	
bool isHamilt(map<int,list<int>>&G, list<int>&L){
	if(has_duplicates(L)){
		return false;
	}
	
	//ver si estan todos los nodos
	for(auto&x : G){
		int nodo=x.first;
		if(!es_vecino(L,nodo)){
			return false;
		}
	}

	return es_camino(G,L);
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
	list<int> L = {1,2,4,3,5,6,7};
			
	if(isHamilt(G,L)){
		cout<<"es camino"<<endl;
	}else{
		cout<<"No es"<<endl;
	}
			
	return 0;
}
		
		
		
		
		
		
		
		
