#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

void merge_map(map<int, list<int>> &A, map<int, list<int>> &B,map<int, list<int>> &C){
	//recorrer todas las claves de A y B para combinar las listas
	for(auto &par : A){
		
		int key=par.first;
		list<int>listA = par.second;
		
		//Buscar la misma clave en B
		auto itB = B.find(key);
		
		//si la clave tambien esta en b, combina las listas ordenadas
		if(itB!= B.end()){
			list<int>listB= itB->second;
			list<int>mergedList;
			
			//Utiliza la funcion merge para combinar y ordenar las listas
			merge(listA.begin(),listA.end(),listB.begin(),listB.end(), back_inserter(mergedList)); 
			//utiliza back_inserter para insertar el resutlado al final de la lista.
			
			//Almacenar en C
			C[key]= mergedList;
		}else {
			
			C[key]=listA;
			
		}
	}
	
	//Ahora las claves en B que no estaba en A
	
	for(auto par: B){
		int key=par.first;
		list<int>listB=par.second;
		
		//si esa clave no esta en A. copia la lista B en C
		
		if(A.find(key) == A.end()){
				C[key] = listB;
			}
	}
}

int main() {
	
	map<int,list<int>> A, B, C;
	
	A[1] = {2, 4, 6};
	A[2] = {1, 3, 5};
	B[2] = {0, 3};
	B[3] = {7, 8, 9};
	
	merge_map(A, B, C);
	
	for (auto par : C) {
		int key = par.first;
		list<int> mergedList = par.second;
		
		cout<<"Clave "<<key<<": ";
		for (int val : mergedList) {
			cout<<val<< " ";
		}
		cout<<endl;
	}
	
	return 0;
}







