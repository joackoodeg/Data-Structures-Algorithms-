#include <iostream>
#include <map>
#include <list>
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

void map2list(map<int,int> &M, list<int> &Keys, list<int> &Vals){
	auto it=M.begin();
	while(it!=M.end()){
		Keys.push_back(it->first);
		Vals.push_back(it->second);
		++it;
	}
}
	
void showList(list<int>&L){
	auto it=L.begin();
	while(it!=L.end()){
		cout<<*it<<" ";
		++it;
	}cout<<endl;
}	

int main() {
	
	map<int,int> M= {
		{1,2},
		{2,3},
		{4,5}
	};
	
	list<int>Keys;
	list<int>Vals;
	
	showMap(M);
	
	map2list(M,Keys,Vals);
	
	showList(Keys);
	showList(Vals);
	
	return 0;
}







