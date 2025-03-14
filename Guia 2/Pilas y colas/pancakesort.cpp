#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int findMax(stack<int>S, int n){
	stack<int>T;
	
	int maxVal=-9999;
	int maxIndex;
	
	for(int i=0;i<n;i++) { 
		T.push(S.top());
		
		if(S.top()>maxVal){
			maxVal=S.top();
			maxIndex=i;
		}
		
		S.pop();
	}
	
	return maxIndex;
}
	
void flipStack(stack<int>&S,int n){
	queue<int>Q;
	
	for(int i=0;i<n;i++) { 
		Q.push(S.top());
		S.pop();
	}
	
	while(!Q.empty()){
		S.push(Q.front());
		Q.pop();
	}
	
}	

void sortStack(stack<int>&S){
	for(int i=S.size(); i>1; --i){
		int maxIndex=findMax(S,i);
		
		flipStack(S,maxIndex+1);
		
		flipStack(S,i);
	}
	
}



void showStack(stack<int>S){
	while(!S.empty()){
		cout<<S.top()<<" ";
		S.pop();
	}cout<<endl;
}

int main() {
	stack<int>S ({1,20,22,5,3,2,7,9,8,13,10,30,1});
	showStack(S);
	
	sortStack(S);
	showStack(S);
	
	return 0;
}







