/*
	Name: Hash Residuo
	Copyright: 
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 12/04/17 04:14
	Description: 
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#define TAM 30

using namespace std;

class nodo{
	public:
		int valor;
		nodo *sig;
};

typedef nodo *apu_nodo;

int main(){
	system("color B");
	int a,b,i;
	srand(time(NULL));
	apu_nodo *arg;
	apu_nodo aux=NULL,aux2=NULL;
	arg=(apu_nodo*) calloc(TAM-1,sizeof(apu_nodo));
	//CREAR ARREGLO CON NODOS
	for(i=0;i<TAM;i++){
		arg[i]=new(nodo);
		arg[i]->valor=0;
		arg[i]->sig=NULL;
	}
	
	for(i=0;i<TAM;i++){
		a=rand()%500+1;
		//cout<<"Numero creado: "<<a;
		b=a%TAM;
		//cout<<" posicion "<<b+1<<endl;
		if(arg[b]->valor!=0){
			cout<<"Coliciona el numero "<<a<<" en la posicion "<<b+1<<endl;
				aux=arg[b]; int bandera=0;
				aux2=new(nodo);
				aux2->valor=a;
				aux2->sig=NULL;
				while(bandera!=1){
					if(aux->valor==a){
						bandera=1;
					}
					else if(aux->valor!=a && aux->sig==NULL){
						aux->sig=aux2;
						bandera=1;
					}
					else{
						aux=aux->sig;
					}
				}
			
		}
		else{
			arg[b]->valor=a;
			arg[b]->sig=NULL;
		}
	}
	
	cout<<endl<<endl;
	//Mostrar el arreglo con la lista
	for(i=0;i<TAM;i++){
		cout<<arg[i]->valor<<" ";
		if(arg[i]->sig!=NULL){
			aux=arg[i]->sig;
			while(aux!=NULL){
				cout<<"-> "<<aux->valor<<" ";
				aux=aux->sig;
			}
			cout<<endl;
		}
		else{
			cout<<endl;
		}
	}
	
	
	return 0;
}
