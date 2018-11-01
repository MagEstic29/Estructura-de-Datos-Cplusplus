#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

class nodo{
	public:
		int valor;
		nodo *sig;
		nodo *ant;
};

typedef nodo *apu_nodo;

class lista{
	public:
		int Insertar_inicio(int a);
		int Insertar_fin(int a);
		int Insertar_posicion(int a, int x);
		int Insertar_aleatorio(int n);
		int Eliminar_inicial(void);
		int Eliminar_final(void);
		int Eliminar_valor(int a);
		int Eliminar_posicion(int x);
		int Eliminar_rango(int a, int b);
		int Eliminar_mayor(int a);
		int Eliminar_menor(int a);
		int Ordenar_asc(void);
		int Ordenar_des(void);
		int Mostrar(void);
		int Mostrar_asc(void);
		int Mostrar_des(void);
		int Mostrar_rango(int a, int b);
		lista(){ inicial=NULL; final=NULL; aux=NULL; aux2=NULL; aux3=NULL; aux4=NULL;
		} apu_nodo inicial, final, aux, aux2, aux3, aux4;
};

lista::Insertar_inicio(int a){
	aux=new(nodo);
	aux->valor=a;
	aux->ant=NULL;
	if(inicial==NULL){
		aux->sig=NULL;
		inicial=aux;
		final=inicial;
	}
	else{
		aux->sig=inicial;
		inicial->ant=aux;
		inicial=aux;
	}
	cout<<"\n** ELEMENTO AGREGADO **";
}

lista::Insertar_fin(int a){
	aux=new(nodo);
	aux->valor=a;
	aux->sig=NULL;
	if(inicial==NULL){
		aux->ant=NULL;
		inicial=aux;
		final=inicial;
	}
	else{
		final->sig=aux;
		aux->ant=final;
		final=aux;
	}
	cout<<"\n** ELEMENTO AGREGADO **";
}

lista::Insertar_posicion(int a, int x){
	if(x==1 || inicial==NULL){
		Insertar_inicio(a);
	}
	else{
		aux=inicial->sig;
		int bandera=0,i=2;
		aux2=new(nodo);
		aux2->valor=a;
		while(bandera!=1){
			//Posicion NULL
			if(aux==NULL){
				if(i==x){
					Insertar_fin(a);
				}
				else{
					cout<<"\n** POSICION NO ENCONTRADA **";
				}
				bandera=1;
				break;
			}
			//Si encuentra posicion
			if(i==x){
				aux->ant->sig=aux2;
				aux2->ant=aux->ant;
				aux2->sig=aux;
				aux->ant=aux2;
				bandera=1;
				cout<<"\n** ELEMENTO AGREGADO **";
			}
			//Si no
			else{
				aux=aux->sig;
				i++;
			}
		}
	}
}

lista::Insertar_aleatorio(int n){
	srand(time(NULL));
	int a;
	for(int i=0;i<n;i++){
		a=rand()%50+1;
		aux=new(nodo);
		aux->valor=a;
		if(inicial==NULL){
			aux->sig=NULL;
			aux->ant=NULL;
			inicial=aux;
			final=inicial;
		}
		else{
			aux->ant=final;
			aux->sig=NULL;
			final->sig=aux;
			final=aux;
		}
	}
	cout<<"\n** CREADOS "<<n<<" ELEMENTOS **";
}

lista::Eliminar_inicial(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		inicial=aux->sig;
		delete(aux);
		if(inicial!=NULL){
			inicial->ant=NULL;
		}
		cout<<"** ELEMENTO ELIMINADO **";
	}
}

lista::Eliminar_final(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=final;
		final=aux->ant;
		delete(aux);
		if(final==NULL){
			inicial=NULL;
		}
		else{
			final->sig=NULL;
		}
		cout<<"** ELEMENTO ELIMINADO **";
	}
}

lista::Eliminar_valor(int a){
	if(inicial==NULL){
		cout<<"\n** LISTA VACIA **";
	}
	else{
		aux=inicial;
		int bandera=0;
		cout<<endl;
		while(aux!=NULL){
			if(aux->valor==a){
				if(aux==inicial){
					Eliminar_inicial();
				}
				else if(aux==final){
					Eliminar_final();
				}
				else{
					aux->ant->sig=aux->sig;
					aux->sig->ant=aux->ant;
					delete(aux);
					cout<<"** ELEMENTO ELIMINADO **";
				}
				bandera=1;
				break;
			}
			else{
				aux=aux->sig;
			}
		}
		if(bandera==0){
			cout<<"** ELEMENTO NO ENCONTRADO **";
		}
	}
}

lista::Eliminar_posicion(int x){
	cout<<endl;
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		if(x==1){
			Eliminar_inicial();
		}
		else{
			aux=inicial->sig;
			int bandera=0,i=2;
			while(aux!=NULL){
				if(i==x){
					if(aux==final){
						Eliminar_final();
					}
					else{
						aux->ant->sig=aux->sig;
						aux->sig->ant=aux->ant;
						delete(aux);
						cout<<"** ELEMENTO ELIMINADO **";
					}
					bandera=1;
					break;
				}
				else{
					aux=aux->sig;
					i++;
				}
			}
			if(bandera==0){
				cout<<"** POSICION NO ENCONTRADA **";
			}
		}
	}
}

lista::Eliminar_rango(int a, int b){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		int t=1;
		while(aux!=NULL){
			if(aux->valor>=a && aux->valor<=b){
				Eliminar_posicion(t);
				system("cls");
				aux=inicial;
				t=1;
			}
			else{
				aux=aux->sig;
				t++;
			}
		}
		cout<<"** ELEMENTOS ELIMINADOS **";
	}
}

lista::Eliminar_mayor(int a){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		int t=1;
		while(aux!=NULL){
			if(aux->valor>a){
				Eliminar_posicion(t);
				system("cls");
				aux=inicial;
				t=1;
			}
			else{
				aux=aux->sig;
				t++;
			}
		}
		cout<<"** ELEMENTOS ELIMINADOS **";
	}
}

lista::Eliminar_menor(int a){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		int t=1;
		while(aux!=NULL){
			if(aux->valor<a){
				Eliminar_posicion(t);
				system("cls");
				aux=inicial;
				t=1;
			}
			else{
				aux=aux->sig;
				t++;
			}
		}
		cout<<"** ELEMENTOS ELIMINADOS **";
	}
}

lista::Ordenar_asc(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else if(inicial==final){
		cout<<"** EXISTE SOLO UN ELEMENTO EN LA LISTA **";
	}
	else{
		aux=inicial; aux2=aux->sig;
		while(aux!=final){
			while(aux2!=NULL){
				if(aux2->valor>=aux->valor){
					aux2=aux2->sig;
				}
				else{
					if(aux==inicial && aux2==final){
						if(aux->sig==aux2){
							aux->sig=NULL;
							aux2->sig=aux;
							aux->ant=aux2;
							aux2->ant=NULL;
							inicial=aux2;
							final=aux;
							aux=inicial;
							aux2=final;
						}
						else{
							aux2->sig=aux->sig;
							aux->sig->ant=aux2;
							aux->sig=NULL;
							aux2->ant->sig=aux;
							aux->ant=aux2->ant;
							aux2->ant=NULL;
							inicial=aux2;
							final=aux;
							aux=inicial;
							aux2=aux->sig;
						}
					}
					else if(aux==inicial && aux2!=final){
						if(aux->sig==aux2){
							aux->sig=aux2->sig;
							aux2->sig->ant=aux;
							aux->ant=aux2;
							aux2->sig=aux;
							aux2->ant=NULL;
							inicial=aux2;
							aux=inicial;
							aux2=aux->sig;
						}
						else{
							aux->sig->ant=aux2;
							aux2->ant->sig=aux;
							aux2->sig->ant=aux;
							aux->ant=aux2->ant;
							aux3=aux2->sig;
							aux2->sig=aux->sig;
							aux->sig=aux3;
							aux2->ant=NULL;
							inicial=aux2;
							aux=inicial;
							aux2=aux->sig;
						}
					}
					else if(aux!=inicial && aux2==final){
						if(aux->sig==aux2){
							aux->ant->sig=aux2;
							aux2->ant=aux->ant;
							aux2->sig=aux;
							aux->ant=aux2;
							aux->sig=NULL;
							final=aux;
							aux=aux2;
							aux2=final;
						}
						else{
							aux->ant->sig=aux2;
							aux->sig->ant=aux2;
							aux2->ant->sig=aux;
							aux3=aux->ant;
							aux->ant=aux2->ant;
							aux2->ant=aux3;
							aux2->sig=aux->sig;
							aux->sig=NULL;
							final=aux;
							aux=aux2;
							aux2=aux->sig;
						}
					}
					else if(aux!=inicial && aux2!=final){
						if(aux->sig==aux2){
							aux->ant->sig=aux2;
							aux2->sig->ant=aux;
							aux2->ant=aux->ant;
							aux->sig=aux2->sig;
							aux2->sig=aux;
							aux->ant=aux2;
						}
						else{
							aux->ant->sig=aux2;
							aux->sig->ant=aux2;
							aux2->ant->sig=aux;
							aux2->sig->ant=aux;
							aux3=aux->ant;
							aux->ant=aux2->ant;
							aux2->ant=aux3;
							aux3=aux2->sig;
							aux2->sig=aux->sig;
							aux->sig=aux3;
						}
						aux=aux2;
						aux2=aux->sig;
					}
				}
			}
			aux=aux->sig;
			aux2=aux->sig;
		}
		cout<<"** LISTA ORDENADA ASCENDENTEMENTE **";
	}
}

lista::Ordenar_des(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else if(inicial==final){
		cout<<"** EXISTE SOLO UN ELEMENTO EN LA LISTA **";
	}
	//Ordenar mas de dos elementos
	else{
		aux=inicial; aux2=aux->sig;
		while(aux!=final){
			while(aux2!=NULL){
				if(aux2->valor<=aux->valor){
					aux2=aux2->sig;
				}
				else{
					//Caso 1
					if(aux==inicial && aux2==final){
						if(aux->sig==aux2){
							aux->sig=NULL;
							aux2->sig=aux;
							aux->ant=aux2;
							aux2->ant=NULL;
							inicial=aux2;
							final=aux;
							aux=inicial;
							aux2=final;
						}
						else{
							aux2->sig=aux->sig;
							aux->sig->ant=aux2;
							aux->sig=NULL;
							aux2->ant->sig=aux;
							aux->ant=aux2->ant;
							aux2->ant=NULL;
							inicial=aux2;
							final=aux;
							aux=inicial;
							aux2=aux->sig;
						}
					}
					//Caso 2
					else if(aux==inicial && aux2!=final){
						if(aux->sig==aux2){
							aux->sig=aux2->sig;
							aux2->sig->ant=aux;
							aux->ant=aux2;
							aux2->sig=aux;
							aux2->ant=NULL;
							inicial=aux2;
							aux=inicial;
							aux2=aux->sig;
						}
						else{
							aux->sig->ant=aux2;
							aux2->ant->sig=aux;
							aux2->sig->ant=aux;
							aux->ant=aux2->ant;
							aux3=aux2->sig;
							aux2->sig=aux->sig;
							aux->sig=aux3;
							aux2->ant=NULL;
							inicial=aux2;
							aux=inicial;
							aux2=aux->sig;
						}
					}
					//Caso 3
					else if(aux!=inicial && aux2==final){
						if(aux->sig==aux2){
							aux->ant->sig=aux2;
							aux2->ant=aux->ant;
							aux2->sig=aux;
							aux->ant=aux2;
							aux->sig=NULL;
							final=aux;
							aux=aux2;
							aux2=final;
						}
						else{
							aux->ant->sig=aux2;
							aux->sig->ant=aux2;
							aux2->ant->sig=aux;
							aux3=aux->ant;
							aux->ant=aux2->ant;
							aux2->ant=aux3;
							aux2->sig=aux->sig;
							aux->sig=NULL;
							final=aux;
							aux=aux2;
							aux2=aux->sig;
						}
					}
					//Caso 4
					else if(aux!=inicial && aux2!=final){
						if(aux->sig==aux2){
							aux->ant->sig=aux2;
							aux2->sig->ant=aux;
							aux2->ant=aux->ant;
							aux->sig=aux2->sig;
							aux2->sig=aux;
							aux->ant=aux2;
						}
						else{
							aux->ant->sig=aux2;
							aux->sig->ant=aux2;
							aux2->ant->sig=aux;
							aux2->sig->ant=aux;
							aux3=aux->ant;
							aux->ant=aux2->ant;
							aux2->ant=aux3;
							aux3=aux2->sig;
							aux2->sig=aux->sig;
							aux->sig=aux3;
						}
						aux=aux2;
						aux2=aux->sig;
					}
				}
			}
			aux=aux->sig;
			aux2=aux->sig;
		}
		cout<<"** LISTA ORDENADA DESCENDENTEMENTE **";
	}
}

lista::Mostrar(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		while(aux!=NULL){
			cout<<aux->valor<<"  ";
			aux=aux->sig;
		}
	}
}

lista::Mostrar_asc(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		int piv=inicial->valor;
		aux=inicial;
		//Sellecion de pivote
		while(aux!=NULL){
			if(aux->valor<piv){
				piv=aux->valor;
				aux=inicial;
			}
			else{
				aux=aux->sig;
			}
		}
		cout<<piv<<"  ";
		aux=inicial;
		aux2=inicial;
		//Muestra
		while(aux!=NULL){
			if(aux->valor<=piv){
				aux=aux->sig;
			}
			else{
				while(aux2!=NULL){
					if(aux2->valor>piv && aux2->valor<aux->valor){
						aux=aux2;
						aux2=inicial;
					}
					else{
						aux2=aux2->sig;
					}
				}
				piv=aux->valor;;
				cout<<piv<<"  ";
				aux2=inicial;
				while(aux2!=NULL){
					if(aux2->valor==piv && aux2!=aux){
						cout<<piv<<"  ";
					}
					aux2=aux2->sig;
				}
				aux=inicial;
				aux2=inicial;
			}			
		}
	}
}

lista::Mostrar_des(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		int piv=inicial->valor;
		aux=inicial;
		//Sellecion de pivote
		while(aux!=NULL){
			if(aux->valor>piv){
				piv=aux->valor;
				aux=inicial;
			}
			else{
				aux=aux->sig;
			}
		}
		cout<<piv<<"  ";
		aux=inicial;
		aux2=inicial;
		//Muestra
		while(aux!=NULL){
			if(aux->valor>=piv){
				aux=aux->sig;
			}
			else{
				while(aux2!=NULL){
					if(aux2->valor<piv && aux2->valor>aux->valor){
						aux=aux2;
						aux2=inicial;
					}
					else{
						aux2=aux2->sig;
					}
				}
				piv=aux->valor;;
				cout<<piv<<"  ";
				aux2=inicial;
				while(aux2!=NULL){
					if(aux2->valor==piv && aux2!=aux){
						cout<<piv<<"  ";
					}
					aux2=aux2->sig;
				}
				aux=inicial;
				aux2=inicial;
			}			
		}
	}
}

lista::Mostrar_rango(int a, int b){
	cout<<endl;
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		while(aux!=NULL){
			if(aux->valor>=a && aux->valor<=b){
				cout<<aux->valor<<"  ";
			}
			aux=aux->sig;
		}
	}
}

void Menu_lista(void){
	cout<<"\n\t** MENU DE LISTA **"<<endl<<endl;
	cout<<"1) INSERTAR AL INICIO"<<endl;
	cout<<"2) INSERTAR AL FINAL"<<endl;
	cout<<"3) INSERTAR EN POSICION"<<endl;
	cout<<"4) INSERTAR ALEATORIAMENTE"<<endl;
	cout<<"5) ELIMINAR INICIAL"<<endl;
	cout<<"6) ELIMINAR FINAL"<<endl;
	cout<<"7) ELIMINAR VALOR"<<endl;
	cout<<"8) ELIMINAR POSICION"<<endl;
	cout<<"9) ELIMINAR RANGO"<<endl;
	cout<<"10) ELIMINAR MAYOR QUE"<<endl;
	cout<<"11) ELIMINAR MENOR QUE"<<endl;
	cout<<"12) ORDENAR ASCENDENTE"<<endl;
	cout<<"13) ORDENAR DESCENDENTE"<<endl;
	cout<<"14) MOSTRAR LISTA"<<endl;
	cout<<"15) MOSTRAR LISTA ASCENDENTE"<<endl;
	cout<<"16) MOSTRAR LISTA DESCENDENTE"<<endl;
	cout<<"17) MOSTRAR RANGO"<<endl;
	cout<<"18) SALIR"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

int main(){
	system("color B");
	int num,opc,pos;
	lista p,q;
	
	do{
		
		Menu_lista(); cin>>opc;
		system("cls");
		
		switch(opc){
			case 1:
				cout<<"[INSERTAR INICIO]"<<endl<<endl;
				cout<<"INTRODUCE EL VALOR: "; cin>>num;
				p.Insertar_inicio(num);
				
				break;
				
			case 2:
				cout<<"[INSERTAR FINAL]"<<endl<<endl;
				cout<<"INTRODUCE EL VALOR: "; cin>>num;
				p.Insertar_fin(num);
				
				break;
				
			case 3:
				cout<<"[INSERTAR POSICION]"<<endl<<endl;
				cout<<"INTRODUCE EL VALOR: "; cin>>num;
				cout<<endl<<"INTRODUCE POSICION: "; cin>>pos;
				p.Insertar_posicion(num,pos);
				
				break;
				
			case 4:
				cout<<"[INSERTAR ALEATORIAMENTE]"<<endl<<endl;
				cout<<"ELEMENTOS ALEATORIOS A GENERAR: "; cin>>num;
				p.Insertar_aleatorio(num);
				
				break;
				
			case 5:
				cout<<"[ELIMINAR INICIAL]"<<endl<<endl;
				p.Eliminar_inicial();
				
				break;
				
			case 6:
				cout<<"[ELIMINAR FINAL]"<<endl<<endl;
				p.Eliminar_final();
				
				break;
				
			case 7:
				cout<<"[ELIMINAR VALOR]"<<endl<<endl;
				cout<<"INSERTA EL VALOR QUE DESEAS ELIMINAR: "; cin>>num;
				p.Eliminar_valor(num);
				
				break;
				
			case 8:
				cout<<"[ELIMINAR POSICION]"<<endl<<endl;
				cout<<"INGRESA LA POSICION A ELIMINAR: "; cin>>pos;
				p.Eliminar_posicion(pos);
				
				break;
				
			case 9:
				cout<<"[ELIMINAR RANGO]"<<endl<<endl;
				cout<<"INGRESE EL RANGO: "; cin>>num;
				system("cls");
				cout<<"[ELIMINAR RANGO]"<<endl<<endl;
				cout<<"INGRESE EL RANGO: "<<num<<" - "; cin>>pos;
				p.Eliminar_rango(num,pos);
				
				break;
				
			case 10:
				cout<<"[ELIMINAR MAYOR QUE]"<<endl<<endl;
				cout<<"INGRESE EL VALOR: "; cin>>num;
				p.Eliminar_mayor(num);
				
				break;
				
			case 11:
				cout<<"[ELIMINAR MENOR QUE]"<<endl<<endl;
				cout<<"INGRESE EL VALOR: "; cin>>num;
				p.Eliminar_menor(num);
				
				break;
				
			case 12:
				cout<<"[ORDENAR ASCENDENTE]"<<endl<<endl;
				p.Ordenar_asc();
								
				break;
				
			case 13:
				cout<<"[ORDENAR DESCENDENTE]"<<endl<<endl;
				p.Ordenar_des();
				
				break;
				
			case 14:
				cout<<"[MOSTRAR LISTA]"<<endl<<endl;
				p.Mostrar();
				
				break;
				
			case 15:
				cout<<"[MOSTRAR LISTA ASCENDENTE]"<<endl<<endl;
				p.Mostrar_asc();
				
				break;
				
			case 16:
				cout<<"[MOSTRAR LISTA DESCENDENTE]"<<endl<<endl;
				p.Mostrar_des();
				
				break;
				
			case 17:
				cout<<"[MOSTRAR RANGO]"<<endl<<endl;
				cout<<"INGRESE EL RANGO: "; cin>>num;
				system("cls");
				cout<<"[MOSTRAR RANGO]"<<endl<<endl;
				cout<<"INGRESE EL RANGO: "<<num<<" - "; cin>>pos;
				p.Mostrar_rango(num,pos);
				
				break;
				
			case 18:
				cout<<"** LISTA ELIMINADA Y SALIENDO DEL PROGRAMA **";
				break;
				
			default:
				cout<<"** OPCION INCORRECTA **";
				break;
		//Fin de Switch
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");
		
	}while(opc!=18);
	
	
	return 0;
}
