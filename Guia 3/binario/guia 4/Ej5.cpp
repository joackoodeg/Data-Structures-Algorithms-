#include <iostream>
#include <vector>
#include <set>
using namespace std;

void set_intersection(set<int> &A,set<int> &B,set<int> &C){
	C.clear();
	
	for(auto elem : A){
		if(B.count(elem)>0){
			C.insert(elem);
		}
	}
}
	

template <typename T>
bool cubre_todo(vector<set<T>>&v, set<T>& W){
	
	for(auto x: v){
		set<T>aux;
		set_intersection(x,W,aux);
		
		if(aux!=x){
			return false;
		}
	}
	
	return true;
}

int main() {
	
	vector<set<int>>V = {{1,2,3}, {2,3,5}, {4,6}};
	
	set<int>W = {1,2,3,4,5,6,7};
	
	if(cubre_todo(V,W)){
		cout<<"SI "<<endl;
	}else{
		cout<<" NO "<<endl;
	}
	return 0;
}







