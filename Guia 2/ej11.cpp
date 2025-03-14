#include <iostream>
#include <iostream>#include <list>

#include <cstring>
using namespace std;bool is_palindromo(char* S) {	list<char> L;
	//borrar espacio y meter caracteres en lista
	for(size_t i=0;i<strlen(S);i++) { 
		if(S[i]!=' '){
			L.push_back(S[i]);
		}
	}
	
	//se fija comprarando por extremo y los va borrando asi no hay que actualizar ni iterador ni nada
	//simplemente al hacer popfront y popback estos se actualizan y vuelven a comprar asi hasta el final
	//si sobrevive todo el for significa que es palindromo
	
	while(!L.empty()){ 
		if(L.front() != L.back()){
			return false;
		}
		L.pop_back();
		L.pop_front();
	}
	return true;}
int main() {	char input[] = "yo hago yoga hoy";//"asd";	if (is_palindromo(input)) {		cout << "Es un palíndromo." << std::endl;	} else {		cout << "No es un palíndromo." << std::endl;	}		return 0;}




