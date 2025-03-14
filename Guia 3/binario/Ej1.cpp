#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
using namespace aed;
using namespace std;


/// Arbol binario
/// PREFIJO: nodo actual, orden_prev(hijo_izq),orden_prev(hijo_der);
/// PREFIJO: nodo actual, orden_prev(hijo_mas_izq), orden_prev(++hijo_mas_izq)...

/// IN_FIJO: orden_infijo(hijo_izq), nodo_actual, orden_infijo(hijo_derecho)

/// POSTFIJO: orden_post(hijo_izq), orden_post(hijo_derecho), nodo_actual


void orden_prev(btree<int>& T, btree<int>::iterator it) {
	if(it==T.end()){
		return;
	}
	
	cout<<*it<<" ";
	orden_prev(T,it.left());
	orden_prev(T,it.right());
}
/* ALTERNATIVA
void orden_prev(btree<int>& T, btree<int>::iterator it) {
	while(it!=T.end()){
		cout<<*it<<" ";
		orden_prev(T,it.left());
		orden_prev(T,it.right());
	}
}
*/
void orden_post(btree<int>& T, btree<int>::iterator it) {
	if(it==T.end()){
		return;
	}
	
	orden_post(T,it.left());
	orden_post(T,it.right());
	cout<<*it<<" ";
}

/* ALTERNATIVA
void orden_post(btree<int>& T, btree<int>::iterator it) {
	while(it!=T.end()){
		orden_post(T,it.left());
		orden_post(T,it.right());
		cout<<*it<<" ";
	}
}*/

void orden_sim(btree<int>& T, btree<int>::iterator it) {
	if(it==T.end()){
		return;
	}
	
	orden_sim(T,it.left());
	cout<<*it<<" ";
	orden_sim(T,it.right());
}

int main(int argc, char *argv[]) {
	btree<int> T;
	
	lisp2btree("(1 (2 3 4) (6 7 .))", T);
	
	btree2dot(T);
	
	cout<<"Orden prev:"<<endl;
	orden_prev(T, T.begin());
	cout<<endl;
	
	cout<<"Orden prev:"<<endl;
	orden_post(T, T.begin());
	cout<<endl;
	
	cout<<"Orden sim:"<<endl;
	orden_sim(T, T.begin());
	cout<<endl;
	
	return 0;
}





