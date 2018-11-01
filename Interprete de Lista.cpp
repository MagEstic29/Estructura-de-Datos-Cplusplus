#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

int main(){
	int tam,i,j,k,bandera,num,num2,bandera2,bandera3,x;
	char cadena[150];
	char numeros[]={'0','1','2','3','4','5','6','7','8','9'};
	lista p;
	//Lista de funciones que realiza el interprete
	string inserta=("inserta");
	string busca=("busca");
	string mostrar=("mostrar");
	string salir=("salir");
	string muestra=("muestra");
	string alea=("aleat");
	string ord=("orde");
	string mayor=(">");
	string menor=("<");
	string rango=("rango");
	string bor=("borrar");
	
	while(1){
		//Lectura de comando
		cout<<">>> "; cin.getline(cadena,150,'\n');
		tam=strlen(cadena);
		//Recorrido de cadena
		for(i=0;i<tam;i++){
			//Funcion Inserta
			if(cadena[i]==inserta[0] && cadena[i+1]==inserta[1] && cadena[i+2]==inserta[2] && cadena[i+3]==inserta[3] && cadena[i+4]==inserta[4] && cadena[i+5]==inserta[5] && cadena[i+6]==inserta[6]){
				bandera=0; num=0; bandera2=0;
				//Busqueda de numero
				for(j=0;j<tam;j++){
					for(k=0;k<10;k++){
						if(cadena[j]==numeros[k]){
							bandera=1;
							num=(num*10)+k;
						}
					}
					if(cadena[j]==alea[0] && cadena[j+1]==alea[1] && cadena[j+2]==alea[2] && cadena[j+3]==alea[3] && cadena[j+4]==alea[4]){
						bandera2=1;
					}
				}
				//Condicional de error
				if(bandera==0){
					cout<<">>> **ERROR DE COMANDO**";
				}
				else{
					if(bandera2==1){
						p.Insertar_aleatorio(num);
					}
					else{
						p.Insertar_fin(num);
					}
				}
				cout<<endl;
			}
			
			//Funcion Mostrar
			if(cadena[i]==mostrar[0] && cadena[i+1]==mostrar[1] && cadena[i+2]==mostrar[2] && cadena[i+3]==mostrar[3] && cadena[i+4]==mostrar[4] && cadena[i+5]==mostrar[5] && cadena[i+6]==mostrar[6]  || (cadena[i]==muestra[0] && cadena[i+1]==muestra[1] && cadena[i+2]==muestra[2] && cadena[i+3]==muestra[3] && cadena[i+4]==muestra[4] && cadena[i+5]==muestra[5] && cadena[i+6]==muestra[6])){
				bandera=0; num=0; bandera2=0; bandera3=0;
				//Busqueda de numero
				for(j=0;j<tam;j++){
					if(cadena[j]==ord[0] && cadena[j+1]==ord[1] && cadena[j+2]==ord[2] && cadena[j+3]==ord[3]){
						bandera2=1;
					}
					if(cadena[j]==rango[0] && cadena[j+1]==rango[1] && cadena[j+2]==rango[2] && cadena[j+3]==rango[3] && cadena[j+4]==rango[4]){
						bandera3=1;
					}
				}
				//Condicional Muestra
					if(bandera2==1){
						if(bandera3==1){
							
						}
						else{
							for(j=0;j<tam;j++){
								if(cadena[j]==mayor[0]){
									p.Mostrar_des();
									break;
								}
								if(cadena[j]==menor[0]){
									p.Mostrar_asc();
									break;
								}
							}
						}
					}
					else if(bandera3==1 && bandera2!=1){
						//Busqueda de numero
						for(j=0;j<tam;j++){
							for(k=0;k<10;k++){
								if(cadena[j]==numeros[k]){
									bandera=1;
									num=(num*10)+k;
								}
							}
							if(cadena[j]==','){
								num2=num;
								num=0;
							}
							if(cadena[j+1]==']'){
								x=num;
							}
						}
						p.Mostrar_rango(num2,x);
					}
					else{
						p.Mostrar();
					}
				cout<<endl;
			}
			//Funcion Eliminar
			if(cadena[i]==bor[0] && cadena[i+1]==bor[1] && cadena[i+2]==bor[2] && cadena[i+3]==bor[3] && cadena[i+4]==bor[4] && cadena[i+5]==bor[5]){
				bandera=0; num=0; bandera2=0;
				//Busqueda de numero
				for(j=0;j<tam;j++){
					for(k=0;k<10;k++){
						if(cadena[j]==numeros[k]){
							bandera=1;
							num=(num*10)+k;
						}
					}
					if(cadena[j]==mayor[0]){
						bandera2=1;
					}
					if(cadena[j]==menor[0]){
						bandera=2;
					}
					if(cadena[j]==rango[0] && cadena[j+1]==rango[1] && cadena[j+2]==rango[2] && cadena[j+3]==rango[3] && cadena[j+4]==rango[4]){
						bandera2=3;
					}
				}
				//Condicional de error
				if(bandera==0){
					cout<<">>> **ERROR DE COMANDO**";
				}
				else{
					if(bandera2==1){
						p.Eliminar_mayor(num);
					}
					else if(bandera2==2){
						p.Eliminar_menor(num);
					}
					else if(bandera2==3){
						num=0;
						//Busqueda de numero
						for(j=0;j<tam;j++){
							for(k=0;k<10;k++){
								if(cadena[j]==numeros[k]){
									bandera=1;
									num=(num*10)+k;
								}
							}
							if(cadena[j]==','){
								num2=num;
								num=0;
							}
							if(cadena[j+1]==']'){
								x=num;
							}
						}
						p.Eliminar_rango(num2,x);
					}
					else{
						p.Eliminar_valor(num);
					}
				}
				
				cout<<endl;
			}
			
			//Funcion Salir
			if(cadena[i]==salir[0] && cadena[i+1]==salir[1] && cadena[i+2]==salir[2] && cadena[i+3]==salir[3] && cadena[i+4]==salir[4]){
				cout<<endl;
				return 1;
			}
		}
	}
	
	return 0;
}
