#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
#include <tree.hpp>
using namespace aed;
using namespace std;

int height(btree<int>&A, btree<int>::iterator itA){
	if(itA==A.end()){return 0;}
	
	return (max(height(A,itA.left()), height(A,itA.right()))+1);
}
	
	
bool is_balanced(btree<int>&B, btree<int>::iterator it){
	if(it==B.end()){
		return true;
	}
	
	if(abs(height(B,it.left()) - height(B,it.right())) >1 ){
		return false;
	}
	
	return (is_balanced(B,it.left()) && is_balanced(B,it.right()));
}

bool is_balanced(btree<int>&B){
	return is_balanced(B,B.begin());
}

int main() {
	btree<int>BT;
	
	lisp2btree ("(4 (9 . 8)(5 7 8))", BT);
	
	btree2dot(BT);
	
	if(is_balanced(BT)){
		cout<<" SI "<<endl;
	}else{
		cout<<" NO "<<endl;
	}
	
	return 0;
}







