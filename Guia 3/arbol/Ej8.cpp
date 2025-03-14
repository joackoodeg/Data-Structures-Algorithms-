#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <list>
#include <set>

using namespace std;
using namespace aed;

typedef map<int,set<int>> graph;

int contar_nodos(tree<int>&T,tree<int>::iterator p){
	int count=0;
	if(p==T.end()){return count;}
	count=1;
	tree<int>::iterator child=p.lchild();
	while(child!=T.end()){
		count+=contar_nodos(T,child);
		child++;
	}
	return count;
}
	
int contar_nodos(tree<int>&T){
	auto it=T.begin();
	return contar_nodos(T,it);
}
	
int contar_nodos(graph G){
	auto p=G.begin();
	int count=0;
	while(p!=G.end()){
		count++;
	}
	return count;
}	
	
bool es_arbol_de_expansion(graph G, tree<int> T, set<int>&visitados, tree<int>::iterator it){
	if(visitados.find(*it)!=visitados.end()){
		return false;//unicidad
	}
	visitados.insert(*it);
	
	if(G.find(*it)==G.end()){ //existencia
		return false;
	}
	
	tree<int>::iterator c = it.lchild();
	set<int>&n_vecinos=G[*it];
	while(c!=T.end()){
		if(n_vecinos.find(*c++)==n_vecinos.end()){ //verificamos que cada hijo este en la lista de vecinos
			return false;
		}
	}
	
	//verificar que cada subarbol este en c
	c=it.lchild();
	while(c!=T.end()){
		if(!es_arbol_de_expansion(G,T,visitados,c++)){
			return false;
		}
	}
	
	return true;
}

	
	
bool es_arbol_de_expansion(graph G, tree<int> T){
	if(T.begin() == T.end()){
		return true;
	}
		
	if(contar_nodos(T)!=G.size()){
		return false;
	}
	set<int>visitados;
	auto it=T.begin();
	return es_arbol_de_expansion(G,T,visitados,it);
}	

int main() {
	tree<int>T;
	lisp2tree("(1 2 4(3 5))",T);
	tree2dot(T);
	
	graph G={
		{1,{2,3,4}},
		{2,{1,4}},
		{3,{1,4,5}},
		{4,{2,1,3,5}},
		{5,{3,4}}
	};
	
	if(es_arbol_de_expansion(G,T)){
		cout<<"si"<<endl;
	}else{cout<<"no"<<endl;}
	
	return 0;
}







