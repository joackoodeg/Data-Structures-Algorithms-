#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

void showL(list<int>&L){
	for(auto i: L){cout<<i<<" ";}cout<<endl;
}

void prefijo(tree<int>&arbol, tree<int>::iterator p, list<int>&L){
	if(p==arbol.end()) return;
	
	L.push_back(*p);

	tree<int>::iterator h= p.lchild();
	while(h != arbol.end()){
		prefijo(arbol,h,L);
		h++;
	}
}

void postfijo(tree<int>&arbol, tree<int>::iterator p, list<int>&L){
	if(p==arbol.end()) return;
	
	tree<int>::iterator h= p.lchild();
	while(h != arbol.end()){
		postfijo(arbol,h,L);
		h++;
	}
	
	L.push_back(*p);
}


int main() {
	
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8)(5 9 (13 10))");
	tree<int>arbol;
	
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else {
		cout<<"error";
	}
	
	
	cout<<"prefijo :"<<endl;
	list<int>L;
	tree<int>::iterator it= arbol.begin();
	prefijo(arbol,it,L);
	showL(L);
	
	cout<<"postfijo :"<<endl;
	L.clear();
	it=arbol.begin();
	postfijo(arbol,it,L);
	showL(L);
	
	return 0;
}







