#include <iostream>
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

void altura(tree<int> &T, tree<int>::iterator it, int prof, int &alt){
	if(it==T.end()){return;}
	
	auto h=it.lchild();
	while(h!=T.end()){
		altura(T,h,prof+1,alt);
		h++;
	}
	
	if(prof>alt){
		alt=prof;
	}
}
	
void contar_hojas(tree<int> &T, tree<int>::iterator it,int &hojas){
	if(it==T.end()){return;}
	
	auto h=it.lchild();
	if(h==T.end()){
		hojas++;
	}
	
	while(h!=T.end()){
		contar_hojas(T,h,hojas);
		h++;
	}
}

void etiqueta_maxima(tree<int> &T, tree<int>::iterator it,int &et_max){	
	if(it==T.end()){return;}
	if(*it>et_max){et_max=*it;}
	
	auto h=it.lchild();
	while(h!=T.end()){
		etiqueta_maxima(T,h,et_max);
		h++;
	}
}
	 
void etiqueta_maxima_par(tree<int> &T, tree<int>::iterator it,int &et_max){
	if(it==T.end()){return;}
	
	if(*it%2==0 && *it>et_max){
		et_max=*it;
	}
	
	auto h=it.lchild();
	while(h!=T.end()){
		etiqueta_maxima_par(T,h,et_max);
		h++;
	}
}
	
void etiqueta_maxima_hojas(tree<int> &T, tree<int>::iterator it,int &et_max){
	auto h=it.lchild();
	if(h==T.end()){
		if(*it>et_max){
			et_max=*it;
		}
	}
	
	while(h!=T.end()){
		etiqueta_maxima_hojas(T,h,et_max);
		h++;
	}
}

void suma_etiquetas(tree<int> &T, tree<int>::iterator it,int &suma){
	if(it==T.end()){return;}
	suma+=*it;
	
	auto h=it.lchild();
	while(h!=T.end()){
		suma_etiquetas(T,h,suma);
		h++;
	}
	
}

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
	
	if(lisp2tree(s_arbol,arbol)){
		tree2dot(arbol);
	}else {
		cout<<"error";
	}
	
	int alt=0;
	altura(arbol, arbol.begin(), 0, alt);
	cout<<"altura: "<<alt<<endl;
	
	int n_hojas=0;
	contar_hojas(arbol,arbol.begin(),n_hojas);
	cout<<"hojas: "<<n_hojas<<endl;
	
	int et_max=-1;
	etiqueta_maxima(arbol,arbol.begin(),et_max);
	cout<<"et max: "<<et_max<<endl;
	
	int et_max_par=-1;
	etiqueta_maxima_par(arbol,arbol.begin(),et_max_par);
	cout<<"et max par: "<<et_max_par<<endl;
	
	int et_max_hoja=-1;
	etiqueta_maxima_hojas(arbol,arbol.begin(),et_max_hoja);
	cout<<"et max hojas: "<<et_max_hoja<<endl;
	
	int suma=0;
	suma_etiquetas(arbol,arbol.begin(),suma);
	cout<<"suma: "<<suma<<endl;
	
	
	purge_odd(arbol,arbol.begin());
	tree2dot(arbol,"arbol_sin_pares");
	return 0;
}







