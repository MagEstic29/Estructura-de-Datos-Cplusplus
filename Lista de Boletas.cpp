/*
	Name: Lista de Boletas en C++
	Copyright: 
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 01/03/17 17:13 ; 08/03/17 03:10 ; 15/03/17 05:40 ; 28/03/17 16:51 ; 29/03/17 02:33
	Description: Con cadenas de caracteres y Manejo de archivos
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class nodo{
	public:
		int boleta;
		int edad;
		string nombre;
		nodo *sig;
		nodo *ant;
};

typedef nodo *pnodo;

class lista{
	public:
		int Inserta_fin(int a,int e, char *n);
		int Inserta_in(int a,int e, char *n);
		int Inserta_ord(int a,int e, char *n);
		int Inserta_pos(int a,int e, char *n, int x);
		void Ordena_asc(void);
		void Ordena_des(void);
		int Elimina_in(void);
		int Elimina_fin(void);
		int Elimina_pos(int x);
		int Elimina_boleta(int b);
		int Muestra (void);
		int Actualiza_nodo(int a, int e, char *n,int x);
		int Guarda(void);
		int Recupera(void);
		lista(){inicial= NULL; aux= NULL; aux2=NULL; aux3=NULL; aux4=NULL;}
		pnodo inicial, aux, aux2,aux3,aux4;
};

lista::Inserta_fin(int a,int e, char *n){
	char *cadena1= (char*) calloc(60,sizeof(char));
	strcpy(cadena1,n);
	aux= new(nodo);
	aux->boleta=a;
	aux->edad=e;
	aux->nombre=cadena1;
	if(inicial==NULL){
		aux->sig= NULL;
		aux->ant=NULL;
		inicial= aux;
		aux2=inicial;
	}
	else{
		aux2->sig=aux;
		aux->sig=NULL;
		aux->ant=aux2;
		aux2=aux;
	}
}

lista::Inserta_ord(int a,int e, char *n){
	char *cadena1= (char*) calloc(60,sizeof(char));
	strcpy(cadena1,n);
	aux= new(nodo);
	aux->boleta=a;
	aux->edad=e;
	aux->nombre=cadena1;
	if(inicial==NULL){
		aux->sig=NULL;
		aux->ant=NULL;
		inicial=aux;
		aux2=inicial;
	}
	else{
		if(aux->boleta<=inicial->boleta){
			Inserta_in(a,e,n);
		}
		else if (aux->boleta>=aux2->boleta){
			Inserta_fin(a,e,n);
		}
		else{
			int bandera=0;aux3=inicial; aux4=aux3->sig;
			while(bandera!=1){
				if(aux->boleta>=aux3->boleta && aux3->sig!=NULL && aux->boleta<=aux4->boleta){
					
					aux->sig=aux4;
					aux->ant=aux3;
					aux4->ant=aux;
					aux3->sig=aux;
					bandera=1;
				}
				else{
					aux3=aux3->sig;
					aux4=aux3->sig;
				}
			}
		}
	}
}

lista::Inserta_in(int a,int e, char *n){
	char *cadena1= (char*) calloc(60,sizeof(char));
	strcpy(cadena1,n);
	aux= new(nodo);
	aux->boleta=a;
	aux->edad=e;
	aux->nombre=cadena1;
	if(inicial==NULL){
		aux->sig= NULL;
		inicial= aux;
		aux2=inicial;
	}
	else{
		aux->sig=inicial;
		inicial->ant=aux;
		inicial=aux;
	}
}

int lista::Inserta_pos(int a,int e, char *n, int x){
	int j=1, bandera=0; aux=inicial;
	if(inicial==NULL){
		cout<<"\n** POSICION NO ENCONTRADA **";
	}
	else{
		while(bandera!=1){
		if(j!=x && aux->sig!=NULL){
			aux=aux->sig;
			j++;
		}
		else if(aux->sig==NULL && j!=x){
			cout<<"\n** NO SE ENCONTRO LA POSICION EN LA LISTA **";
			bandera=1;
		}
		else if(j==x){
			if(aux->ant==NULL && aux->sig==NULL){
				Inserta_in(a,e,n);
			}
			else if(aux->sig==NULL && aux->ant!=NULL){
				char *cadena1= (char*) calloc(60,sizeof(char));
				strcpy(cadena1,n);
				aux3= new(nodo);
				aux3->boleta=a;
				aux3->edad=e;
				aux3->nombre=cadena1;
				aux3->sig=aux;
				aux3->ant=aux->ant;
				aux4=aux->ant;
				aux4->sig=aux3;
				aux->ant=aux3;
			}
			else if(aux->ant==NULL && aux->sig!=NULL){
				Inserta_in(a,e,n);
			}
			else{
				char *cadena1= (char*) calloc(60,sizeof(char));
				strcpy(cadena1,n);
				aux3= new(nodo);
				aux3->boleta=a;
				aux3->edad=e;
				aux3->nombre=cadena1;
				aux3->sig=aux;
				aux3->ant=aux->ant;
				aux4=aux->ant;
				aux4->sig=aux3;
				aux->ant=aux3;
			}
			cout<<"\n** ELEMENTO AGREGADO **";
			bandera=1;
		}
		}
	}
}

void lista::Ordena_asc(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		cout<<"ORDENANDO LISTA, POR FAVOR ESPERE...\n\n";
		aux3= inicial; aux4=aux2; int bandera=0, c;
		string cadena1;
		while(bandera!=1){
			if(aux4->boleta<aux3->boleta && aux4!=aux3){
				c=aux4->boleta;
				aux4->boleta=aux3->boleta;
				aux3->boleta=c;
				c=aux4->edad;
				aux4->edad=aux3->edad;
				aux3->edad=c;
				cadena1=aux4->nombre;
				aux4->nombre=aux3->nombre;
				aux3->nombre=cadena1;
				aux4=aux2;
			}
			else if(aux4==aux3 && aux3->sig!=NULL){
				aux3=aux3->sig;
				aux4=aux2;
			}
			else if(aux3->sig==NULL){
				bandera=1;
			}
			else{
				aux4=aux4->ant;
			}
		}
		system("pause"); system("cls");
	}
}


void lista::Ordena_des(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		cout<<"ORDENANDO LISTA, POR FAVOR ESPERE...\n\n";
		aux3= inicial; aux4=aux2; int bandera=0, c;
		string cadena1;
		while(bandera!=1){
			if(aux4->boleta>aux3->boleta && aux4!=aux3){
				c=aux4->boleta;
				aux4->boleta=aux3->boleta;
				aux3->boleta=c;
				c=aux4->edad;
				aux4->edad=aux3->edad;
				aux3->edad=c;
				cadena1=aux4->nombre;
				aux4->nombre=aux3->nombre;
				aux3->nombre=cadena1;
				aux4=aux2;
			}
			else if(aux4==aux3 && aux3->sig!=NULL){
				aux3=aux3->sig;
				aux4=aux2;
			}
			else if(aux3->sig==NULL){
				bandera=1;
			}
			else{
				aux4=aux4->ant;
			}
		}
		system("pause"); system("cls");
	}
}

lista::Elimina_in(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else if(inicial->sig!=NULL){
		aux=inicial->sig;
		delete(inicial);
		inicial=aux;
		inicial->ant=NULL;
		cout<<"** ELEMENTO ELIMINADO **";
	}
	else{
		delete(inicial);
		inicial=NULL;
		aux2=NULL;
		aux=NULL;
		cout<<"** ELEMENTO ELIMINADO Y LA LISTA ESTA VACIA **";
	}
}

lista::Elimina_fin(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else if(aux2->ant!=NULL){
		aux=aux2->ant;
		delete(aux2);
		aux2=aux;
		aux2->sig=NULL;
		cout<<"** ELEMENTO ELIMINADO **";
	}
	else{
		delete(aux2);
		inicial=NULL;
		aux2=NULL;
		aux=NULL;
		cout<<"** ELEMENTO ELIMINADO Y LA LISTA ESTA VACIA **";
	}
}

lista::Elimina_pos(int x){
	if(inicial==NULL){
		cout<<"\n** LISTA VACIA **";
	}
	else{
		aux= inicial; int j=1, bandera=0;
		while(bandera!=1){
			if(j!=x && aux->sig!=NULL){
				aux=aux->sig;
				j++;
			}
			else if(aux->sig==NULL && j!=x){
				cout<<"\n** NO SE ENCONTRO LA POSICION EN LA LISTA **";
				bandera=1;
			}
			else if(j==x){
				if(aux->ant==NULL && aux->sig==NULL){
					delete(aux);
					inicial=NULL;
					aux2=NULL;
					cout<<"\n** ELEMENTO ELIMINADO Y LA LISTA ESTA VACIA **";
				}
				else if(aux->sig==NULL && aux->ant!=NULL){
					cout<<endl;
					Elimina_fin();
				}
				else if(aux->ant==NULL && aux->sig!=NULL){
					cout<<endl;
					Elimina_in();
				}
				else{
					aux3=aux->ant;
					aux3->sig=aux->sig;
					aux3=aux->sig;
					aux3->ant=aux->ant;
					delete(aux);
					cout<<"\n** ELEMENTO ELIMINADO **";
				}
				bandera=1;
			}	
		}
	}
}

lista::Muestra(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		do{
			cout<<aux->boleta<<"\t"<<aux->nombre<<"\t\t"<<aux->edad<<endl;
			aux=aux->sig;
		}while(aux!=NULL);
	}
}

lista::Actualiza_nodo(int a,int e, char *n, int x){
	if(inicial==NULL){
		cout<<"\n** LISTA VACIA **";
	}
	else{
		int j=1, bandera=0; aux3= inicial;
		while(bandera!=1){
			if(j==x){
				aux3->boleta=a;
				aux3->edad=e;
				aux3->nombre=n;
				bandera=1;
				cout<<"\n** NODO ACTUALIZADO **";
			}
			else if(j!=x && aux3->sig!=NULL){
				aux3=aux3->sig;
				j++;
			}
			else if(j!=x && aux3->sig==NULL){
				cout<<"\n** POSICION NO ENCONTRADA **";
				bandera=1;
			}
		}
	}
}

//Manejo de Archivos

lista::Guarda(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
		remove("Lista de Alumnos.csv");
	}
	else{
		FILE *archivo;
		char *cadena2= (char*)calloc(70,sizeof(string));
		archivo= fopen("Lista de Alumnos.csv","w");
		sprintf(cadena2,"No. Boleta , Nombre del Alumno ,,,Edad\n\n");
		fputs(cadena2,archivo);
		
		aux=inicial; int bandera=0;
		while(bandera!=1){
			
			if(aux!=aux2){
				sprintf(cadena2,"%i,%s,,,%i\n",aux->boleta,aux->nombre.c_str(),aux->edad);
				fputs(cadena2,archivo);
				aux=aux->sig;
			}
			else{
				sprintf(cadena2,"%i,%s,,,%i\n",aux->boleta,aux->nombre.c_str(),aux->edad);
				fputs(cadena2,archivo);
				bandera=1;
			}
			
		}
		cout<<"** ARCHIVO GUARDADO **";
		fclose(archivo);
	}
}

lista::Recupera(){
	int e,b,bandera=0;
	
	FILE* archivo;
	//Auxiliares
	char *cadena=(char*) calloc(70,sizeof(string));
	char *cadena2=(char*) calloc(70,sizeof(string));
	char *cadena3=(char*) calloc(70,sizeof(string));
	
	archivo= fopen("Lista de Alumnos.csv","r");
	if(archivo==NULL){
		cout<<"** ARCHIVO NO ENCONTRADO **";;
	}
	else{
	rewind(archivo);
	fgets(cadena,70,archivo);
	fgets(cadena,70,archivo);
	//Recupera cada linea del archivo
	while(!feof(archivo)){
		fgets(cadena,70,archivo);
		/*Se utiliza strtok y strrev para ir quitando los pedasos que no nos interesa 
			y solo nos quede su edad, boleta y nombre*/
		//Edad
		cadena2=strrchr(cadena,',');
		strrev(cadena2);
		strtok(cadena2,",");
		strrev(cadena2);
		//atoi convierte cadena a entero
		e=atoi(cadena2);

		//Boleta
		char *cadena2=(char*) calloc(70,sizeof(string));
		strcpy(cadena2,cadena);
		strtok(cadena2,",");
		b=atoi(cadena2);
		
		//Nombre
		cadena3=strchr(cadena,',');
		strtok(cadena3,",");
		strrev(cadena3);
		strtok(cadena3,",");
		strrev(cadena3);
		
		//Inserta en nodo
		Inserta_fin(b,e,cadena3);
		bandera++;
		
		cout<<b<<"  "<<cadena3<<"  "<<e<<endl;
		/*if(bandera==2){
			break;
		}*/
	}
	fclose(archivo);
	cout<<"** ARCHIVO RECUPERADO Y LISTO PARA USAR **";

	}
}


void Menu(){
	cout<<"\n\t** LISTA DINAMICA **"<<endl<<endl;
	cout<<"(1) Insertar Elemento al Inicio"<<endl;
	cout<<"(2) Insertar Elemento al Final"<<endl;
	cout<<"(3) Insertar Ordenadamente"<<endl;
	cout<<"(4) Insertar en Posicion"<<endl;
	cout<<"(5) Ordenar Lista Ascendente"<<endl;
	cout<<"(6) Ordenar Lista Descendente"<<endl;
	cout<<"(7) Eliminar Elemento Inicial"<<endl;
	cout<<"(8) Eliminar Elemento Final"<<endl;
	cout<<"(9) Eliminar Elemento una Posicion"<<endl;
	cout<<"(10) Mostrar Lista"<<endl;
	cout<<"(11) Actualizar Registro"<<endl<<endl;
	cout<<"\t** MANEJO DE ARCHIVOS **"<<endl<<endl;
	cout<<"(12) Guardar Lista"<<endl;
	cout<<"(13) Recuperar Datos"<<endl;
	cout<<"(14) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

int main(){
	system("color B");
	int op,a,ord_asc=0,ord_des=0, x,e,comp=0;
	char *cadena= (char*) calloc(60,sizeof(char));
	
	lista p;
	
	do{
		Menu();  cin>>op;
		system("cls");
		
		switch (op){
			
			case 1:
			cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA LA BOLETA: "; cin>>a;
				cout<<"INTRODUZCA LA EDAD: "; cin>>e;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Inserta_in(a,e,cadena);
				cout<<"\n** ELEMENTO AGREGADO **";
				ord_asc=0;
				ord_des=0;
				
				break;
				
			case 2:
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA LA BOLETA: "; cin>>a;
				cout<<"INTRODUZCA LA EDAD: "; cin>>e;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Inserta_fin(a,e,cadena);
				cout<<"\n** ELEMENTO AGREGADO **";
				ord_asc=0;
				ord_des=0;
				
				break;
				
			case 3:
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA LA BOLETA: "; cin>>a;
				cout<<"INTRODUZCA LA EDAD: "; cin>>e;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Inserta_ord(a,e,cadena);
				cout<<"\n** ELEMENTO AGREGADO **";
				ord_asc=0;
				ord_des=0;
				
				break;
				
			case 4:
				cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA LA POSICION A AGREGAR: "; cin>>x;
				cout<<"INTRODUZCA LA BOLETA: "; cin>>a;
				cout<<"INTRODUZCA LA EDAD: "; cin>>e;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Inserta_pos(a,e,cadena,x);
				ord_asc=0;
				ord_des=0;
				
				
				
				break;
				
			case 5:
				cout<<"[ORDENAR LISTA]"<<endl<<endl;
				if(ord_asc==0){
					p.Ordena_asc();
					ord_asc++;
					cout<<"[ORDENAR LISTA]"<<endl<<endl;
					cout<<"** LISTA ORDENADA **";
					ord_des=0;
				}
				else{
					cout<<"** LISTA YA ORDENADA **";
				}
				
				break;
				
			case 6:
				cout<<"[ORDENAR LISTA]"<<endl<<endl;
				if(ord_des==0){
					p.Ordena_des();
					ord_des++;
					cout<<"[ORDENAR LISTA]"<<endl<<endl;
					cout<<"** LISTA ORDENADA **";
					ord_asc=0;
				}
				else{
					cout<<"** LISTA YA ORDENADA **";
				}
				
				break;
				
			case 7:
				cout<<"[ELIMINAR ELEMENTO]"<<endl<<endl;
				p.Elimina_in();
				
				break;
				
			case 8:
				cout<<"[ELIMINAR ELEMENTO]"<<endl<<endl;
				p.Elimina_fin();
				
				break;
				
			case 9:
				cout<<"[ELIMINAR ELEMENTO]"<<endl<<endl;
				cout<<"INTRODUZCA UNA POSICION: "; cin>>x;
				p.Elimina_pos(x);
				
				break;
				
			case 10:
				cout<<"[MOSTRAR LISTA]"<<endl<<endl;
				cout<<"No. Boleta |\t Nombre  \t\t\t|\tEdad"<<endl<<endl;
				p.Muestra();
				
				break;
				
			case 11:
				cout<<"[ACTUALIZAR REGISTRO]"<<endl<<endl;
				cout<<"INTRODUZCA LA POSICION A ACTUALIZAR: "; cin>>x;
				cout<<"INTRODUZCA LA BOLETA: "; cin>>a;
				cout<<"INTRODUZCA LA EDAD: "; cin>>e;
				cin.get();
				cout<<"INTRODUZCA EL NOMBRE: "; cin.getline(cadena,60,'\n');
				p.Actualiza_nodo(a,e,cadena,x);
				ord_asc=0;
				ord_des=0;
				
				break;
				
			case 12:
				cout<<"[GUARDAR A ARCHIVO]"<<endl<<endl;
				p.Guarda();
				comp=1;
				
				break;
				
			case 13:
				cout<<"[RECUPERAR DE ARCHIVO]"<<endl<<endl;
				if(comp==0){
					p.Recupera();
					comp=1;
				}
				else{
					cout<<"** ARCHIVO RECUPERADO Y LISTO PARA USAR **";
				}
				
				break;
		
		//Fin de Switch		
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");

	}while(op!=14);
	
	
	return 0;
}
