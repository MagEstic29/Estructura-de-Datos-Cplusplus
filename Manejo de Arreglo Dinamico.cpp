#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	int *arreglou,**arreglob;
	int n,i,m,j;
	m=5;
	n=10;
	//Arreglo Unidimencional
	arreglou= (int*) calloc(n, sizeof(int));
	cout<<"*Arreglo Unidimencional*"<<endl<<endl;
	
	for(i=0;i<n;i++){
		cout<<"Arreglo{"<<i<<"]= "<<arreglou[i]<<endl;
	}
	cout<<endl<<endl<<"*Arreglo Bidimencional*"<<endl<<endl;
	
	//Arreglo Bidimencional
	arreglob= (int**) malloc(n* sizeof(int*));
	for(i=0;i<n;i++){
		arreglob[i]= (int*) calloc(m, sizeof(int));
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout<<arreglob[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	
	return 0;
}
