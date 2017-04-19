#include <iostream>
using namespace std;

int fact(int n);

int main(){
	int n = 3;
	int f = fact(n);
	cout << "answer: " << f << endl;
}

int fact(int n){
	cout << "computing factorial for " << n << endl;
	if(n == 0) return 1;
	else return(n * fact(n-1));
}
