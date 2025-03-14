#include <iostream>
#include <map>
#include <list>
using namespace std;

template<typename T,typename Q>
void showMap(map<T,Q> &M){
	for (auto par : M) {
		int key = par.first;
		list<int> L = par.second;
		
		cout<<"Clave "<<key<<": ";
		for (int val :L) {
			cout<<val<< " ";
		}
		cout<<endl;
	}
}

void showL(list<int>&L){
	for(auto i: L){cout<<i<<" ";}cout<<endl;
}	

void cutoffmap(map<int, list<int>> &M, int p, int q){
	auto it=M.begin();
	while(it!=M.end()){
		int key=it->first;
		if(key<p || key>=q){
			//borrar
			it=M.erase(it);
		}else{
			++it;
		}
	}
	auto it2=M.begin();
	while(it2!=M.end()){
		list<int>L=it2->second;
		
		auto itL= L.begin();
		while(itL!=L.end()){
			if(*itL<p || *itL>=q){
				itL=L.erase(itL);
			}else{
				++itL;
			}
		}
		
		if(L.empty()){
			it2=M.erase(it2);
		} else{
			++it2;
		}
		
	}
	
}

int main() {
	
	map<int, list<int>>M;
	M[1]={2,3,4};
	M[5]={6,7,8};
	M[8]={4,5};
	M[3]={1,3,7};
	
	cutoffmap(M,1,6);
	
	showMap(M);
	
	return 0;
}







