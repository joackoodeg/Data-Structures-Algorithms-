#include <iostream>
#include <set>
#include <list>
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

bool conexion_directa(vector<set<int>> sw, int a, int b){
	set<int>par={a,b};
	
	for(int i=0;i<sw.size();i++) { 
		set<int>aux;
		set_intersection(par,sw[i],aux);
		if(aux.size()==2){
			return true;
		}
	}
	return false;
}

bool flat(vector< set<int> > &sw, int n) {
	for(int i=0;i<n;i++) { 
		for(int j=0;j<n;j++) { 
			if(i!=j){
				if(!conexion_directa(sw,i,j)){
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	
	set<int> sw0 = {0,1,2,3,4};
	set<int> sw1 = {0,1,5,6,7};
	set<int> sw2 = {2,3,4,5,6,7};
	
	
	set<int> sw0_b = {0,2,3,4};
	set<int> sw1_b = {0,1,5,7};
	set<int> sw2_b = {2,3,5,6,7};
	
	vector<set<int>> sw = {sw0,sw1,sw2};
	vector<set<int>> sw_b = {sw0_b,sw1_b,sw2_b};
	
	if(flat(sw,8)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	if(flat(sw_b,8)){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
	
	return 0;
}







