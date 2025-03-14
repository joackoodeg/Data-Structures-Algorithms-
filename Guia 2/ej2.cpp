#include <iostream>
#include <list>
using namespace std;

void selection_sort(list<int> &L){
	list<int>::iterator current = L.begin();
	
	while(current != L.end()){
		list<int>::iterator min = current;
		list<int>::iterator next = current;
		++next;
		
		//busca al mas chico
		while(next != L.end()){
			if(*next < *min){
				min=next;
			}
			++next;
		}
		
		//los cambia
		if(min != current) {
			swap(*current, *min);
		}
		++current;
	}
}

int main(int argc, char *argv[]) {
	list<int> l(15,0);
	for( list<int>::iterator it=l.begin(); it!=l.end(); ++it ) { 
		*it = rand()%100+1;
	}
	
	for(auto it: l){cout<<it<<" ";} cout<<endl;
	
	selection_sort(l);
	
	for(auto it: l){cout<<it<<" ";} cout<<endl;
	
	return 0;
}

