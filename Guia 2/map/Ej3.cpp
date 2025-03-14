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
	
bool areinverse(map<int,int> &M1, map<int,int> &M2){
	if (M1.size() != M2.size()) { //si tienen distinto size=false
		return false;
	}
	
	for (auto& pair : M1) { 
		auto it = M2.find(pair.second); //it=encontrar valor de M1 en clave de M2
		if (it == M2.end() || it->second != pair.first) { 
			//si no la encuentra o  (la otra comparacion)
			//es decir, si valor de M2 es distinto de clave de M1
			return false;
		}
	}
	
	return true;
}

int main() {
	map<int, int> M1 = {{1, 2}, {3, 4}, {5, 6}};
	map<int, int> M2 = {{2, 1}, {4, 3}, {6, 5}};
	
	if (areinverse(M1, M2)) {
		cout << "M1 y M2 son inversos." <<endl;
	} else {
		cout << "M1 y M2 no son inversos." <<endl;
	}
	
	return 0;
}







