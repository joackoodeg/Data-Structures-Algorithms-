#include <iostream>
#include <set>
#include <list>
#include <vector>

using namespace std;

void showL(list<set<int>>L){
	for(auto set:L){
		for(auto elem: set){
			cout<<elem<< " ";
		}
		cout<<endl;
	}
}

void show_set(set<int> A) {
	cout<<"{ ";
	for(auto i:A) {
		cout<<i<<" ";
	}
	cout<<"}"<<endl;
}

void subK(set<int>&S,set<int>::iterator itS, int k, list<set<int>>&L ,set<int> s){	
	if(s.size() == k){ 
		///agregamos a la ista y salimos
		L.push_back(s);
		return;
	}
	
	if(itS== S.end()){
		return;
	}
	
	///recursion
	set<int>s_sin = s;
	set<int>s_con = s;
	
	s_con.insert(*itS);

	subK(S,next(itS),k,L,s_sin);
	subK(S,next(itS),k,L,s_con);
	
	show_set(s_sin);
	show_set(s_con);
}


list<set<int>> subK(set<int> &S, int k) 
{
	list<set<int>>L;
	
	set<int>s;
	
	subK(S,S.begin(),k,L,s);
	
	return L;
}


int main()
{
	set<int> A = {1,2,3,4};
	int k = 2;
	
	/// {{1,2}, {1,3}, {1,4},{2,3},{2,4},{3,4}}
	
	list<set<int>> lSets = subK(A,k);
	
	cout<<endl;
	
	list<set<int>>::iterator itA = lSets.begin();
	while (itA != lSets.end())
	{
		show_set(*itA);
		cout << endl;
		itA++;
	}

	
	return 0;
}
