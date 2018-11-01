#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include<iostream>
#include<time.h>
# define tam 100

using namespace std;

class nodo{
	public:
		int valor;
		nodo *sig;
		nodo *ant;
		int valorhr;
		int posicion;
		nodo *hash;
		nodo *colicion;
		int valorhcm;
		int posicioncm;
		nodo *hashcm;
		nodo *colision;
};

typedef nodo *apu_nodo;
int deb=0;
int var=0;
int col=0;

class listahcm{
	public:
		int Insertar(int a);
		int Buscar_Elemento(int a,int x);
		int Insertar_posicioncm(int n,int x);
		int Mostrar_listahcm(void);
		int llave(int b);
		listahcm(){ inicialhcm=NULL; finalhcm=NULL; auxhcm=NULL; auxhcm2=NULL; auxhcm3=NULL;
		} apu_nodo inicialhcm, finalhcm, auxhcm, auxhcm2, auxhcm3;
};

listahcm::Insertar(int a){
	srand(time(NULL));
	int b,res;
	for(int i=0;i<a;i++){
			b=rand()%100;
			res=llave(b);
		if(inicialhcm==NULL){
			auxhcm=new(nodo);
			auxhcm->valorhcm=b;
			auxhcm->posicioncm=res;
			auxhcm->colision=NULL;
			auxhcm->hashcm=NULL;
			inicialhcm=auxhcm;
			finalhcm=inicialhcm;
		}
		else{
			auxhcm=new(nodo);
			auxhcm->valorhcm=b;
			auxhcm->posicioncm=res;
			auxhcm->colision=NULL;
			auxhcm->hashcm=NULL;
			//Inserta Inicio
			if(res<inicialhcm->posicioncm){
				auxhcm->hashcm=inicialhcm;
				inicialhcm=auxhcm;
			}
			//Inserta Final
			else if(res>finalhcm->posicioncm){
				finalhcm->hashcm=auxhcm;
				finalhcm=auxhcm;
			}
			//Inserta en Medio
			else{
				auxhcm2=inicialhcm; auxhcm3=auxhcm2->hashcm;
				while(auxhcm2!=NULL){
					//Si existe la posicioncm se vuelve colision
					if(auxhcm2->posicioncm==res){
						while(auxhcm2->colision!=NULL){
							auxhcm2=auxhcm2->colision;
						}
						auxhcm2->colision=auxhcm;
						break;
					}
					else if(auxhcm2->posicioncm!=res && auxhcm3->posicioncm>res){
						auxhcm->hashcm=auxhcm3;
						auxhcm2->hashcm=auxhcm;
						
						break;
						
					}
					else{
						auxhcm2=auxhcm3;
						auxhcm3=auxhcm2->hashcm;
					}
				}
			}
		}
	}
}

listahcm::Buscar_Elemento(int a,int x){
	cout<<endl;
	if(inicialhcm==NULL){
		cout<<">>> ** LISTA VACIA **";
	}
	else{
		int res;
		res=llave(a);
		auxhcm=inicialhcm;
		while(auxhcm!=NULL){
			if(auxhcm->posicioncm==res){
				auxhcm2=auxhcm;
				while(auxhcm2!=NULL){
					if(auxhcm2->valorhcm==a){
						cout<<">>> ** VALOR ENCONTRADO EN LA POSICION "<<res<<" **";
						break;
					}
					else{
						auxhcm2=auxhcm2->colision;
					}
					if(auxhcm2==NULL){
						cout<<">>> ** VALOR NO ENCONTRADO **";
					}
				}
				break;
			}
			else{
				auxhcm=auxhcm->hashcm;
			}
			if(auxhcm==NULL){
				cout<<">>> ** VALOR NO ENCONTRADO **";
			}
		}
	}
}

listahcm::Mostrar_listahcm(){
	if(inicialhcm==NULL){
		cout<<">>> ** LISTA VACIA **";
	}
	else{
		cout<<">>> POSICION |\t"<<"COLICIONES"<<endl<<endl;
		auxhcm=inicialhcm; int vacio=0;
		while(auxhcm!=NULL){
			while((vacio!=auxhcm->posicioncm)){
				cout<<vacio<<"  |\t"<<endl;
				vacio++;
			}
			
			//Imprime la posicioncm 
			cout<<auxhcm->posicioncm<<"  |\t"<<auxhcm->valorhcm<<"  ";
			vacio++;
			//Imprime Colisiones
			if(auxhcm->colision!=NULL){
				auxhcm2=auxhcm->colision;
				while(auxhcm2!=NULL){
					cout<<auxhcm2->valorhcm<<"  ";
					auxhcm2=auxhcm2->colision;
				}
			}
			cout<<endl;
			auxhcm=auxhcm->hashcm;
		}
		var=vacio;
	}
}

listahcm:: llave(int b)
{
	int i,j,k,l=0,n=0,m=0;
	char num1[10]={};
	char num2[10]={};
	
	while(1)
	{
	j=b*b;
	sprintf(num1,"%d",j);
	l=strlen(num1);
	m=0;n=0;
	for(i=0;i<=l;i++)
	{
		if(l==6)
		{
			if(i>1)
			{
				if(m==2)break;
					num2[n]=num1[i];
					n++;m++;	
			}
		}
		else if(l==5)
		{
			if(i>0)
			{
				if(m==2)break;
					num2[n]=num1[i];
					n++;m++;	
			}
		}
		else if(l==4)
		{
			if(i>0)
			{
				if(m==2)break;
					num2[n]=num1[i];
					n++;m++;	
			}
		}
		else if(l==3)
		{
			if(i>0)
			{
				if(m==2)break;
					num2[n]=num1[i];
					n++;m++;	
			}
		}
		else
		{		if(m==2)break;
				num2[n]=num1[i];
					n++;m++;	
		}
				
	}
	j=atoi(num2);
	//printf("%d\t%s\t%s\t%d\t\n",b,num1,num2,l);
	return j;
	
	
	}
	
}



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


class listahr{
	public:
		int Insertar(int a);
		int Buscar_Elemento(int a,int x);
		int Insertar_posicion(int n,int x);
		int Mostrar_listahr(void);
		listahr(){ inicialhr=NULL; finalhr=NULL; auxhr=NULL; auxhr2=NULL; auxhr3=NULL;
		} apu_nodo inicialhr, finalhr, auxhr, auxhr2, auxhr3;
};

listahr::Insertar(int a){
	srand(time(NULL));
	int b,res;
	for(int i=0;i<a;i++){
		b=rand()%99+1;
		res=b%a;
		if(inicialhr==NULL){
			auxhr=new(nodo);
			auxhr->valorhr=b;
			auxhr->posicion=res;
			auxhr->colicion=NULL;
			auxhr->hash=NULL;
			inicialhr=auxhr;
			finalhr=inicialhr;
		}
		else{
			auxhr=new(nodo);
			auxhr->valorhr=b;
			auxhr->posicion=res;
			auxhr->colicion=NULL;
			auxhr->hash=NULL;
			//Inserta Inicio
			if(res<inicialhr->posicion){
				auxhr->hash=inicialhr;
				inicialhr=auxhr;
			}
			//Inserta Final
			else if(res>finalhr->posicion){
				finalhr->hash=auxhr;
				finalhr=auxhr;
			}
			//Inserta en Medio
			else{
				auxhr2=inicialhr; auxhr3=auxhr2->hash;
				while(auxhr2!=NULL){
					//Si existe la posicion se vuelve colision
					if(auxhr2->posicion==res){
						while(auxhr2->colicion!=NULL){
							auxhr2=auxhr2->colicion;
						}
						auxhr2->colicion=auxhr;
						break;
					}
					else if(auxhr2->posicion!=res && auxhr3->posicion>res){
						auxhr->hash=auxhr3;
						auxhr2->hash=auxhr;
						break;
					}
					else{
						auxhr2=auxhr3;
						auxhr3=auxhr2->hash;
					}
				}
			}
		}
	}
}

listahr::Buscar_Elemento(int a,int x){
	cout<<endl;
	if(inicialhr==NULL){
		cout<<">>> ** LISTA VACIA **";
	}
	else{
		int res;
		res=a%x;
		auxhr=inicialhr;
		while(auxhr!=NULL){
			if(auxhr->posicion==res){
				auxhr2=auxhr;
				while(auxhr2!=NULL){
					if(auxhr2->valorhr==a){
						cout<<">>> ** VALOR ENCONTRADO EN LA POSICION "<<res<<" **";
						break;
					}
					else{
						auxhr2=auxhr2->colicion;
					}
					if(auxhr2==NULL){
						cout<<">>> ** VALOR NO ENCONTRADO **";
					}
				}
				break;
			}
			else{
				auxhr=auxhr->hash;
			}
			if(auxhr==NULL){
				cout<<">>> ** VALOR NO ENCONTRADO **";
			}
		}
	}
}

listahr::Mostrar_listahr(){
	if(inicialhr==NULL){
		cout<<">>> ** LISTA VACIA **";
	}
	else{
		cout<<">>> POSICION |\t"<<"COLICIONES"<<endl<<endl;
		auxhr=inicialhr; int vacio=0;
		while(auxhr!=NULL){
			while((vacio!=auxhr->posicion)){
				cout<<vacio<<"  |\t"<<endl;
				vacio++;
			}
			
			//Imprime la posicion 
			cout<<auxhr->posicion<<"  |\t"<<auxhr->valorhr<<"  ";
			vacio++;
			//Imprime Colisiones
			if(auxhr->colicion!=NULL){
				auxhr2=auxhr->colicion;
				while(auxhr2!=NULL){
					cout<<auxhr2->valorhr<<"  ";
					auxhr2=auxhr2->colicion;
				}
			}
			cout<<endl;
			auxhr=auxhr->hash;
		}
	}
}

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
				//system("cls");
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
				//system("cls");
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
				//system("cls");
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

char Amayuscula(char may[100])
{
	int i;
	for (i=0;i<101;i++)
	{
		may[i]=toupper(may[i]);
	}
	
}
int conta=0;
char Alimpiar (char limpiar[100])
{
	int i;
	for (i=0;i<101;i++)
	{
		limpiar[i]='\0';
	}
}


int Aterminal(int op1,int op2,int op3,int op4,int op5, int op6, int op7)
{
	
	return 0;
	
}

int AConfirma(char s[tam][tam])
{
	int negacion=0;
		for(int i=0;i<tam;i++)
		{
			//printf("%s",s[i]);
			if(strcmp(s[i],"NO")==0)
			{
				
				negacion++;
			}
		}
		if((negacion%2)==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}

int AOrden(char cadena[tam][tam])
{
	for(int i=0;i<tam;i++)
	{

		if( (strcmp(cadena[i],"INSERTA")==0) || (strcmp(cadena[i],"AGREGA")==0) || (strcmp(cadena[i],"CREA")==0) || (strcmp(cadena[i],"GENERA")==0)  )
		{
		if(deb==1)	printf("inserta");
			return 1;
		}
		else if( (strcmp(cadena[i],"BORRA")==0) || (strcmp(cadena[i],"ELIMINA")==0)|| (strcmp(cadena[i],"DESTRUYE")==0)  )
		{
		if(deb==1)	printf("borra");
			return 2;
		}
		else if( (strcmp(cadena[i],"MUESTRA")==0) || (strcmp(cadena[i],"MOSTRAR")==0))
		{
		if(deb==1)	printf("muestra");
			return 3;
		}
		else if( (strcmp(cadena[i],"ORDENA")==0) || (strcmp(cadena[i],"ORGANIZA")==0)  )
		{
		if(deb==1)	printf("ordena");
			return 4;
		}
		else if( (strcmp(cadena[i],"BUSCA")==0) || (strcmp(cadena[i],"ENCUENTRA")==0)  )
		{
		if(deb==1)	printf("busca");
			return 5;
		}
		
	}
}
int Aorden1(char cadena[tam][tam])
{
	int a1=0,a2=0,a3=0,a4=0;
	for(int i=0; i<tam;i++)
	{
		if( (strcmp(cadena[i],"ASCENDENTE")==0)  || (strcmp(cadena[i],"ASCENDENTEMENTE")==0))
		{
		if(deb==1)	printf("mayor");
			a4++;
			return a4;
			//return 5;
		}
		else if( (strcmp(cadena[i],"DESCENDENTE")==0)  || (strcmp(cadena[i],"DESCENDENTEMENTE")==0) )
		{
		if(deb==1)	printf("menor");
			a4+=2;
			return a4;
			//return 6;
		}
		else if( (strcmp(cadena[i],"NODO")==0) || (strcmp(cadena[i],"NODOS")==0)  )
		{
		if(deb==1)	printf("nodo");
			a1++;
			a2++;
			//return 8;
		}
		else if( (strcmp(cadena[i],"LISTA")==0) )
		{
		if(deb==1)	printf("lista");
			a4=1;
			a1+=4;
			a2+=4;
			//return 9;
		}
		else if( (strcmp(cadena[i],"HASH")==0) )
		{
		if(deb==1)	printf("ash");
			
			a1+=100;
			a2+=100;
			//return 9;
		}
		else if( (strcmp(cadena[i],"METODO")==0) )
		{
		if(deb==1)	printf("metodo");
		
			a1+=11;
			a2+=11;
			//return 9;
		}
		else if( (strcmp(cadena[i],"RESIDUO")==0) || (strcmp(cadena[i],"RESIDUO")==0))
		{
		if(deb==1)	printf("residuo");
			
			a1+=22;
			a2+=22;
			//return 9;
		}
		else if( (strcmp(cadena[i],"CUADRADOS")==0) || (strcmp(cadena[i],"MEDIOS")==0))
		{
		if(deb==1)	printf("cuadrados");
			
			a1+=33;
			a2+=33;
			//return 9;
		}
		else if( (strcmp(cadena[i],"INICIO")==0) || (strcmp(cadena[i],"PRINCIPIO")==0)|| (strcmp(cadena[i],"INICIAL")==0)|| (strcmp(cadena[i],"PRIMER")==0) )
		{
		if(deb==1)	printf("inicio");
			a1++;
			a2++;
			//return 11;
		}
		else if( (strcmp(cadena[i],"VALOR")==0) || (strcmp(cadena[i],"NUMERO")==0) )
		{
		if(deb==1)	printf("valor");
			a1+=5;
			a2+=5;
			//return a1;
			//return al+5;
		}
		else if( (strcmp(cadena[i],"VALORES")==0))
		{
		if(deb==1)	printf("valor");
			a1++;
		}
		else if( (strcmp(cadena[i],"POSICION")==0) )
		{
		if(deb==1)	printf("posicion");
			a1+=2;
			a2+=2;
			//return 12;
		}
		else if( (strcmp(cadena[i],"ULTIMO")==0) || (strcmp(cadena[i],"FINAL")==0) )
		{
		if(deb==1)	printf("ultimo");
			a1+=3;
			a2+=3;
			//return 13;
		}
		else if( ((strcmp(cadena[i],"ALEATORIOS")==0) && (strcmp(cadena[i-1],"NUMEROS")==0) )|| ((strcmp(cadena[i],"ALEATORIO")==0) && (strcmp(cadena[i-1],"NUMERO")==0) ))
		{
		if(deb==1)	printf("random");
			a1+=6;
			//return a1;
		}
		else if( (strcmp(cadena[i],"POLLO")==0) || (strcmp(cadena[i],"POLLITO")==0)  || (strcmp(cadena[i],"POLLITOS")==0) )
		{
			printf("\n\tTerminal>Hola pollo!");
			return 0;
		}
		else if( (strcmp(cadena[i],"RANGO")==0) || (strcmp(cadena[i],"ENTRE")==0) || ( (strcmp(cadena[i],"DE")==0) && (strcmp(cadena[i+2],"A")==0) ) )
		{
		if(deb==1)	printf("rango");
			a1+=25;
			a2+=25;
			a4+=25;
		}
		else if( ( (strcmp(cadena[i],"MENORES")==0) && (strcmp(cadena[i+1],"QUE")==0) )|| (strcmp(cadena[i],"<")==0) || ( (strcmp(cadena[i],"MENOR")==0) && (strcmp(cadena[i+1],"QUE")==0) ) )
		{
		if(deb==1)	printf("rango");
			a1+=29;
			a2+=29;
			a4+=29;
		}
		else if( ( (strcmp(cadena[i],"MAYORES")==0) && (strcmp(cadena[i+1],"QUE")==0) )|| (strcmp(cadena[i],">")==0) || ( (strcmp(cadena[i],"MAYOR")==0) && (strcmp(cadena[i+1],"QUE")==0) ) )
		{
		if(deb==1)	printf("rango");
			a1+=27;
			a2+=27;
			a4+=27;
		}
		
		
	}
	if(a1<a2)
	{
		return a2;
	}
	else
	{
		return a1;
	}
			
}

int AFiltronum(char cadena[tam][tam])
{
	char filtro[15]={};
	int s=0,j,k=0,num,m=0;
	for(int i=0; i<tam;i++)
	{
		if( (strcmp(cadena[i],"VALOR")==0) )
		{
			s=i;
		}
	}
	if(s<1)
	{
		return -1;
	}
	else
	{
		for(int i=s;i<tam;i++)
		{
			if(m==1)break;
			for(j=0;j<tam;j++)
			{
				if((cadena[i][j]=='0'|| cadena[i][j]=='1'||cadena[i][j]=='2'||cadena[i][j]=='3'||cadena[i][j]=='4'||cadena[i][j]=='5'||cadena[i][j]=='6'||cadena[i][j]=='7'|| cadena[i][j]=='8' || cadena[i][j]=='9' || cadena[i][j]=='.'|| cadena[i][j]=='-'))
				{
					filtro[k]=cadena[i][j];
					k++;
					m=1;
				}
				else
				{
					m=2;
				}
				
			}
		}
	}
		if(m==2) return -1;
	num=atoi(filtro);
	return num;
}
int AFiltropos(char cadena[tam][tam])
{
	char filtro[15]={};
	int s=0,j,k=0,num,m=0;
	for(int i=0; i<tam;i++)
	{
		if( (strcmp(cadena[i],"POSICION")==0) )
		{
			s=i;
		}
	}
	if(s<1)
	{
		return -1;
	}
	else
	{
		for(int i=s;i<tam;i++)
		{
			if(m==1)break;
			for(j=0;j<tam;j++)
			{
				if((cadena[i][j]=='0'|| cadena[i][j]=='1'||cadena[i][j]=='2'||cadena[i][j]=='3'||cadena[i][j]=='4'||cadena[i][j]=='5'||cadena[i][j]=='6'||cadena[i][j]=='7'|| cadena[i][j]=='8' || cadena[i][j]=='9' || cadena[i][j]=='.'|| cadena[i][j]=='-'))
				{
					filtro[k]=cadena[i][j];
					k++;
					m=1;
				}
				else
				{
					m=2;
				}
				
			}
		}
	}
	if(m==2) return -1;
	num=atoi(filtro);
	return num;
}

int AFiltrorang(char cadena[tam][tam])
{
	char filtro[15]={};
	int s=0,j,k=0,num,m=0,u=0,z=0;
	for(int i=0;i<tam;i++)
	{
		if( (strcmp(cadena[i],"ENTRE")==0) || (strcmp(cadena[i],"DE")==0) )
		{
			s=i;
			break;
		}
		else if( (strcmp(cadena[i+3],"A")==0) || (strcmp(cadena[i+3],"-")==0) )
		{
			u=1;
			//printf("\nALt");
		}
		else if((strcmp(cadena[i],"<")==0) || (strcmp(cadena[i],">")==0))
		{
			s=i;
			u=1;
			//printf("\nALt");
			break;
		}
	}
	if(s<1 || u==0)
	{
		return -1;
	}
	else
	{
		for(int i=s;i<tam;i++)
		{
			if(m==1)break;
			for(j=0;j<tam;j++)
			{
				if((cadena[i][j]=='0'|| cadena[i][j]=='1'||cadena[i][j]=='2'||cadena[i][j]=='3'||cadena[i][j]=='4'||cadena[i][j]=='5'||cadena[i][j]=='6'||cadena[i][j]=='7'|| cadena[i][j]=='8' || cadena[i][j]=='9' || cadena[i][j]=='.'|| cadena[i][j]=='-'))
				{
					filtro[k]=cadena[i][j];
					k++;
					m=1;
				}
				
			}
		
		}
	}
	//puts(filtro);
	num=atoi(filtro);
	return num;
}

int AFiltrorang1(char cadena[tam][tam])
{
	char filtro[15]={};
	int s=0,j,k=0,num,m=0,u=0,z=0;
	for(int i=0;i<tam;i++)
	{
		if( (strcmp(cadena[i],"ENTRE")==0) || (strcmp(cadena[i],"DE")==0) )
		{
			s=i;
			break;
		}
		else if((strcmp(cadena[i+3],"A")==0))
		{
			u=1;
			z=i+3;
			//printf("\nALt");
		}
		else if((strcmp(cadena[i+3],"-")==0) )
		{
			u=1;
			z=i+4;
		}
	}
	if(s<1 || u==0)
	{
		return -1;
	}
	else
	{
		
		for(int i=z;i<tam;i++)
		{
			if(m==1)break;
			for(j=0;j<tam;j++)
			{
				if((cadena[i][j]=='0'|| cadena[i][j]=='1'||cadena[i][j]=='2'||cadena[i][j]=='3'||cadena[i][j]=='4'||cadena[i][j]=='5'||cadena[i][j]=='6'||cadena[i][j]=='7'|| cadena[i][j]=='8' || cadena[i][j]=='9' || cadena[i][j]=='.'|| cadena[i][j]=='-'))
				{
					filtro[k]=cadena[i][j];
					k++;
					m=1;
				}
				
			}
		
		}
	}
	num=atoi(filtro);
	return num;
		
		
}


int AFiltroalt(char cadena[tam][tam])
{
	char filtro[15]={};
	int s=0,j,k=0,num,m=0,u=0,z=0;
	for(int i=0; i<tam;i++)
	{
		if( (strcmp(cadena[i],"CON")==0) || (strcmp(cadena[i],"DE")==0) )
		{
			s=i;
			
		}
		if( (strcmp(cadena[i+3],"ALEATORIOS")==0) && (strcmp(cadena[i+2],"NUMEROS")==0) )
		{	
			u=1;
			//break;
			//printf("\nALt");
		}
		if( (strcmp(cadena[i+2],"ALEATORIOS")==0) && (strcmp(cadena[i+1],"NUMEROS")==0) )
		{	
			s=i;
			u=1;
			break;
			//printf("\nALt");
		}
	}
	if(s<1 || u==0)
	{
		return -1;
	}
	else
	{
		for(int i=s;i<tam;i++)
		{
			if(m==1)break;
			for(j=0;j<tam;j++)
			{
				if((cadena[i][j]=='0'|| cadena[i][j]=='1'||cadena[i][j]=='2'||cadena[i][j]=='3'||cadena[i][j]=='4'||cadena[i][j]=='5'||cadena[i][j]=='6'||cadena[i][j]=='7'|| cadena[i][j]=='8' || cadena[i][j]=='9' || cadena[i][j]=='.'|| cadena[i][j]=='-'))
				{
					filtro[k]=cadena[i][j];
					k++;
					m=1;
				}
				
			}
		
		}
		
	}
	//puts(filtro);
	num=atoi(filtro);
	return num;
	
}

int main(void)
{
	lista p,q;
	listahr phr;
	listahcm phcm;
	char s[tam]={}; 
	char z[tam]={};
	char cadena[tam][tam]={};
	char cadena2[tam][tam]={};
		printf("\n");
		
	while(1)
	{
		int i,k=0,j=0,negacion=0,op1,op2,op3,op4,op5,op6,op7,op9,op10,y=-1;
		for(i=0;i<100;i++)
		{
			s[i]='\0';
			z[i]='\0';
			for(j=0;j<100;j++)
			{
			cadena[i][j]='\0';	
			cadena2[i][j]='\0';
			}
		}
		printf("\n\tTerminal>");
		Alimpiar(s);
		gets(s);
		Amayuscula(s);
		if (strncmp(s,"SALIR",4) == 0) exit(0);
		
		for(i=0;i<tam;i++)
		{   
			for(j=0;j<tam;j++)
			{
				if(s[k]==' ')
				{
				 	j=tam;
				}
				else if(s[k]=='Y' || s[k]==',')
				{
				 	y=k;
				}
			else if(s[k]=='\0')
			{
				i=tam;
			}
			else
			{
				cadena[i][j]=s[k];
			}
			k++;
			}
		}
		k=0;
		if(y!=-1)
	{
			
	
		for(i=y;i<tam;i++)
		{   
			for(j=0;j<tam;j++)
			{
				if(s[k]==' ')
				{
				 	j=tam;
				}
			else if(s[k]=='\0')
			{
				i=tam;
			}
			else
			{
				cadena2[i][j]=s[k];
			}
			k++;
			}
		}
	}
		if((AConfirma(cadena))==1)
		{
			op1=AOrden(cadena);
			op2=Aorden1(cadena);
			op4=AFiltronum(cadena);
			op3=AFiltropos(cadena);
			op5=AFiltroalt(cadena);
			//AFiltrorang(cadena);
			op6=AFiltrorang(cadena);
			op7=AFiltrorang1(cadena);
		if(deb!=0){
		printf("\nresultado %d %d %d %d %d %d %d %d",op1,op2,op3,op4,op5,op6,op7,y);}
			//Aterminal(op1,op2,op3,op4,op5,op6,op7);
			
	srand(time(NULL));
	int op8=rand()%99+1;
	switch(op1)
	{
		case 1:
			if(op2==11)
			{if(op4!=-1)p.Insertar_inicio(op4);}
			else if (op2==12 )
			{if(op4!=-1 && op3!=-1)p.Insertar_posicion(op4,op3);}
			else if (op2 ==13)
			{if(op4!=-1)p.Insertar_fin(op4);}
			else if (op2==10)
			{if(op5==-1){ if( op4!=-1)p.Insertar_inicio(op4);
			}
			else
			p.Insertar_aleatorio(op5);}
			else if (op2==17 || op2==16)
			{p.Insertar_inicio(op8);}
			else if (op2==18)
			{if(op3!=-1)p.Insertar_posicion(op8,op3);}
			else if (op2==19)
			{p.Insertar_fin(op8);}
			if(op2==128 || op2==127 || op2==139 || op2==143)
			{phr.Insertar(op5);cout<<"\n** CREADOS "<<op5<<" ELEMENTOS **"; op9=op5;}
			if(op2==187 || op2==150 || op2==183)
			{phcm.Insertar(op5);cout<<"\n** CREADOS "<<op5<<" ELEMENTOS **"; op10=op5;}
			break;
		case 2:
			if(op2==6)
			{p.Eliminar_inicial();}
			else if (op2==3 || op2 ==7)
			{p.Eliminar_posicion(op3);}
			else if (op2==8)
			{p.Eliminar_final();}
			else if (op2==9 || op2==10)
			{if(op4!=-1)p.Eliminar_valor(op4);}
			else if (op2==32)
			{p.Eliminar_rango(op6+1,9999);}
			else if (op2==34)
			{p.Eliminar_rango(-9999,op6-1);}
			else if (op2==30 || op2==26 || op2==55)
			{p.Eliminar_rango(op6,op7);}
			else if (op2==4)
			{p.Eliminar_rango(-9999,9999);}
			break;
		case 3:
			if(op2==4)
			{cout<<"[MOSTRAR LISTA]"<<endl<<endl;p.Mostrar();}
			if(op2==104 || op2==104 || op2==137)
			{phr.Mostrar_listahr();}
			if(op2==181)
			{phcm.Mostrar_listahcm();}
			else if (op2==2)
			{cout<<"[MOSTRAR LISTA ASCENDENTE]"<<endl<<endl;p.Mostrar_asc();}
			else if (op2==3)
			{cout<<"[MOSTRAR LISTA DESCENDENTE]"<<endl<<endl;p.Mostrar_des();}
			else if (op2==55 || op2 ==30 || op2==29)
			{cout<<"[MOSTRAR LISTA]"<<endl<<endl;p.Mostrar_rango(op6,op7);}
			else if (op2==9 || op2==5)
			{cout<<"[MOSTRAR LISTA]"<<endl<<endl;p.Mostrar_rango(op4,op4);}
			break;
		case 4:
			if(op2==2)
			{p.Ordenar_asc();}
			else if (op2==3)
			{p.Ordenar_des();}
			break;
		case 5:
			if(op2==142)
			{ phr.Buscar_Elemento(op4,op9);}
			if(op2==153 || op2==186)
			{ phcm.Buscar_Elemento(op4,op9);}
			break;
		default:
		cout<<"\n\tTerminal>** OPCION INCORRECTA **";
				break;
	}
		}
	if (strncmp(s,"CLS",3) == 0) system("cls");
	if (strncmp(s,"AZUL",4) == 0) system("color B");
	if (strncmp(s,"VERDE",5) == 0) system("color A");
	if (strncmp(s,"ROJO",4) == 0) system("color C");
	if (strncmp(s,"AMARILLO",8) == 0) system("color E");
	if (strncmp(s,"BLANCO",6) == 0) system("color F");
		if(deb!=0)
		{
			if (strncmp(s,"DEV",3) == 0) deb=0;
		}
		else
		{
			if (strncmp(s,"DEV",3) == 0) deb=1;
		}
	}

	return 33;
}
