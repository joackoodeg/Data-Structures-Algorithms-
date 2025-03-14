#include <iostream>
#include <stack>

/// metodos de list (lista)
///	iterator_t insert(iterator_t p,elem_t x);
///	iterator_t erase(iterator_t p);
///	elem_t & retrieve(iterator_t p);
///	iterator_t next(iterator_t p);
///	iterator_t begin();
///	iterator_t end();

/// metodos de stack (pila)
/// T &top()
/// void pop()
/// void push(T elem)
/// int size()
/// bool empty()


#include <vector>
#include <list>
using namespace std;

void show_stack(stack<int> S){
	cout<<"(";
	while (!S.empty())
	{
		cout << S.top()<< " ,";
		S.pop();
	}
	cout<<")"<<endl;
}
	
void proc_a(stack<int> &S, int i)
{
	for(int i=0;i<2;i++) { 
		S.pop();
	}
	S.push(i);
}

void proc_b(stack<int> &S, int i)
{
	int n1;
	n1=S.top();
	S.pop();
	
	int n2;
	n2=S.top();
	S.pop();
	
	S.push(i);
	S.push(n2);
	S.push(n1);
}

void proc_c(stack<int> &S, int i, int n)
{
	for(int i=0;i<n;i++) { 
		S.pop();
	}
	S.push(i);
}

void proc_d(stack<int> &S, int i)
{
	while(!S.empty()){
		S.pop();
	}
	S.push(i);
}

void proc_e(stack<int> &S, int i)
{
	stack<int>L;
	
	while(!S.empty()){
		L.push(S.top());
		S.pop();
	}
	
	S.push(i);
	
	while(!L.empty()){
		S.push(L.top());
		L.pop();
	}
	
}
		
						
int main() {
	stack<int> S({5,4,3,2,1});	
	
	cout<<endl<<"Pila: "<<endl;
	show_stack(S);
	
	proc_e(S,100);
	show_stack(S);
	
	return 0;
}
						
