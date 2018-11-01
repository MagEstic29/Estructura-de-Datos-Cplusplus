#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class nodo{
	public:
	int valor;
	int posicion;
	nodo *hash;
	nodo *colicion;
};

typedef nodo *apu_nodo;


class lista{
	public:
		int Insertar(int a);
		int Buscar_Elemento(int a,int x);
		int Insertar_posicion(int n,int x);
		int Mostrar_lista(void);
		lista(){ inicial=NULL; final=NULL; aux=NULL; aux2=NULL; aux3=NULL;
		} apu_nodo inicial, final, aux, aux2, aux3;
};

lista::Insertar(int a){
	srand(time(NULL));
	int b,res;
	for(int i=0;i<a;i++){
		b=rand()%99+1;
		res=b%a;
		if(inicial==NULL){
			aux=new(nodo);
			aux->valor=b;
			aux->posicion=res;
			aux->colicion=NULL;
			aux->hash=NULL;
			inicial=aux;
			final=inicial;
		}
		else{
			aux=new(nodo);
			aux->valor=b;
			aux->posicion=res;
			aux->colicion=NULL;
			aux->hash=NULL;
			//Inserta Inicio
			if(res<inicial->posicion){
				aux->hash=inicial;
				inicial=aux;
			}
			//Inserta Final
			else if(res>final->posicion){
				final->hash=aux;
				final=aux;
			}
			//Inserta en Medio
			else{
				aux2=inicial; aux3=aux2->hash;
				while(aux2!=final){
					//Si existe la posicion se vuelve colision
					if(aux2->posicion==res){
						while(aux2->colicion!=NULL){
							aux2=aux2->colicion;
						}
						aux2->colicion=aux;
						break;
					}
					else if(aux2->posicion!=res && aux3->posicion>res){
						aux->hash=aux3;
						aux2->hash=aux;
						break;
					}
					else{
						aux2=aux3;
						aux3=aux2->hash;
					}
				}
			}
		}
	}
}

lista::Buscar_Elemento(int a,int x){
	cout<<endl;
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		int res;
		res=a%x;
		aux=inicial;
		while(aux!=NULL){
			if(aux->posicion==res){
				aux2=aux;
				while(aux2!=NULL){
					if(aux2->valor==a){
						cout<<"** VALOR ENCONTRADO EN LA POSICION "<<res<<" **";
						break;
					}
					else{
						aux2=aux2->colicion;
					}
					if(aux2==NULL){
						cout<<"** VALOR NO ENCONTRADO **";
					}
				}
				break;
			}
			else{
				aux=aux->hash;
			}
			if(aux==NULL){
				cout<<"** VALOR NO ENCONTRADO **";
			}
		}
	}
}

lista::Mostrar_lista(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		cout<<"POSICION |\t"<<"COLICIONES"<<endl<<endl;
		aux=inicial;
		while(aux!=NULL){
			cout<<aux->posicion<<"  |\t"<<aux->valor<<"  ";
			if(aux->colicion!=NULL){
				aux2=aux->colicion;
				while(aux2!=NULL){
					cout<<aux2->valor<<"  ";
					aux2=aux2->colicion;
				}
			}
			cout<<endl;
			aux=aux->hash;
		}
	}
}

int Menu(){
	cout<<"\n\t** MENU DE TABLA HASH **"<<endl<<endl;
	cout<<"1) BUSCAR UN ELEMENTO"<<endl;
	cout<<"2) MOSTRAR TABLA"<<endl;
	cout<<"3) SALIR"<<endl<<endl;
	cout<<"ELIGE UNA OPCION: ";
}

int main(){
	system("color B");
	system("cls");
	int num,opc,busq;
	lista p;
	
	cout<<"INTRODUCE CUANTOS ELEMENTOS CREAR: "; cin>>num;
	p.Insertar(num);
	cout<<endl<<endl;
	system("pause");
	system("cls");
	
	do{
		Menu(); cin>>opc;
		system("cls");
		
		switch(opc){
			case 1:
				cout<<"INTRODUCE EL NUMERO A BUSCAR: "; cin>>busq;
				p.Buscar_Elemento(busq,num);
				
				break;
			
			case 2:
				p.Mostrar_lista();
				
				break;
				
			case 3:
				cout<<"Saliendo...";
				
				break;
				
			default:
				cout<<"** OPCION INCORRECTA **";
				break;
		}
		
		
		cout<<endl<<endl;
		cout<<"-------------------------------------------"<<endl;
		system("pause"); system("cls");
	}while(opc!=3);
	
	
	
	return 0;
}
