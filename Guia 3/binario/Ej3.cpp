#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
using namespace aed;
using namespace std;
int cant_nodos_prof(btree<int> &A, int prof,btree<int>::iterator it, int nivel)
{	
	int cant=0;
	
	if(it==A.end()){
		return cant;
	}
	
	if(nivel>=prof){
		cant++;
	}
	nivel++;
	
	cant+=cant_nodos_prof(A,prof,it.left(),nivel);
	cant+=cant_nodos_prof(A,prof,it.right(),nivel);
	
	return cant;
}
///Wrapper
int cant_nodos_prof(btree<int> &A, int prof)
{
	return cant_nodos_prof(A,prof,A.begin(),0);
}

int main(int argc, char *argv[]) {
	btree<int> T;
	
	lisp2btree("(1 (2 3 4) (6 7 .))", T);
	
	btree2dot(T);
	
	cout<<cant_nodos_prof(T,1);
	
	return 0;
}





