#include <iostream>
#include <list>
using namespace std;

void basic_sort(list<int> &L){
	list<int>L2;
	
	while(!L.empty()){
		auto min_it=L.begin();
		
		for( list<int>::iterator it=L.begin(); it!=L.end(); ++it ) { 
			if(*it<*min_it){
				min_it=it;
			}
		}
		
		L2.push_back(*min_it);
		L.erase(min_it);
	}
	
	for( list<int>::iterator it=L2.begin(); it!=L2.end(); ++it ) { 
		L.push_back(*it);
	}
}

int main() {
	
	list<int>L = {2,5,7,2,5,4,10,22};
	for(auto i:L){cout<<i<<" ";}cout<<endl;
	
	basic_sort(L);
	
	for(auto i:L){cout<<i<<" ";}cout<<endl;
	
	return 0;
}







