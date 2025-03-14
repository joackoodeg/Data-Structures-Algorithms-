#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;


void countlevel(tree<int>&T,tree<int>::iterator it, int n, int level){
	if(it == T.end())return;
	tree<int>::iterator h = it.lchild();
	
	if(n==level){
		cout<<*it<<" ";
	}else{
		while(h!=T.end()){
			countlevel(T,h,n+1,level);
			h++;
		}
	}
}
	
void count_level(tree<int>&T, int level){
	int n=0;
	tree<int>::iterator p = T.begin();
	while(level != -1){
		cout<<"Nivel ";
		cout<<level<<": ";
		countlevel(T,p,n,level);
		cout<<endl;
		level--;
	}
}
	

int main() {
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8)(5 9 (13 10))");
	tree<int>arbol;

	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else {
		cout<<"error";
	}
		
	count_level(arbol,3);

	return 0;
}
	
	
