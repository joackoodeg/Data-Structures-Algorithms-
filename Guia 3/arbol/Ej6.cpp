#include <iostream>
#include <tree.hpp>
#include <string>
#include <list>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <map>
using namespace aed;
using namespace std;

bool odd(int x){
	return x%2;
}
	
bool positive(int x){
	return x>0;
}

bool negative(int x){
	return x<0;
}	

void list_if(tree<int> &T,  list<int>&L, bool (*pred)(int x), tree<int>::iterator it){
	if(it==T.end()){return;}
	
	if(pred(*it)){
		L.push_back(*it);
	}
	
	auto h= it.lchild();
	while(h!=T.end()){
		list_if(T,L,pred,h);
		h++;
	}
}	

void list_if(tree<int> &T,list<int>&L,bool (*pred)(int x)){
	tree<int>::iterator p=T.begin();
	list_if(T,L,pred,p);
}	

int main() {
	string s_arbol ("(1 (-2 7(8 -7)(3 -5 -6)))");
	tree<int>arbol;
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else{cout<<"error";}
	
	list<int>L;
	list_if(arbol,L,odd);
	cout<<"lista impares:"<<endl;
	for(auto i: L){cout<<i<<" ";}cout<<endl; L.clear();
	
	list_if(arbol,L,negative);
	cout<<"lista negativos:"<<endl;
	for(auto i: L){cout<<i<<" ";}cout<<endl; L.clear();
	
	
	list_if(arbol,L,positive);
	cout<<"lista positivos:"<<endl;
	for(auto i: L){cout<<i<<" ";}cout<<endl; L.clear();
	
	return 0;
}







