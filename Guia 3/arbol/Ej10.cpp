#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
#include <list>
#include <set>

using namespace std;
using namespace aed;

bool verif_sum(tree<int> &T, tree<int>::iterator n){
	if(n == T.end()){
		return true; // si es una hoja siempre cumple la propiedad
	}
	
	int etiqueta= *n;
	int suma_hijos=0;
	
	for(auto hijo=n.lchild(); hijo!= T.end(); hijo++){
		suma_hijos += *hijo;
	}
	
	//parche
	if(suma_hijos==0){
		return true;
	}
	
	if(etiqueta != suma_hijos){
		return false; 
	}
	
	//ahora ver para los hijos del actual
	for(auto hijo = n.lchild(); hijo != T.end(); hijo++){
		if(!verif_sum(T,hijo)){
			return false;
		}
	}
	
	return true;
}

int main() {
	tree<int>T;
	lisp2tree("(10 (6 (5 (3 1 1 1) 1)2) 4)",T);
	tree2dot(T);
	
	if(verif_sum(T,T.begin())){
		cout<<"si"<<endl;
	}else{cout<<"no";}
	
	return 0;
}







