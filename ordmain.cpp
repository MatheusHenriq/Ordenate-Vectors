#include <iostream>
#include "ord.h"

using namespace std;

int main(){

	int vet[5] = {12,34,54,2,3};

	Ordenate a(5);
	
	for(int i=0; i<5; i++){
		a.Setdata(i,vet[i]);
	}
	
	a.ShellSort();

	a.Show();	

	return 0;

}
