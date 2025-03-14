#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>

using namespace aed;
using namespace std;

tree<int>::iterator purge_odd(tree<int> &T, tree<int>::iterator it){
	if(it==T.end()){return it;}
	
	if(*it%2!=0){
		it=T.erase(it);
	}else{
		auto h=it.lchild();
		while(h!=T.end()){
			h=purge_odd(T,h);
			h++;
		}
	}
	return it;
}
	

int main() {
	
	string s_arbol("(10 2 (3 6 (7 11 12))(4 8)(6 9 (41 10))");
	tree<int>arbol;
	
	lisp2tree(s_arbol,arbol);
	
	purge_odd(arbol,arbol.begin());
	tree2dot(arbol);
	
	return 0;
}







