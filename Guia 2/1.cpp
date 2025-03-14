#include <iostream>
#include <list>
using namespace std;

//Basicsort
void basic_sort(list<int> &L){
	list<int>L2;
	
	while(!L.empty()){
		
		auto min_it = L.begin();
		auto current = L.begin();
		++current;
		
		while(current!=L.end()){
			if(*current < *min_it){
				min_it=current; //No cambio los valores ya que dsp de recorrer todo
				//es preferible que siga apuntando al menor y no ir sacando y poniendo
			}
			++current;
		}
		
		L2.push_back(*min_it);
		L.erase(min_it); // no actualizo el iterador xq lo vuelve a hacer el while
	}
	
	for(int& n: L2){
		L.push_back(n);
	}
}
int main() {
	
	list<int>L(15,0);
	
	for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
		*it=rand()%100+1;
	}
	
	for(auto i:L){cout<<i<<" ";}cout<<endl;
	
	basic_sort(L);
	
	for(auto i:L){cout<<i<<" ";}cout<<endl;
	
	return 0;
}

