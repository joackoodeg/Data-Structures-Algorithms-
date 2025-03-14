#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main(int argc, char *argv[]) {
	
	int x = 42; //variable de tipo int
	
	int *p; // puntero a int, guarda la direccion de memoria de algun entero
	
	p = &x; //p toma la direccion de memoria de x
	
	
	//los couts:
	
	cout<<p<<endl; //muestra la direccion de la variable x
	cout<<*p<<endl; //sigue la flecha y muestra el valor de p
	
	//Iterators
	
	vector<int> v(15,0);
	for(vector<int>::iterator it = v.begin(); it!=v.end(); it++) {
		*it = 1+ rand()%100;
	}
	
	vector<int> b(15,0);
	for (int &x : b){
		x= 1+rand()%10;
	}
	
	
	//mostrar
	for(int i : v){
		cout<<i<<" ";
	}	cout<<endl;
	
	for(int i : b){
		cout<<i<<" ";
	}cout<<endl;
	
	//LIST && STL
	
	//list tiene una interfaz muy similar a la de dvecotr, pero no permite acceso aleatorio:
	// - no tiene sobrecarga del operador []
	// - sus iteradores solo pueden "moverse" con ++ y --
	
	//Multiples posiciones: advance(it,N); adavance(it,-N);
	// sin modificar el iterador: it1= prev(it,N); it2=next(it,N);
	
	
	list<int> l(15,0);
	for( list<int>::iterator it=l.begin(); it!=l.end(); ++it ) { 
		*it = rand()%100;
	}
	
	list<int> s(15,0);
	for( auto it=s.begin(); it!=s.end(); ++it ) { 
		*it = rand()%100;
	}
	
	for(auto it: l){cout<<it<<" ";} cout<<endl;
	
	//insert:
	int w= 10;
	list<int>::iterator it5 = l.begin();
	advance(it5,4);
	l.insert(it5,w); //devuelve un iterador7
	
	for(auto it: l){cout<<it<<" ";}
	
	
	
	return 0;
}

