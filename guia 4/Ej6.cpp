#include <iostream>
#include <set>
#include <vector>
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
	
	

int includes_all(vector< set<int> > &setv){
	int count=0;
	
	for(auto set : setv){
		if(cubre_todo(setv,set)){
			return count;
		}
		count++;
	}
	
	return -1;
}

int main() {
	set<int> A = {2,3,4};
	set<int> B = {2,3,4};			
	set<int> C = {1,2,4};
	set<int> D = {2,4};
	set<int> E = {};
	set<int> Z = {1,2,3,4};
	
	vector<set<int>> V{A,B,C,C,D,E,Z};
	cout<<includes_all(V);
	
	return 0;
}







