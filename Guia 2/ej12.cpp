#include <iostream>
#include <list>
#include <string>

//Compacta. Escribir una funci´on void compacta(list<int> &L,list<int> &S) que toma un
//	elemento entero n de S y, si es positivo, saca n elementos de L y los reemplaza por su suma. Esto
//	ocurre con todos los elementos de S hasta que se acaben, o bien se acaben los elementos de L.

using namespace std;

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<" ";
	}
	cout<<")"<<endl;
}

void compacta(list<int> &L,list<int> &S) {
	auto it_L=L.begin();
	auto it_S = S.begin();
	
	while(it_L != L.end() && it_S != S.end()){
		int max=*it_S;
		int sum=0;
		
		for(int i=0;i<max;i++) { 
			sum += *it_L;
			it_L=L.erase(it_L);
		}
		L.insert(it_L,sum);
		++it_S;
	}
}

int main(int argc, char *argv[]) {
	
	list<int> L = {1,3,6,2,8,2,3,2,3,10,1,4,5,7,6,4,7,2,3,7};
	list<int> S = {3,3,3,3}; //{10,12,8,15,5,7,6,4,7,2,3,7}
	show_list(L);
	show_list(S);
	compacta(L,S);	
	show_list(L);
	return 0;
}













