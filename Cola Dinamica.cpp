/*
	Name: Cola Dinamica
	Copyright: 
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 20/02/17
	Description: Inserta, Elimina, Muestra, Vacia
*/


#include<iostream>

using namespace std;

class nodo{
	public:
		int valor;
		nodo *sig;
		nodo *ant;
};

typedef nodo *apu_nodo;

class cola{
	public:
		void Insertar(int a);
		void Eliminar(void);
		void Mostrar(void);
		//void Vaciar(void);
		cola(){
			actual= NULL; aux= NULL; aux2=NULL;
		}
		apu_nodo actual,aux,aux2;		
};

void Menu(){
	cout<<"\n\t** COLA DINAMICA **"<<endl<<endl;
	cout<<"(1) Insertar Elemento"<<endl;
	cout<<"(2) Eliminar Elemento"<<endl;
	cout<<"(3) Mostrar Elemento"<<endl;
	//cout<<"(4) Vaciar Cola"<<endl;
	cout<<"(4) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

void cola::Insertar(int a){
	aux= new(nodo);
	aux->valor=a;
	if(actual==NULL){
		aux->sig=NULL;
		aux->ant=NULL;
		aux2=aux;
	}
	else{
		actual->sig=aux;
		aux->sig=NULL;
		aux->ant=actual;
	}
	actual=aux;
}

void cola::Mostrar(){
	if(actual==NULL){
		cout<<"** COLA VACIA **";
	}
	else{
		cout<<"El primer elemento es: "<<aux2->valor;
	}
	
}

/*MUESTRA COLA

void cola::Mostrar(){
	if(actual==NULL){
		cout<<"** COLA VACIA **";
	}
	else{
		cout<<"Los elementos de la cola son:"<<endl<<endl;
		do{
			cout<<"  "<<aux->valor;
			aux= aux->ant;
			if(aux==NULL){
				cout<<" -> NULL";
			}
		}while(aux!=NULL);
	}
	aux=actual;
}*/

void cola::Eliminar(){
	if(actual==NULL){
		cout<<"** COLA VACIA **";
	}
	else if(actual->ant==NULL){
		delete(actual);
		actual=NULL;
		aux=NULL;
		cout<<"** ELEMENTO ELIMINADO Y LA COLA ESTA VACIA **";
	}
	else{
		int num;
		num=aux2->valor;
		cout<<"** ELEMENTO "<<num<<" ELIMINADO **";
		aux=aux2->sig;
		delete(aux2);
		aux->ant=NULL;
		aux2=aux;
		aux=actual;	
	}
}

/*
void cola::Vaciar(){
	if(actual==NULL){
		cout<<"** COLA VACIA **";
	}
	else{
		while(aux!=NULL){
			actual=actual->ant;
			delete(aux);
			aux=actual;
		}
		cout<<"** COLA VACIADA **";
	}
}
*/


int main(){
	
	system("color B");
	int op,a;
	cola p;
	
	do{
		Menu();  cin>>op;
		system("cls");
		
		switch (op){
			
			case 1:
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA UN VALOR: "; cin>>a;
				p.Insertar(a);
				cout<<"\n** ELEMENTO AGREGADO **";
				break;
				
			case 2:
				cout<<"[ELIMINAR ELEMENTO]"<<endl<<endl;
				p.Eliminar();
				
				break;
				
			case 3:
				cout<<"[MOSTRAR COLA]"<<endl<<endl;
				p.Mostrar();
				
				break;
				
			/*case 4:
				cout<<"[VACIAR COLA]"<<endl<<endl;
				p.Vaciar();
				
				break;*/
				
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");

	}while(op!=4);
	
	
	return 0;
}
