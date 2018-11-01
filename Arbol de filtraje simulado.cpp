/*
	Name: PRACTICA 8
	Copyright: 
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 26/10/17 16:09
	Description: 
*/

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class nodo{
	public:
		int hoja, ID, ID_PADRE,valor;
		string pregunta;
		nodo* sig;
};

typedef nodo *apu_nodo;

class arbol{
	public:
		int Insertar(int g, int h, int p, char *cad);
		int Cargar_condiciones(int i, int con);
		int Mostrar(int g);
		int Guardar(void);
		int Calificacion(void);
		arbol(){
			raiz=NULL; aux=NULL; aux2=NULL; final=NULL;
		}apu_nodo raiz, aux, aux2,final;
};

arbol::Insertar(int g, int h, int p, char *cad){
	aux=new(nodo);
	aux->ID=g;
	aux->ID_PADRE=p;
	aux->hoja=h;
	aux->pregunta=cad;
	aux->sig=NULL;
	if(raiz==NULL){
		aux->ID_PADRE=0;
		raiz=aux;
		final=raiz;
	}
	else{
		int ban=0;
		aux2=raiz;
		while(aux2!=NULL){
			if(aux2->ID==p){
				ban++;
			}
			aux2=aux2->sig;
		}
		if(ban==0){
			cout<<"** NO SE ENCONTRO EL NODO PADRE, ELEMENTO NO INSERTADO **";
		}
		else{
			final->sig=aux;
			final=aux;
		}
	}
}

arbol::Cargar_condiciones(int i, int con){
	aux=raiz;
	while(aux!=NULL){
		if(aux->ID==i){
			aux->valor=con;
		}
		aux=aux->sig;
	}
}

arbol::Mostrar(int g){
	if(raiz==NULL){
		cout<<"** ARBOL VACIO **";
	}
	else{
		aux=raiz;
		while(aux!=NULL){
			cout<<aux->ID<<"\t| "<<aux->ID_PADRE<<"\t| "<<aux->pregunta<<"\t| "<<aux->valor<<endl;
			aux=aux->sig;
		}
	}
}

arbol::Guardar(){
	char *cadena= (char*) calloc(80,sizeof(char));
	FILE *archivo;
	aux=raiz;
	remove("arbolito.csv");
	while(aux!=NULL){
		archivo= fopen("arbolito.csv","a");
		sprintf(cadena,"%i,%i,%s\n",aux->ID,aux->ID_PADRE,aux->pregunta.c_str());
		fputs(cadena,archivo);
		fclose(archivo);
		aux=aux->sig;
	}
	
}

arbol::Calificacion(){
	if(raiz==NULL){
		cout<<"** NO SE HA CARGADO ARBOL **";
	}
	else{
		int band=0;
		aux=raiz;
		while(band!=1){
			aux2=raiz;
			while(aux2->ID_PADRE!=aux->ID){
				aux2=aux2->sig;
			}
			if(aux->valor==0){
				aux=aux2;
			}
			else if(aux->valor==1){
				aux=aux2->sig;
			}
			if(aux->hoja==1){
				band=1;
				cout<<"RESULTADO DEL FILTRAJE:  * "<<aux->pregunta<<" *";
			}
		}
	}
}

int Menu(){
	cout<<"\n\t** MENU DE FILTRAJE **"<<endl<<endl;
	cout<<"1) CARGAR ARBOL"<<endl;
	cout<<"2) CARGAR CONDICIONES DE USUARIO"<<endl;
	cout<<"3) MOSTRAR ARBOL"<<endl;
	cout<<"4) MOSTRAR ARCHIVO"<<endl;
	cout<<"5) GUARDAR A ARCHIVO"<<endl;
	cout<<"6) CALIFICAR AL SOLICITANTE"<<endl;
	cout<<"7) SALIR"<<endl<<endl;
	cout<<"ELIJE UNA OPCION: ";
}

int main(){
	int global=1,opc,num,ban=0,i,p,h,r=0, bandera=0,v;
	char c;
	FILE *archivo;
	arbol arb;
	string si="si";
	string no="no";
	char *cadena= (char*) calloc(80,sizeof(char));
	char *cadena2= (char*) calloc(80,sizeof(char));
	char *cadena3= (char*) calloc(80,sizeof(char));
	
	do{
		
		Menu(); cin>>opc;
		system("cls");
		
		switch(opc){
			case 1:
				cout<<"[CARGAR ARBOL]"<<endl<<endl;
				archivo= fopen("arbol_filtro.csv","r");
				rewind(archivo);
				fgets(cadena,80,archivo);
				fgets(cadena,80,archivo);
				while(!feof(archivo)){
					//ID
					strcpy(cadena2,cadena);
					strtok(cadena2,",");
					i=atoi(cadena2);
					if(r==i){
						ban=1;
					}
					c=r;
					//HOJA
					strcpy(cadena3,cadena);
					strrev(cadena3);
					strtok(cadena3,",");
					strrev(cadena3);
					h=atoi(cadena3);
					//ID_PADRE
					strcpy(cadena2,cadena);
					cadena3=strstr(cadena2,",");
					strrev(cadena3);
					cadena3=strstr(cadena3,",,");
					strrev(cadena3);
					strtok(cadena3,",");
					strrev(cadena3);
					strtok(cadena3,",");
					strrev(cadena3);
					p=atoi(cadena3);
					//SENTENCIA
					strcpy(cadena2,cadena);
					cadena2=strstr(cadena2,",,");
					strtok(cadena2,",");
					strrev(cadena2);
					strtok(cadena2,",");
					strrev(cadena2);
					//PASAMOS AL ARBOL
					if(ban!=1){
						arb.Insertar(i,h,p,cadena2);
					}
					fgets(cadena,80,archivo);
				}
				
				fclose(archivo);
				cout<<"** ARCHIVO CARGADO **";
				bandera=1;
				
				break;
				
			case 2:
				cout<<"[CARGAR CONDICIONES]"<<endl<<endl;
				if(bandera==0){
					cout<<"** NO SE HA CREADO NINGUN CUESTIONARIO **";
				}
				else{
					archivo= fopen("condiciones de usuario.csv","r");
						if(archivo==NULL){
							cout<<"** ARCHIVO NO ENCONTRADO **";
						}else{
							rewind(archivo);
							fgets(cadena,80,archivo);
							fgets(cadena,80,archivo);
							while(!feof(archivo)){
								//ID
								strcpy(cadena2,cadena);
								strtok(cadena2,",");
								i=atoi(cadena2);
								//VALOR
								strcpy(cadena2,cadena);
								strrev(cadena2);
								strtok(cadena2,",");
								strrev(cadena2);
								if(i==7 || i==9){
									v=atoi(cadena2);
									if(v<=1500){
										v=0;
									}
									else if(v>1500){
										v=1;
									}
								}
								else{
									if(cadena2[0]==si[0]){
										v=1;
									}
									else if(cadena2[0]==no[0]){
										v=0;
									}
								}
								cout<<v;
								arb.Cargar_condiciones(i,v);
								fgets(cadena,80,archivo);
							}
						}
						fclose(archivo);
				}
				//INGRESAR ELEMENTOS AL ARBOL
				/*cout<<"[INSERTAR ELEMENTO]"<<endl<<endl;
				cout<<"INGRESA EL ID PADRE: "; cin>>num;
				cin.get();
				cout<<"INGRESA EL TEXTO: "; cin.getline(cadena,60,'\n');
				arb.Insertar(global,0,num,cadena);
				global++;*/
				
				break;
				
			case 3:
				cout<<"[MOSTRAR ARBOL]"<<endl<<endl;
				cout<<"ID\t| ID_PADRE\t| TEXTO\t| VALOR"<<endl<<endl;
				arb.Mostrar(global);
				
				break;
				
			case 4:
				cout<<"[MOSTRAR ARCHIVO]"<<endl<<endl;
				archivo= fopen("arbolito.csv","r");
				if(archivo==NULL){
					cout<<"** ARCHIVO NO ENCONTRADO **";;
				}
				else{
					rewind(archivo);
					do{
						c= fgetc(archivo);
						if(c==','){
							c=' ';
						}
						printf("%c",c);
					}while(c!=EOF);
				}
				fclose(archivo);
				
				break;
				
			case 5:
				cout<<"[GUARDAR A ARCHIVO]"<<endl<<endl;
				arb.Guardar();
				
			case 6:
				cout<<"[CALIFICAR SOLICITANTE]"<<endl<<endl;
				arb.Calificacion();
				
				break;
				
			case 7:
				
				break;
				
			default:
				cout<<"** OPCION INCORRECTA **";
				break;
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");
	}while(opc!=7);
	
	return 0;
}
