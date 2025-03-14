#include <iostream>
#include <set>
#include <vector>
using namespace std;

void set_intersection(set<int> &A,set<int> &B,set<int> &C){
	C.clear();
	
	for(const auto &elem : A){
		if(B.count(elem)>0){
			C.insert(elem);
		}
	}
}

bool disjuntos(vector<set<int>>&v) {
	
	for(size_t i=0;i<v.size();i++) { 
		for(size_t j=0;j<v.size();j++) { 
			if(i!=j){
				set<int>x;
				set_intersection(v[i],v[j],x);
				if(!x.empty()){
					return false;
				}
			}
		}
	}
	
	return true;
}

int main() {
	set<int> A = {1,2,3};
	set<int> B = {4,5};
	set<int> C = {6,7};
	
	vector<set<int>>V= {A,B,C};
	
	if(disjuntos(V)){
		cout<<"Si"<<endl;
	}else{
		cout<<" No "<<endl;
	}
	
	return 0;
}







