#include <iostream>
#include <list>
using namespace std;
//maxSubList. Programar una funci´on list<int> max_sublist(list<int> &L) la cual reciba una
//lista de enteros y encuentre y retorne la sublista Lmax que obtenga la mayor suma entre todos sus
//	elementos. Notar que debido a que algunos elementos pueden ser negativos el problema no se
//	resuelve simplemente tomando todos los elementos. Tambi´en es posible que la sublista resultado
//	no contenga ning´un elemento, en el caso de que todos los elementos de L sean negativos. Si hay
//	varias sublistas que den la misma suma, debe retornar la que comience primero y sea m´as corta.
//	Por ejemplo: [1,2,-5,4,-3,2]->[4], [5,-3,-5,1,7,-2]->[1,7], [4,-3,11,-2]->[4,-3,11].	


//Kadane's Algorithm
// La idea principal es mantener un seguimiento de la suma actual y la sublista actual. 
//Si la suma actual se vuelve negativa, se reinicia a cero junto con la sublista actual. 
//En cada paso, se verifica si la suma actual es mayor que la suma máxima registrada hasta ese momento. 
//Si es así, se actualiza la suma máxima y la sublista máxima. 
//Si la suma actual es igual a la suma máxima pero la sublista actual es más corta, 
//también se actualizan los valores máximos.


list<int> max_sublist(list<int> &L) {
	int max_sum = 0;
	int current_sum = 0;
	list<int> max_sub;
	list<int> current_sub;
	
	for (auto it = L.begin(); it != L.end(); ++it) {
		current_sum += *it;
		current_sub.push_back(*it);
		
		//verifica la salvedad de que haya 2 iguales y toma la de menor size
		if (current_sum > max_sum || 
			(current_sum == max_sum && 
			current_sub.size() < max_sub.size()
			)){
			
			max_sum = current_sum;
			max_sub = current_sub;
		}
		
		if (current_sum <= 0) {
			current_sum = 0;
			current_sub.clear();
		}
	}
	
	return max_sub;
}

void showL(list<int>&L){
	for(auto i:L){cout<<i<<" ";}cout<<endl;
}

int main() {
	//list<int> input = {2, -3, 5, -1, 2, -1, 3};
	//list<int> input = {5,-3,-5,1,7,-2};
	
	list<int> L = {5,-3,-5,1,7,-2};
	list<int> result=max_sublist(L);
	showL(result);
	
	return 0;
}





