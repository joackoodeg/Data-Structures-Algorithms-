#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <map>
using namespace aed;
using namespace std;

void showL(list<int>&L){
	for(auto i :L ){cout<<i<<" ";}
}

//Aux
void orden_de_nivel(tree<int>&T, tree<int>::iterator it, int nivel, map<int, list<int>>& M){
	if(it==T.end())return;
	
	M[nivel].push_back(*it);
	//alt: ++nivel;
	auto h= it.lchild();
	while(h!=T.end()){
		orden_de_nivel(T,h,nivel+1,M); // no es lo mismo q ++nivel // ver clase del 10 min 36 // ver alt
		h++;
	}
	//alt: --nivel;
}

//wrapper
void orden_de_nivel(tree<int>&T){
	map<int,list<int>>M;
	int nivel=0;
	tree<int>::iterator it = T.begin();
	orden_de_nivel(T,it,nivel,M);
	
	list<int>L;
	
	for( map<int,list<int>>::iterator it=M.begin(); it!=M.end(); ++it ) { 
		for( auto it1=it->second.begin(); it1!=it->second.end(); ++it1 ) { 
			L.push_back(*it1);
		}
	}

	showL(L);
}

int main() {
	
	string s_arbol ("(1 2 (3 6 (7 11 12))(4 8)(5 9 (13 10))");
	tree<int>arbol;
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else{cout<<"error";}
	
	orden_de_nivel(arbol);
	
	return 0;
}







