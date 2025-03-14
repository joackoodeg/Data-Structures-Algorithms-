#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;

bool es_menor(btree<int>&A,btree<int>::iterator itA, btree<int>&B, btree<int>::iterator itB){
	//Si los arboles estan vacios retorna falso
	if(itA== A.end() && itB == B.end()){return false;}
	
	//Si a esta vacio y B no, se cumple relacion de orden
	if(itA==A.end()){return true;}
	
	//Si b esta vacio y a no, no se cumple la relacion
	if(itB==B.end()){return false;}
	
	//si a<b retorna true
	if(*itA<*itB){return true;}
	if(*itA>*itB){return false;}
	
	//a=b, hay que evaluar hijos izq
	if(es_menor(A,itA.left(),B,itB.left())){return true;}
	
	//Bi no  puede ser menor que Ai
	if(es_menor(B,itB.left(),A,itA.left())){return false;}
		
	
	//hijos derechos
	return es_menor(A,itA.right(),B,itB.right());
}

bool es_menor(btree<int>&A, btree<int>&B){
	return es_menor(A,A.begin(),B,B.begin());
}

int main() {
	
	btree<int> B1,B2;
	
	lisp2btree("(4 (9 4 6)(7 2 3))", B1);
	lisp2btree("(4 (9 4 6)(7 3 4))", B2);
	
	btree2dot(B1,"B1");
	btree2dot(B2,"B2");
	
	if(es_menor(B1,B2)){
		cout<<"Es menor"<<endl;
	}else{
		cout<<"No es menor"<<endl;
	}
	
	return 0;
}







