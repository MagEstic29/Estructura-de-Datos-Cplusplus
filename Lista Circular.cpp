#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

class nodo{
	public:
	string nombre;
	nodo *sig;
};

typedef nodo *apu_nodo;

class Lista_Circular{
	public:
		int Insertar(char* n);
		int Mostrar(void);
		int Eliminar(char *n);
		Lista_Circular(){
			inicial=NULL; final=NULL; aux=NULL; aux2=NULL;
		}
		apu_nodo inicial,final,aux,aux2;
};

Lista_Circular::Insertar(char *n){
	char *cadena1= (char*) calloc(60,sizeof(char));
	strcpy(cadena1,n);
	aux= new(nodo);
	aux->nombre=cadena1;
	if(inicial==NULL){
		aux->sig=NULL;
		inicial=aux;
		final=inicial;
	}
	else{
		aux->sig=inicial;
		final->sig=aux;
		final=final->sig;
	}
	cout<<"\n** ELEMENTO AGREGADO **";
}

Lista_Circular::Eliminar(char *n){
	if(inicial==NULL){
		cout<<"\n** LISTA VACIA **";
	}
	else{
		char *cadena1= (char*) calloc(60,sizeof(char));
		strcpy(cadena1,n);
		if(cadena1==inicial->nombre && cadena1!=final->nombre){
			final->sig=inicial->sig;
			delete(inicial);
			inicial=final->sig;
			cout<<"\n** ELEMENTO ELIMIADO **";
		}
		else if(cadena1==final->nombre && cadena1!=inicial->nombre){
			aux=inicial;
			while(aux->sig!=final){
				aux=aux->sig;
			}
			aux->sig=final->sig;
			delete(final);
			final=aux;
			cout<<"\n** ELEMENTO ELIMIADO **";
		}
		else if(cadena1==inicial->nombre && final==inicial){
			delete(inicial);
			inicial=NULL;
			final=NULL;
			aux=NULL;
			cout<<"\n** ELEMENTO ELIMIADO Y LA LISTA ESTA VACIA **";
		}
		else if(inicial->sig==NULL && cadena1!=inicial->nombre){
			cout<<"\n** ELEMENTO NO ENCONTRADO **";
		}
		else{
			aux2=inicial; aux=inicial->sig; int bandera=0;
			while(aux!=final){
				cout<<"si entra";
				if(cadena1==aux->nombre){
					aux2->sig=aux->sig;
					delete(aux);
					bandera=1;
					aux=final;
				}
				else{
					aux2=aux2->sig;
					aux=aux->sig;
				}
			}
			if(bandera==0){
				cout<<"\n** ELEMENTO NO ENCONTRADO **";
			}
			else{
				cout<<"\n** ELEMENTO ELIMIADO **";
			}
		}
	}
	
}

Lista_Circular::Mostrar(){
	aux=inicial;
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else if(aux==final){
		cout<<"1|\t"<<aux->nombre<<endl;
	}
	else{
		int bandera=0,i=1;
		while(bandera!=1){
			if(aux->sig==inicial){
				bandera=1;
			}
			cout<<i<<"|\t"<<aux->nombre<<endl;
			i++;
			aux=aux->sig;
		}
	}
}

void Menu(){
	cout<<"\n\t** LISTA DINAMICA **"<<endl<<endl;
	cout<<"(1) Insertar Elemento"<<endl;
	cout<<"(2) Eliminar Elemento"<<endl;
	cout<<"(3) Mostrar Elemento"<<endl;
	cout<<"(4) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

int main(){
	int a,b,i,bandera=0,op;
	srand(time(NULL));
	char *cadena= (char*) calloc(60,sizeof(char));
	
	Lista_Circular p;
	
	do{
		Menu(); cin>>op;
		system("cls");
		
		switch(op){
			case 1:
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Insertar(cadena);
				
				break;
				
			case 2:
				cout<<"[ELIMINAR ELEMENTO]"<<endl<<endl;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE A ELIMINAR: "; cin.getline(cadena,60,'\n');
				p.Eliminar(cadena);
				
				break;
				
			case 3:
				cout<<"[MOSTRAR LISTA]"<<endl<<endl;
				p.Mostrar();
				
				break;
			
			//Fin del Switch
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");
	}while(op!=4);
	
	
	
	return 0;
}
