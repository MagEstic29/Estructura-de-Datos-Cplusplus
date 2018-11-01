#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

class nodo{
	public:
		int factor;
		int exp;
		nodo *sig;
};

typedef nodo *apu_nodo;

class lista{
	public:
		int Agregar_Factor(int a);
		int Mostrar_Factores(long long res);
		lista(){
			inicial=NULL; final=NULL; aux=NULL;
		}apu_nodo inicial,final,aux;
};

lista::Agregar_Factor(int a){
	if(inicial==NULL){
		aux=new(nodo);
		aux->factor=a;
		aux->exp=1;
		aux->sig=NULL;
		inicial=aux;
		final=aux;
	}
	else{
		aux=inicial; int bandera=0; 
		while(aux!=NULL){
			if(aux->factor==a){
				aux->exp++;
				bandera=1;
				break;
			}
			else{
				aux=aux->sig;
			}
		}
		if(bandera==0){
			aux=new(nodo);
			aux->factor=a;
			aux->exp=1;
			aux->sig=NULL;
			final->sig=aux;
			final=final->sig;
		}
	}
}

lista::Mostrar_Factores(long long res){
	aux=inicial;
	cout<<"LOS FACTORES DE "<<res<<" SON:"<<endl<<endl;
	while(aux!=NULL){
		cout<<aux->factor<<"^"<<aux->exp<<"  ";
		aux=aux->sig;
	}
}

int main(){
	system("color B");
	long long num, res;
	int i,j,x=0;
	lista p;
	
	cout<<"[FACTORIZACION POR EXPONENTE]"<<endl<<endl;
	cout<<"INGRESE EL NUMERO A FACTORIZAR: "; cin>>num;
	system("cls");
	res=num;
		
	//Comprobacion de Numero Primo
	for(i=1;i<=num;i++){
		if(num%i==0){
			x++;
		}
	}
	//Es Primo
	if(x==2){
		cout<<"** EL NUMERO "<<num<<" ES PRIMO **"<<endl<<endl;
	}
	//Si no es primo
	else{
		i=2;
		while(num!=1){
			if(num%i==0){
				p.Agregar_Factor(i);
				num=num/i;
				i=2;
			}
			else{
				i++;
			}
		}
		p.Mostrar_Factores(res);
	}
	
	
	return 0;
}
