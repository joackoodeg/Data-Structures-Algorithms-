#include <iostream>
#include <list>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

void showL(list<int> L) {
	cout<<"(";
	for(auto i:L) {
		cout<<i<<" ";
	}
	cout<<")"<<endl;
}

/// Auxiliar
tree<int>::iterator list2tree(tree<int>& T, tree<int>::iterator n, list<int>& L, list<int>::iterator& p) {
	/// agrega el valor del nodo
	n = T.insert(n, *p);
	
	/// avanza el iterator para obtener la 
	/// cantidad de hijos a procesar
	++p;
	
	/// obtiene la cantidad de hijos del nodo
	int cantHijos = *p;
	++p;
	
	/// reconstruccion de los hijos
	tree<int>::iterator hijoIzq = n.lchild();
	for(int i = 0; i < cantHijos; i++) {
		hijoIzq = list2tree(T, hijoIzq, L, p);
		hijoIzq++;
	}
	
	return n;
}

/// Wrapper
void list2tree(tree<int>& T, list<int>& L) {
	list<int>::iterator p = L.begin();
	list2tree(T, T.begin(), L, p);
}


void tree2list(tree<int>& T,tree<int>::iterator itT, list<int>&L){
	if(itT==T.end()){return;}
	
	L.push_back(*itT);
	int n_hijos=0;
	
	auto h=itT.lchild();
	while(h!=T.end()){
		h++;
		n_hijos++;
	}
	
	L.push_back(n_hijos);
	auto c=itT.lchild();
	while(c!=T.end()){
		tree2list(T,c,L);
		c++;
	}
	
}


void tree2list(tree<int>& T, list<int>&L){
	tree2list(T,T.begin(),L);
}


int main(int argc, char *argv[]) {
	tree<int> T;
	
	//	lisp2tree("(6 4 8 (5 4 4) 7 9)", T);
	
	list<int> L = {6, 5, 4, 0, 8, 0, 5, 2, 4, 0, 4, 0, 7, 0, 9, 0};
	
	list2tree(T, L);
	
	tree2dot(T);
	
	L.clear();
	tree2list(T,L);
	showL(L);
	
	return 0;
}




