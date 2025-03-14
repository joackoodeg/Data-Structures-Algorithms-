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
using namespace std;

void show_stack(stack<int> S){
	cout<<"[";
	while(!S.empty()){
		cout<<S.top()<<", ";
		S.pop();
	}
	cout<<"]"<<endl;
}
	
void flip(stack<int>&S, int n){

	vector<int>v;
	
	for(int i=0;i<n;i++) {
		v.push_back(S.top());
		S.pop();
	}
	
	for(int i=0;i<n;i++) { 
		S.push(v[i]);
	}
	
	/* ALTERNATIVA CON COLA
	queue<int> Q;
	while(!S.empty()){
		Q.push(S.top());
		S.pop();
	}
	
	while(!Q.empty()){
		S.push(Q.front());
		Q.pop();
	}
	*/
}
	
int findMax(stack<int>&S, int n){
	int maxIndex;
	int maxVal=-99999;
	stack<int>temp;
	
	
	for(int i=0;i<n;i++) { 
		int current= S.top();
		S.pop();
		temp.push(current);
		
		if(current>maxVal){
			maxVal=current;
			maxIndex=i;
		}
	}
	
	
	//Restaurar pila original
	while(!temp.empty()){
		S.push(temp.top());
		temp.pop();
	}
	
	
	return maxIndex;
	
}	
				
void pancake_sort(stack<int>&S){		
	int n= S.size();
	
	for(int i=n;i>1;--i) {
		// Encontrar el índice del máximo elemento en los primeros 'i' elementos
		int maxIndex = findMax(S,i);
		
		// Si el máximo elemento no está en la posición 'i-1', hacer flip
		if(maxIndex != (i-1)){
			// Hacer flip para llevar el máximo elemento al tope
			flip(S, maxIndex + 1);
			// Hacer flip para llevar el máximo elemento a la posición correcta
			flip(S, i);
		}
	}
}
				
int main() {
	stack<int> S({5,32,56,4,-4,-6,-7,9});
	
	show_stack(S);	
	pancake_sort(S);
	cout<<endl;
	show_stack(S);	
	
	return 0;
}
