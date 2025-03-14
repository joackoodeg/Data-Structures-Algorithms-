#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <typename T>
bool cubre_todo(vector<set<T>>&v, set<T>& W){
	
	for(auto set: v){
		for(auto elem: set){
			if(W.count(elem)==0){
				return false;
			}
		}
	}
	
	return true;
}

int main() {
	
	vector<set<int>>V = {{1,2,3}, {2,3,5}, {4,6}};
	
	set<int>W = {1,2,3,4,5,6,7,10,12};
	
	if(cubre_todo(V,W)){
		cout<<"SI "<<endl;
	}else{
		cout<<" NO "<<endl;
	}
	
	return 0;
}







