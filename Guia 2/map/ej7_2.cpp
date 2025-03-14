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

int main() {
	
	map<int, list<int>> G = {
		{1, {2,6}},
		{2, {1,3,4,5}},
		{3, {2,5,7,}},
		{4, {2,6}},
		{5, {2,3}},
		{6, {1,4,7}},
		{7, {3,6}}
	};
	
	graph2dot(G);
	list<int> L = {1,2,3,5,3};
	
	if(es_camino(G,L)){
		cout<<"es camino"<<endl;
	}else{
		cout<<"No es"<<endl;
	}
	
	return 0;
}







