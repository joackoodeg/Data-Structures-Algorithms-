#include <iostream>
#include <list>
#include <map>
using namespace std;

void showL(list<int>&L){
	for(auto i: L){cout<<i<<" ";}cout<<endl;
}

void apply_map(list<int> &L, map<int,int> &M,list<int> &ML){
	auto it=L.begin();

	while(it!=L.end()){
		int key=*it;
		auto itK=M.find(key);
		if(itK!=M.end()){
			ML.push_back(itK->second);
		}
		
		++it;
	}
} 

int main() {
	
	list<int>L = {1,2,3,4,5,6,7,1,2,3};
	
	map<int,int>M = {{1,2},{2,3},{3,4},{4,5},{7,8}};
	
	list<int>ML;
	apply_map(L,M,ML);
	showL(ML);
	
	return 0;
}







