#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

void countlevel(tree<int>&T,tree<int>::iterator it, int &currentLevel, int &nnodos, int maxLevel){
	if(it == T.end())return;
	
	if(currentLevel==maxLevel){
		++nnodos;
		--currentLevel;
		return;
	}
	
	auto h = it.lchild();
	while(h!=T.end()){
		countlevel(T,h,++currentLevel,nnodos,maxLevel);
		h++;
	}

	--currentLevel;
}

int count_level(tree<int>&T, int level){
	int n=0;
	int nnodos=0;
	countlevel(T,T.begin(),n,nnodos,level);
	return nnodos;
}

int main() {
	
	string s_arbol("(1 2 (3 6 (7 11 12))(4 8)(5 9 (13 10))");
	tree<int>arbol;
	
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else {
		cout<<"error";
	}
	
	int level=count_level(arbol,3);
	cout<<"cant: "<<level<<endl;
	
	
	return 0;
}







