#include <iostream>
#include <set>
using namespace std;

void showSet(set<int>&A){
	for(auto i: A){
		cout<<i<<" ";
	}cout<<endl;
}
	
void set_union(set<int> &A,set<int> &B,set<int> &C){
	C=A;
	C.insert(B.begin(),B.end());
}

void set_intersection(set<int> &A,set<int> &B,set<int> &C){
	C.clear();
	
	for(auto elem : A){
		if(B.count(elem)>0){
			C.insert(elem);
		}
	}
}

void set_difference(set<int> &A,set<int> &B,set<int> &C){
	//Elementos que estan en A y NO en B
	C.clear();
	
	for(auto elem: A){
		if(B.count(elem)==0) //No esta en B
		{
			C.insert(elem);
		}
	}
}
	
int main() {
	
	set<int> A = {1,2,4,5,7};
	set<int> B = {6,7,8,9,2};
	set<int> C;
	
	set_union(A,B,C);
	showSet(C);
	
	set_intersection(A,B,C);
	showSet(C);
	
	set_difference(A,B,C);
	showSet(C);
	
	return 0;
}







