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

void string_to_list(std::string str , list<char> &chars)
{	
	for (char c: str) {
		chars.push_back(c);
	}
}
	

bool chequeo(list<char> &z) //arreglar
{		
	// no anda esta la de abajo si
	stack<char> s;
	queue<char> q;
	
	auto it=z.begin();
	while(it!=z.end()){
		s.push(*it);
		q.push(*it);
		++it;
	}
	
	
	int c=0;
	while(!s.empty() && !q.empty()){
		if(s.top()=='('){
			if(q.front()==')'){
				c++;
			}else{
				q.pop();
			}
		}else{
			s.pop();
		}
	}
	if(c%2==0){
		return true;
	}else{
		return false;
	}
}

/*
// Función para verificar si los paréntesis están embebidos correctamente en una expresión
bool verificarParentesis(const string& expresion) {
stack<char> pila;

for (char caracter : expresion) {
if (caracter == '(') {
pila.push(caracter);
} else if (caracter == ')') {
if (pila.empty()) {
return false; // Hay un paréntesis derecho sin un correspondiente izquierdo
}
pila.pop();
}
}

return pila.empty(); // Si la pila está vacía al final, los paréntesis están embebidos correctamente
}
*/
				
int main() {
	std::string str = "((a - b)*(5 - c))/4";
	list<char> S;
	string_to_list(str,S);
	show_list(S);		
	
	if (!chequeo(S)) 
	{
		cout << "No ";
	}
	cout << "es balanceada" << endl;
	return 0;
}

				
				
				
				
