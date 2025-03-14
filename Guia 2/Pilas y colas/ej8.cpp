#include <iostream>
#include <queue>

/// metodos de queue (cola)
/// T front()
/// void pop()
/// void push(T elem)
/// int size()
/// bool empty()



using namespace std;


void show_queue(queue<int> Q) {
	cout<<"[";
	while (!Q.empty()) {
		cout<<Q.front()<<", ";
		Q.pop();
	}
	cout<<"]"<<endl;
}

void sort_queue(queue<int> &Q) {
	int n=Q.size();
	queue<int>temp;
	
	for(int i=0;i<n;i++) { 
		int current=Q.front();
		if(current%2==0){
			break;
		}else{
			temp.push(Q.front());
			Q.pop();
		}
	}

	while(!temp.empty()){
		Q.push(temp.front());
		temp.pop();
	}
}

/*
// Función para realizar la rotación en la cola para que quede un número par en el frente
void rotacion(queue<int>& C) {
queue<int> temp;

// Paso 1: Mover los elementos no pares al final de la cola
while (C.front() % 2 != 0) {
int front = C.front();
C.pop();
temp.push(front);

if (C.empty()) {
break; // Evitar bucle infinito si no hay números pares en la cola
}
}

// Paso 2: Mover los elementos a la cola principal en el orden correcto
while (!temp.empty()) {
int front = temp.front();
temp.pop();
C.push(front);
}
}
*/

				
int main() {
	//queue<int> Q ({4, 7, 9, 8, 3, 7, 2, 3, 1, 5, 12, 1});	
	queue<int> Q ({1, 3, 5, 2, 4});
	sort_queue(Q);
	show_queue(Q);	
	return 0;
}

				
				
				
				
