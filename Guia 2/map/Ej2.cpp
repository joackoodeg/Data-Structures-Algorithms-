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
	
	void list2map(map<int,int> &M,
				  list<int> &Keys, list<int> &Vals){
		auto it=Keys.begin();		auto it2=Vals.begin();		while(it!=Keys.end()){			if(it2!=Vals.end()){ 				M[*it]=*it2;//queda la ultima asignacion xq asi lo hace por defecto el container				it++;				it2++;			}			else{				M[*it]=0; 				it++;			}		}
}
		
void showList(list<int>&L){
	auto it=L.begin();
	while(it!=L.end()){
		cout<<*it<<" ";
		++it;
	}cout<<endl;
}	
			

int main() {

	list<int>Keys={1,2,3};
	list<int>Vals={4,5,6;}

				
	list2map(Keys,Vals);
				

	return 0;
}
