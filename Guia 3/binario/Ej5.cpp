#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;


void ord2bin(tree<int> &T, btree<int> &B,tree<int>::iterator itT, btree<int>::iterator itB){
	
	if(itT==T.end() || *itT==-1){return;}
	
	itB=B.insert(itB,*itT);
	
	tree<int>::iterator l,r;
	
	l=itT.lchild();
	if(l==T.end()){
		return;  ///itT es hoja
	}
	
	r=l; r++;
	assert(r!=T.end()); ///si es r es end tira un break
	
	
	ord2bin(T,B,l,itB.left());
	ord2bin(T,B,r,itB.right());
}


void ord2bin(tree<int> &T, btree<int> &B){
	B.clear();
	
	ord2bin(T,B,T.begin(),B.begin());
}

int main() {
	
	tree<int> TT;
	
	lisp2tree("(1 (2 3 4) (6 7))", TT);
	
	tree2dot(TT);

	btree<int>TB;
	
	ord2bin(TT,TB);
	
	btree2dot(TB);

	return 0;
}







