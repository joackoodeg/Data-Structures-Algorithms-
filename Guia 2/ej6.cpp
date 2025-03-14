#include <iostream>
#include <list>
using namespace std;

/*
	ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
	distintas longitudes, escribir una funci´on void reemplaza(list<int> &L, list<int>& SEQ,
	list<int> &REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
	ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
	despu´es de llamar a reemplaza(L,SEQ,REEMP), debe quedar
	L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
	principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando a partir
	del siguiente elemento al ´ultimo de REEMP
*/

void reemplaza(list<int> &L, list<int>& SEQ,list<int> &REEMP){
	auto it = L.begin();
	
	while (it != L.end()) {
		auto seqIt = SEQ.begin();
		bool matchFound = true;
		
		// Buscar la secuencia SEQ en la lista L
		while (seqIt != SEQ.end()) {
			if (it == L.end() || *it != *seqIt) {
				matchFound = false;
				break; // Ver que con el break no se suma ningun iterador
			}
			++it;
			++seqIt;
		}//si el true sobrevive a todas las iteraciones del while quiere decir que se encontro la secuencia
		
		
		if (matchFound) {
			// Reemplazar la secuencia SEQ con REEMP
			it = L.erase(prev(it, SEQ.size()), it); //busco borrar desde it menos toda la secuencia SEQ hasta it
			L.insert(it, REEMP.begin(), REEMP.end());//Inserto todo REEMP (da igual su size)
			advance(it, REEMP.size()); //refresco el iterador REEMP lugares
		} else {
			++it; // el unico movimiento de iterador que "busca" ya que el otro siempre se de el break no se va a ejecutar 
		}
	}
}

int main() {
	list<int>L={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1};
	list<int>SEQ={4,5,1};
	list<int>REEMP={9,7,3,2};
	for(auto i: L){cout<<i<<" ";}cout<<endl;
	
	reemplaza(L,SEQ,REEMP);
	
	for(auto i: L){cout<<i<<" ";}cout<<endl;
	
	return 0;
}







