#include <iostream>
#include <list>
using namespace std;

list<int>concatenateLists(list<int> &L1, const list<int> &L2) {
	L1.insert(L1.end(), L2.begin(), L2.end()); //primera pos, donde arranca a insertar, donde termina
	return L1;
}

list<int> concatenateLists(const list<std::list<int>> &listOfList) {
	std::list<int> result;
	for (const auto &sublist : listOfList) {
		result.insert(result.end(), sublist.begin(), sublist.end());
	}
	return result;
}


list<int>concatenateListsSplice(list<list<int>>listOfList) {
	list<int>result;
	
	for(auto &sublist : listOfList){
		result.splice(result.end(),sublist);
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	list<int> l1 = {1, 2, 3};
	list<int> l2 = {4, 5, 6};
	list<int> l3 = {7, 8, 9};

	list<int>a = concatenateLists(l1,l2);
	
	for(auto it1: a){cout<<it1<<" ";} cout<<endl;
	
	list<list<int>>listOfList = {l1,l2,l3};
	
	list<int>b = concatenateLists(listOfList);
	for(auto it2: b){cout<<it2<<" ";} cout<<endl;
	
	list<int>c = concatenateListsSplice(listOfList);
	for(auto it2: c){cout<<it2<<" ";} cout<<endl;
	
	return 0;
}

