#include <iostream>
#include <map>
using namespace std;

template<typename T,typename Q>
void showMap(map<T,Q> &M){
	typename map<T,Q>::iterator it = M.begin();
	while(it!=M.end()){
		cout<<it->first<<"-> "<<it->second; 
		++it;
		cout<<endl;
	}
}
	//ver de hacerlo con find.
bool areinverse(map<int,int> &M1, map<int,int> &M2){
	if(M1.size() != M2.size()){
		return false;
	}
	
	auto it1= M1.begin();
	auto it2= M2.begin();
	
	while(it1!=M1.end()){
		if(M2[it1->second] != it1->first){return false;}
		if(M1[it2->second] != it2->first){return false;}
		++it1; ++it2;
	}
	
	return true;
}

int main() {
	map<int, int> M1 = {{1, 2}, {3, 4}, {5, 6}};
	map<int, int> M2 = {{2, 1}, {4, 3}, {6, 5}};
	
	if(areinverse(M1,M2)){
		cout<<"si son"<<endl;
	}else {
		cout<<"no son"<<endl;
	}
	
	return 0;
}







