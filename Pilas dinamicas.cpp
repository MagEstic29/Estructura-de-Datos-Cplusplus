/*
	Name: Pila inamica
	Copyright: 
	Author: Gutierrez Beltran Jonathan Ivan, Morales Hernandez Edwin Javier, Arriaga Martinez Alan Eduardo
	Date: 01/09/17 17:35
	Description: 
*/

#include<iostream>

using namespace std;

class nodo{
	public:
		int valor;
		nodo *sig;
};

typedef nodo *pnodo;

class pila{
	public:
		int Inserta(int num);
		int Extrae(void);
		int Muestra (void);
		pila(){aux= NULL; inicial=NULL; final=NULL;}
		pnodo aux, inicial, final;
};

void Menu_vacio(){
	cout<<"[Menu de la Pila]"<<endl<<endl;
	cout<<"1) Insertar Elemento"<<endl;
	cout<<"2) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: : ";
}

void Menu_general(){
	cout<<"[Menu de la Pila]"<<endl<<endl;
	cout<<"1) Insertar Elemento"<<endl;
	cout<<"2) Eliminar Elemento"<<endl;
	cout<<"3) Mostrar Pila"<<endl;
	cout<<"4) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: : ";
}

int pila::Inserta(int num){
	aux= new(nodo);
	aux->valor= num;
	aux->sig=NULL;
	if(inicial==NULL){
		inicial=aux;
		final=inicial;
	}
	else{
		aux->sig=inicial;
		inicial=aux;
	}
	cout<<"\n** ELEMENTO AGREGADO **";
}

int pila::Extrae(void){
	if(inicial==NULL){
		cout<<"** LA PILA ESTA VACIA **";
	}
	else{
		aux=inicial;
		inicial=inicial->sig;
		delete(aux);
		cout<<"\n** ELEMENTO ELIMINADO **";
	}
}

int pila::Muestra(void){
	if(inicial==NULL){
		cout<<"** LA PILA ESTA VACIA **";
	}
	else{
		cout<<"ELEMENTO EN LA PILA:"<<endl<<endl;
		cout<<inicial->valor;
	
	}
}

int main(void){
	system("color B");
	int num, i, opc, bandera;
	pila p;
	
	do{
		//Menu de cola vacia
		if(p.inicial==NULL){
			Menu_vacio(); cin>>opc;
			system("cls");
			
			switch(opc){
				case 1:
					cout<<"INTRODUZCA UN VALOR: "; cin>>num;
					p.Inserta(num);
					
					break;
					
				case 2:
					return 0;
					
					break;
			}
		}
		//Menu de general
		else{
			Menu_general(); cin>>opc;
			system("cls");
			
			switch(opc){
				case 1:
					cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
					cout<<"INTRODUZCA UN VALOR: "; cin>>num;
					p.Inserta(num);
					
				break;
				
				case 2:
					cout<<"[ELIMINAR ELEMENTO]"<<endl<<endl;
					p.Extrae();
					
				break;
				
				case 3:
					p.Muestra();
					
				break;
				
				case 4:
					return 0;
				break;
			}
			
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");
		
	}while(1);
	
	return 0;
}
