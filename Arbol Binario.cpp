#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>

using namespace std;

class nodo{
	public:
		int valor;
		nodo *izq,*der;
		nodo(){
			izq=NULL; der=NULL;
		}
};

typedef nodo *apu_nodo;

class arbol{
	public:
		int Insertar(apu_nodo aux2, int n,int i);
		int Inserta_Alea(apu_nodo aux2, int n,int i);
		int Recorrido_Pre(apu_nodo aux,int i);
		int Recorrido_Ino(apu_nodo aux,int i);
		int Recorrido_Pos(apu_nodo aux,int i);
		int Busqueda(apu_nodo aux, int n, int i, int b);
		int Guard_Pre(apu_nodo aux,int i, FILE *arc);
		int Guardar(int n, char *c);
		arbol(){
			raiz=NULL; aux=NULL; aux2=NULL;
		}apu_nodo raiz, aux, aux2;
};

arbol::Insertar(apu_nodo aux2, int n, int i){
	if(raiz==NULL){
		aux=new(nodo);
		aux->valor=n;
		raiz=aux;
		cout<<"\n** ELEMENTO INSERTADO **";
	}
	else{
		if(i==0){
			aux2=raiz;
			i++;
		}
		while(aux2!=NULL){
			if(n<aux2->valor && aux2->izq==NULL){
				aux=new(nodo);
				aux->valor=n;
				aux2->izq=aux;
				cout<<"\n** ELEMENTO INSERTADO **";
			}
			else if(n<aux2->valor && aux2->izq!=NULL){
				Insertar(aux2->izq,n,i);
			}
			else if(n>aux2->valor && aux2->der==NULL){
				aux=new(nodo);
				aux->valor=n;
				aux2->der=aux;
				cout<<"\n** ELEMENTO INSERTADO **";
			}
			else if(n>aux2->valor && aux2->der!=NULL){
				Insertar(aux2->der,n,i);
			}
			//Elemento repetido
			else{
				cout<<"\n** ELEMENTO YA INSERTADO **";
			}
			aux2=NULL;
		}
	}
}

arbol::Inserta_Alea(apu_nodo aux2, int n,int i){
	if(raiz==NULL){
		aux=new(nodo);
		aux->valor=n;
		raiz=aux;
	}
	else{
		if(i==0){
			aux2=raiz;
			i++;
		}
		while(aux2!=NULL){
			if(n<aux2->valor && aux2->izq==NULL){
				aux=new(nodo);
				aux->valor=n;
				aux2->izq=aux;
			}
			else if(n<aux2->valor && aux2->izq!=NULL){
				Inserta_Alea(aux2->izq,n,i);
			}
			else if(n>aux2->valor && aux2->der==NULL){
				aux=new(nodo);
				aux->valor=n;
				aux2->der=aux;
			}
			else if(n>aux2->valor && aux2->der!=NULL){
				Inserta_Alea(aux2->der,n,i);
			}
			//Elemento repetido
			else{
				
			}
			aux2=NULL;
		}
	}
}

arbol::Recorrido_Pre(apu_nodo aux,int i){
	if(i==0){
		aux=raiz;
		i++;
	}
	if(aux!=NULL){
		cout<<aux->valor<<"  ";
		Recorrido_Pre(aux->izq,i);
		Recorrido_Pre(aux->der,i);
	}
}

arbol::Recorrido_Ino(apu_nodo aux, int i){
	if(i==0){
		aux=raiz;
		i++;
	}
	if(aux!=NULL){
		Recorrido_Ino(aux->izq,i);
		cout<<aux->valor<<"  ";
		Recorrido_Ino(aux->der,i);
	}
}

arbol::Recorrido_Pos(apu_nodo aux, int i){
	if(i==0){
		aux=raiz;
		i++;
	}
	if(aux!=NULL){
		Recorrido_Pos(aux->izq,i);
		Recorrido_Pos(aux->der,i);
		cout<<aux->valor<<"  ";
	}
}

arbol::Busqueda(apu_nodo aux, int n, int i, int b){
	if(raiz==NULL){
		cout<<"\n** ARBOL VACIO **";
	}
	else{
		if(i==0){
			aux=raiz;
			i++;
		}
		if(aux==NULL && b==0){
			cout<<"** VALOR NO ENCONTRADO :c **";
		}
		while(aux!=NULL){
			if(n<aux->valor){
				i++;
				Busqueda(aux->izq,n,i,b);
			}
			else if(n>aux->valor){
				i++;
				Busqueda(aux->der,n,i,b);
			}
			else if(n==aux->valor){
				cout<<"** VALOR ENCONTRADO EN EL NIVEL "<<i<<" **";
				b++;
			}
			aux=NULL;
		}
	}
}

arbol::Guard_Pre(apu_nodo aux, int i, FILE *arc){
	char *cadena2= (char*)calloc(70,sizeof(string));
	if(i==0){
		aux=raiz;
		i++;
	}
	if(aux!=NULL){
		sprintf(cadena2,"%i,",aux->valor);
		fputs(cadena2,arc);
		Recorrido_Pre(aux->izq,i);
		Recorrido_Pre(aux->der,i);
	}
}

arbol::Guardar(int n, char *c){
	FILE *archivo;
	char *cadena1= (char*)calloc(70,sizeof(string));
	if(raiz!=NULL){
		archivo= fopen(c,"w");
		sprintf(cadena1,"\n,,ARBOL BINARIO,,\n\n");
		fputs(cadena1,archivo);
		if(archivo!=NULL){
			cout<<"** ARCHIVO CREADO **";
		}
		else{
			cout<<"** ERROR AL CREAR **";
		}
		switch(n){
			//FUNCION PRE-ORDEN
			case 1:
				Guard_Pre(raiz,0,archivo);
				
				break;
				
			//FUNCION IN-OREDEN
			case 2:
				
				break;
				
			//FUNCION POS-ORDEN
			case 3:
				
				break;
		}
		fclose(archivo);
	}
}

int Salirarc(char *c){
	FILE *archivo;
	remove(c);
}

int Menu(){
	cout<<"\n\t** MENU DE ARBOL BINARIO **"<<endl<<endl;
	cout<<"1) INSERTAR ELEMENTO"<<endl;
	cout<<"2) INSERTAR ALEATORIAMENTE"<<endl;
	cout<<"3) RECORRIDO PRE-ORDEN"<<endl;
	cout<<"4) RECORRIDO IN-ORDEN"<<endl;
	cout<<"5) RECORRIDO POS-ORDEN"<<endl;
	cout<<"6) BUSCAR ELEMENTO"<<endl;
	cout<<"7) GUARDAR EN ARCHIVO"<<endl;
	cout<<"8) SALIR"<<endl<<endl;
	cout<<"ELIJE UNA OPCION: ";
}

int MenuGuardar(){
	cout<<"\n\t** OPCIONES DE GUARDADO **"<<endl<<endl;
	cout<<"1) PRE-ORDEN"<<endl;
	cout<<"2) IN-ORDEN"<<endl;
	cout<<"3) POS-ORDEN"<<endl<<endl;
	cout<<"ELIJE UNA OPCION: ";
}

int main(){
	system("color B");
	int opc, num,i,a,j,b;
	arbol p;
	apu_nodo aux2,raiz,aux;
	srand(time(NULL));
	char *cadena= (char*) calloc(60,sizeof(char));
	
	do{
		//MENU
		Menu(); cin>>opc;
		system("cls");
		
		switch(opc){
			//FUNCION INSERTAR
			case 1:
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA UN NUMERO: "; cin>>num;
				i=0;
				p.Insertar(aux2,num,i);
				
				break;
			
			//FUNCION ALEATORIOS
			case 2:
				cout<<"[INSERTAR ALEATORIAMENTE]"<<endl<<endl;
				cout<<"INTRODUZCA EL NUMERO DE ELEMENTOS A GENERAR: "; cin>>num;
				cout<<"\nELEMENTOS GENERADOS:"<<endl<<endl;
				for(j=0;j<num;j++){
					a=rand()%99+1;
					cout<<a<<"  ";
					i=0;
					p.Inserta_Alea(aux2,a,i);
				}
				cout<<endl<<endl<<"** ELEMENTOS INSERTADOS **";
				
				break;
				
			//FUNCION PRE-ORDEN
			case 3:
				cout<<"[RECORRIDO PRE-ORDEN]"<<endl<<endl;
				i=0;
				p.Recorrido_Pre(raiz,i);
				
				break;
				
			//FUNCION IN-ORDEN
			case 4:
				cout<<"[RECORRIDO IN-ORDEN]"<<endl<<endl;
				i=0;
				p.Recorrido_Ino(raiz,i);
				
				break;
				
			//FUNCION POS-ORDEN
			case 5:
				cout<<"[RECORRIDO POS-ORDEN]"<<endl<<endl;
				i=0;
				p.Recorrido_Pos(raiz,i);
				
				break;
				
			//FUNCION BUSCAR
			case 6:
				cout<<"[BUSCAR ELEMENTO]"<<endl<<endl;
				cout<<"INGRESA EL NUMERO A BUSCAR: "; cin>>num;
				i=0,b=0;
				cout<<endl;
				p.Busqueda(aux,num,i,b);
				
				break;
				
			//FUNCION GUARDAR EN ARCHIVO
			case 7:
				cout<<"[GUARDAR EN ARCHIVO]"<<endl<<endl;
				MenuGuardar(); cin>>num;
				cout<<endl;
				cin.get();
				cout<<"INGRESA EL NOMBRE DEL ARCHIVO (SOLO LETRAS Y NUMEROS): "; cin.getline(cadena,60,'\n');
				strcat(cadena,".csv");
				p.Guardar(num,cadena);
				
				break;
			
			//SALIR
			case 8:
				Salirarc(cadena);
				cout<<"** GG IZI MID **";
				break;
				
			default:
				cout<<"** OPCION INCORRECTA **";
				break;
			
		}
		
		cout<<endl<<endl;
		cout<<"-------------------------------------------"<<endl;
		system("pause"); system("cls");
	}while(opc!=8);
	
	
	return 0;
}
