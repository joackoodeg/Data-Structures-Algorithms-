#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
#include <btree.hpp>
using namespace aed;
using namespace std;

///aux
bool semejantes(btree<int>& A, btree<int>& B,btree<int>::iterator itA,btree<int>::iterator itB) {
	if(itA==A.end() && itB!=B.end()){
		return false;
	}
	if(itB==B.end()&& itA!=A.end()){
		return false;
	}
	
	if(itA==A.end() && itB==B.end()){
		return true;
	}
	
	if(!semejantes(A,B,itA.left(),itB.left())){return false;}
	if(!semejantes(A,B,itA.right(),itB.right())){return false;}
	
	return true;
}

/// Wrapper
bool semejantes(btree<int>& A, btree<int>& B) {
	return semejantes(A,B,A.begin(),B.begin());
}
///aux
bool espejados(btree<int>& A, btree<int>& B,btree<int>::iterator itA,btree<int>::iterator itB) {
	if(itA==A.end() && itB!=B.end()){
		return false;
	}
	if(itB==B.end()&& itA!=A.end()){
		return false;
	}
	
	if(itA==A.end() && itB==B.end()){
		return true;
	}
	
	if(!espejados(A,B,itA.left(),itB.right())){return false;}
	if(!espejados(A,B,itA.right(),itB.left())){return false;}
	
	return true;
}

/// Wrapper
bool espejados(btree<int>& A, btree<int>& B) {
	return espejados(A,B,A.begin(),B.begin());
}
///aux
bool iguales(btree<int>& A, btree<int>& B,btree<int>::iterator itA,btree<int>::iterator itB) {
	if(itA==A.end() && itB!=B.end()){
		return false;
	}
	if(itB==B.end()&& itA!=A.end()){
		return false;
	}
	
	if(*itA!=*itB){
		return false;
	}
	
	if(itA==A.end() && itB==B.end()){
		return true;
	}
	
	if(!semejantes(A,B,itA.left(),itB.left())){return false;}
	if(!semejantes(A,B,itA.right(),itB.right())){return false;}
	
	return true;
}

/// Wrapper
bool iguales(btree<int>& A, btree<int>& B) {
	return iguales(A,B,A.begin(),B.begin());
}

///aux
void copia_espejada(btree<int>& A, btree<int>& B,btree<int>::iterator itA,btree<int>::iterator itB) {
	if(itA==A.end()){
		return ;
	}
	
	itB=B.insert(itB,*itA);
	
	copia_espejada(A,B,itA.left(),itB.right());
	copia_espejada(A,B,itA.right(),itB.left());
}
/// Wrapper
void copia_espejada(btree<int>& A,btree<int>& B) {
	copia_espejada(A,B,A.begin(),B.begin());
}

int main(int argc, char *argv[]) {
	btree<int> T1,T2, T3, T4;
	lisp2btree("(1 (2 4 .) (6 (7 . 5) .))", T1);
	lisp2btree("(10 (12 34 .) (26 (47 . 55) .))", T2);
	lisp2btree("(12 (26 . (73 54 .)) (2 . 34))", T3);
	
	if(semejantes(T1,T2)){
		cout<<"Son semejantes"<<endl;
	}else{cout<<"no son semejantes"<<endl;}
	
	
	if(!espejados(T1,T3))cout<<"No";
	cout<< " son espejados"<<endl;
	
	if(iguales(T2,T2)){
		cout<<"Son iguales"<<endl;
	}else{cout<<"No son iguales"<<endl;}
	
	btree2dot(T1,"original");
	copia_espejada(T1,T4);
	btree2dot(T4,"original");
	
	
	
	
	return 0;
}
