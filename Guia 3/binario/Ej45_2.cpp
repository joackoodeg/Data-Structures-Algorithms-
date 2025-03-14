#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;

void bin2ord(btree<int> &B, tree<int> &T, btree<int>::iterator itB,tree<int>::iterator itT){
	
	if(itB==B.end()){return;}
	
	*itT=*itB;
	
	tree<int>::iterator l,r;
	
	if(itB.left()!=B.end() || itB.right()!=B.end()){
		l=itT.lchild();
		l= T.insert(l,-1);
		
		r=l;
		r++;
		r=T.insert(r,-1);
		
		bin2ord(B,T,itB.left(),l);
		bin2ord(B,T,itB.right(),r);
	}
}
	
void bin2ord(btree<int> &B, tree<int> &T) {
	T.clear();
		
	if(B.begin()==B.end()){
		return;
	}
		
	T.insert(T.begin(),-1);
		
	bin2ord(B,T,B.begin(),T.begin());
}
	
void ord2bin(tree<int> &T, btree<int> &B,tree<int>::iterator itT, btree<int>::iterator itB){
	if(itT==T.end() || *itT==-1){
		return;
	}
	
	itB=B.insert(itB,*itT);
	
	tree<int>::iterator l,r;
	
	l=itT.lchild();
	if(l==T.end()){return;}
	
	r=l;
	r++;
	if(r==T.end()){return;}
	
	ord2bin(T,B,l,itB.left());
	ord2bin(T,B,r,itB.right());
}
		
		
void ord2bin(tree<int> &T, btree<int> &B){
	B.clear();
			
	ord2bin(T,B,T.begin(),B.begin());
}
			
int main() {
				btree<int> TB;
				
				lisp2btree("(1 (2 3 4) (6 7 .))", TB);
				
				btree2dot(TB,"TB");
				
				tree<int>TT;
				
				bin2ord(TB,TT);
				
				tree2dot(TT,"TT");
				
				/////////
							
				btree<int>TB2;
				
				ord2bin(TT,TB2);
				
				btree2dot(TB2,"TB2");
				
	return 0;
}
			
