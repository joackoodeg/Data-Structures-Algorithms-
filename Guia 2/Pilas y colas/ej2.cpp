#include <iostream>
#include <list>
#include <stack>
#include <queue>

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


/// metodos de queue (cola)
/// T front()
/// void pop()
/// void push(T elem)
/// int size()
/// bool empty()



using namespace std;


void show_list(list<char> L) {
	cout<<"[";
	for (auto i:L) {
		cout<<i<<", ";
	}
	cout<<"]"<<endl;
}

void show_stack(stack<char> S){
	cout<<"[";
	while(!S.empty()){	
		cout<<S.top()<<endl;
		cout<<", ";
		S.pop();
	}
	cout<<"]"<<endl;
}

	
bool inverso(list<char> &z)
{		
	stack<char> s;
	queue<char> q;
	
	auto it=z.begin();
	while(it!=z.end()){
		s.push(*it);
		q.push(*it);
		++it;
	}
	
	while(!s.empty() && !q.empty()){
		if(s.top() != q.front()){
			return false;
		}
		s.pop();
		q.pop();
	}
	
	return s.empty() && q.empty();
}
				
int main() {
	list<char> S({'a','b','c','d','c','b','a'});	
	show_list(S);		
	
	if (!inverso(S)) 
	{
		cout << "No ";
	}
	cout << "es z = xy" << endl;
	return 0;
}

				
				
				
				
