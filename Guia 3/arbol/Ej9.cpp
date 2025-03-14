#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <list>
#include <set>
//crea tantos niveles como para que las hojas sean en valor < n
//todos los niveles suman M
//g es una cota de la cant de hijos

using namespace std;
using namespace aed;

void crea(double M, int g, int n, tree<double>& T, tree<double>::iterator it){
	tree<double>::iterator child = it.lchild();
	
	double childValue = M/g;
	
	for(int i=0;i<g;i++) { 
		child=T.insert(child,childValue);
	}
	
	//si no se alcanzo la condicion <n hago hijos hasta que suceda.
	if(childValue>n){
		while(child!=T.end()){
			crea(childValue,g,n,T,child);
			child++;
		}
	}
}

tree<double>crea(double M, int n){
	tree<double>T;
	tree<double>::iterator it=T.begin();
	it=T.insert(it,M);
	if(n>=M) return T;
	
	int g=3; // cant hijos por nivel
	crea(M,g,n,T,it);
	return T;
}

int main() {
	tree<double>T;
	T=crea(10,2);
	tree2dot(T);
	
	return 0;
}







