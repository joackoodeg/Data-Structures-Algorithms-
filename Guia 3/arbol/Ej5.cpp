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

//aux
int count_if(tree<int> &T,bool (*pred)(int x),tree<int>::iterator it){
	int count=0;
	
	if(it==T.end()){
		return 0;
	}
	
	if(pred(*it)){
		count=1;
	}
	
	auto h=it.lchild();
	while(h != T.end()){
		count += count_if(T,pred,h);
		h++;
	}
	
	return count;
}	
	
//wrapper	
int count_if(tree<int> &T,bool (*pred)(int x)){
	tree<int>::iterator it=T.begin();
	return count_if(T,pred,it);
}
	
int main() {
	
	string s_arbol ("(1 2 (3 6 (7 11 12))(4 8)(5 9 (13 10))");
	tree<int>arbol;
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else{cout<<"error";}
	
	int n=count_if(arbol,odd);
	cout<<"cant impares: "<<n<<endl;
	
	n=count_if(arbol,positive);
	cout<<"cant positivos: "<<n<<endl;
	
	n=count_if(arbol,negative);
	cout<<"cant negativos: "<<n<<endl;
	
	return 0;
}







