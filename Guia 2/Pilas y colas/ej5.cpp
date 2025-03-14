#include <iostream>
#include <list>
#include <queue>

/// metodos de list (lista)
///	iterator_t insert(iterator_t p,elem_t x);
///	iterator_t erase(iterator_t p);
///	elem_t & retrieve(iterator_t p);
///	iterator_t next(iterator_t p);
///	iterator_t begin();
///	iterator_t end();


/// metodos de queue (cola)
/// T front()
/// void pop()
/// void push(T elem)
/// int size()
/// bool empty()



using namespace std;


void show_list(list<int> L) {
	cout<<"[";
	for (auto i:L) {
		cout<<i<<", ";
	}
	cout<<"]"<<endl;
}

void sort_queue(list<int> &L) {
	queue<int> C;
	
	while(!L.empty()){
		auto it=L.begin();
		auto min_it=L.begin();
		
		while(it!=L.end()){
			
			if(*it<*min_it){
				min_it = it;
			}
			++it;
		}
		C.push(*min_it);
		L.erase(min_it);
	}
	
	while(!C.empty()){
		L.push_back(C.front());
		C.pop();
	}
}

				
int main() {
	list<int> L = {4, 7, 9, 8, 3, 7, 2, 3, 1, 5, 12, 1};
	
	sort_queue(L);
	
	show_list(L);
	return 0;
}

				
				
				
				
