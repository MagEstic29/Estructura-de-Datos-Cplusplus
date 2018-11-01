#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class nodo{
	public:
		int valor,ID,Padre;
		nodo *sig;
};

typedef nodo *apu_nodo;

class arbol_ene{
	public:
		int Insertar(int a, int b, int c);
		int Mostrar(int a);
		arbol_ene(){
			raiz=NULL; aux=NULL; aux2=NULL; final=NULL;
		}apu_nodo raiz,aux,aux2,final;
};

void Menu(void){
	cout<<"\n\t** MENU DE ARBOL ENEARIO **"<<endl<<endl;
	cout<<"1) INSERTAR ELEMENTO"<<endl;
	cout<<"2) INSERTAR ALEATORIOS"<<endl;
	cout<<"3) MOSTRAR ARBOL"<<endl;
	cout<<"4) SALIR"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

arbol_ene::Insertar(int a, int b, int c){
	aux=new(nodo);
	aux->ID=a;
	aux->Padre=b;
	aux->valor=c;
	aux->sig=NULL;
	if(raiz==NULL){
		aux->Padre=0;
		raiz=aux;
		final=raiz;
	}
	else{
		int ban=0;
		aux2=raiz;
		while(aux2!=NULL){
			if(aux2->ID==b){
				ban=1;
			}
			aux2=aux2->sig;
		}
		if(ban==1){
			final->sig=aux;
			final=aux;
		}
		else{
			cout<<"** PADRE NO ENCONTRADO **";
		}
	}
}

arbol_ene::Mostrar(int a){
	if(raiz==NULL){
		cout<<"** ARBOL VACIO **";
	}
	else{
		aux=raiz;
		cout<<"ID\t| ID_PADRE\t| VALOR"<<endl<<endl;
		while(aux!=NULL){
			cout<<aux->ID<<"\t| "<<aux->Padre<<"\t| "<<aux->valor<<endl;
			aux=aux->sig;
		}
	}
}

int main(){
	int pad,opc,num, global=1,i;
	arbol_ene arb;
	
	do{
		
		Menu(); cin>>opc;
		system("cls");
		
		switch(opc){
			case 1:
				cout<<"[INSERTAR ELEMENTO]\t ID Actual: "<<global<<endl<<endl;
				cout<<"INTRODUCE EL VALOR: "; cin>>num;
				cout<<"INTRODUCE EL ID DEL PADRE: "; cin>>pad;
				cout<<endl;
				arb.Insertar(global,pad,num);
				global++;
				
				break;
				
			case 2:
				
				break;
				
			case 3:
				cout<<"[MOSTRAR ARBOL]"<<endl<<endl;
				arb.Mostrar(global);
				
				break;
				
			case 4:
				cout<<"** GG IZI MID **";
				
				break;
				
			default:
				cout<<"** OPCION INCORRECTA **";
				break;
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");
	}while(opc!=4);
	
	return 0;
}
