#include <iostream>
#include <set>
#include <list>
using namespace std;

void showSet(set<int>&A){
	for(auto i: A){
		cout<<i<<" ";
	}cout<<endl;
}

void diffsym(list< set<int> > &L, set<int> &ad){
	ad.clear();
	
	set<int>allElements;
	
	for(const set<int>&s: L){
		for(int elem: s){
			if(allElements.count(elem)>0){
				ad.erase(elem);
			}else{
				ad.insert(elem);
			}
			allElements.insert(elem); ///CHEQUEA LOS ELEMENTOS
		}
	}
}

int main() {
	
	set<int> A = {1,2,4,5,7};
	set<int> B = {6,7,8,9,2};
	set<int> C = {8,10,4,7,44};
	
	list<set<int>> L = {A,B,C};
	
	set<int>ad;
	
	diffsym(L,ad);
	showSet(ad);
	
	return 0;
}







