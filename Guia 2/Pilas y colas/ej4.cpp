#include <iostream>
#include <list>
#include <stack>

/// metodos de list (lista)
///	iterator_t insert(iterator_t p,elem_t x);
///	iterator_t erase(iterator_t p);
///	elem_t & retrieve(iterator_t p);
///	iterator_t next(iterator_t p);
///	iterator_t begin();
///	iterator_t end();


/// metodos de stack (pila)
/// T top()
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

void sort_stack(list<int> &L) {
	stack<int> P;
	while(!L.empty()){
		auto it=L.begin();
		auto min_it=L.begin();
		
		while(it!=L.end()){

			if(*it<*min_it){
				min_it = it;
			}
			++it;
		}
		P.push(*min_it);
		L.erase(min_it);
	}
	
	while(!P.empty()){
		L.push_back(P.top());
		P.pop();
	}
}

				
int main() {
	list<int> L = {4, 7, 9, 8, 3, 7, 2, 3, 1, 5, 12, 1};
	
	sort_stack(L);
	
	show_list(L);
	return 0;
}

				
				
				
				
