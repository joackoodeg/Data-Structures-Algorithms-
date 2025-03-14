#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <map>
using namespace aed;
using namespace std;


void showL(list<int>&L){
	for(auto i: L){cout<<i<<" ";}cout<<endl;
}
	
void get_path(tree<int>& T, tree<int>::iterator q, int n, list<int>& L) {
	if (q == T.end()) {
		return; // Nodo nulo, regresamos sin añadir nada a la lista
	}
		
	if (*q == n) {
		L.push_front(*q);
		return; // Nodo encontrado, agregamos el valor a la lista y regresamos
	}
		
	// Si no se cumple ninguna de las condiciones anteriores, exploramos los hijos
	auto hijo = q.lchild();
	while (hijo != T.end()) {
		list<int> sublista;
		get_path(T, hijo, n, sublista);
			
		if (!sublista.empty()) {
			sublista.push_front(*q);
			L = sublista; // Si encontramos un camino en los hijos, lo actualizamos y regresamos
			return;
		}
			
		++hijo;
	}
}
void get_path(tree<int> &T,int n,list<int> &L){
	get_path(T,T.begin(),n,L);
	showL(L);
}


int main() {
	string s_arbol ("(5 (1 8 (9 2)) (7 3))");
	tree<int>arbol;
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else{cout<<"error";}
	
	list<int>L;
	get_path(arbol,8,L);

	return 0;
}







