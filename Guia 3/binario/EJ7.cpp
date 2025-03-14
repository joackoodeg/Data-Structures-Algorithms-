#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;

bool contenido(btree<int> &A, btree<int> &B,btree<int>::iterator itA, btree<int>::iterator itB){
	if(itA==A.end()){return true;} /// LA LINEA MAS IMP
	
	if(itA!=A.end() && itB==B.end()){return false;} 

	if(*itA>=*itB){return false;}
	
	if(!contenido(A,B,itA.left(),itB.left())){return false;}
	if(!contenido(A,B,itA.right(),itB.right())){return false;}
	
	return true;
}

bool contenido(btree<int> &A, btree<int> &B){
	return contenido(A,B,A.begin(),B.begin());
}

int main() {
	
	btree<int>BT1,BT2;
	
	lisp2btree ("(4 (9 . 8)(5 7 8))", BT1);
	lisp2btree ("(5 (10 7 9)(6 8 9))", BT2);
	
	btree2dot(BT1,"BT1");
	btree2dot(BT2,"BT2");
	
	if(contenido(BT1,BT2)){
		cout<<"Si "<<endl;
	}else{
		cout<<"NO "<<endl;
	}
	
	return 0;
}







