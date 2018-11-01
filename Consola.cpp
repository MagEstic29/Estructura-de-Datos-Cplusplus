/*
	Name: Consola
	Copyright: 
	Author: Gutierrez Beltran JOnathan Ivan
	Date: 01/04/17 05:28 || 04/04/17 02:09
	Description: 
*/


#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define PI 3.1416


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
	int Inserta_alea(int tam);
	int muestra(void);
	lista(){inicial=NULL; final=NULL; aux=NULL; aux2=NULL; aux3=NULL;}
	apu_nodo inicial,final,aux,aux2,aux3;
};

lista::Inserta_alea(int tam){
	srand(time(NULL));
	int a;
	for(int i=0;i<tam;i++){
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
	cout<<"** CREADOS "<<tam<<" ELEMENTOS **";
}

lista::muestra(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		do{
			cout<<aux->valor<<" ";
			aux=aux->sig;
		}while(aux!=NULL);
	}
}

int main(){
	int com,op,a=0,b,lon,i,j,len,k,bandera=0,bandera2=0,bandera3=0,bandera4=0, bandera5=0;
	lista p;
	float num,res;
	char numeros[]={'0','1','2','3','4','5','6','7','8','9'};
	string encuentra="encuentra";
	string consola="Mi_Consola-> ";
	string localiza="localiza";
	string busca= "busca";
	string hola="hola";
	string salir="salir";
	
	char *cadena;
	cadena=(char*) calloc(70,sizeof(string));
	do{
		bandera5=0;
		cout<<consola; gets(cadena);
		lon=strlen(cadena);
		//Lee toda la cadena
		for(i=0;i<lon;i++){
			if(cadena[i]==salir[0] || cadena[i]==hola[0] || cadena[i]==encuentra[0] || cadena[i]==localiza[0] || cadena[i]==busca[0] || cadena[i]==numeros[0] || cadena[i]==numeros[1] || cadena[i]==numeros[2] || cadena[i]==numeros[3] || cadena[i]==numeros[4] || cadena[i]==numeros[5] || cadena[i]==numeros[6] || cadena[i]==numeros[7] || cadena[i]==numeros[8] || cadena[i]==numeros[9]  || cadena[i]=='='){
				//**Opcion Salir**
				if(cadena[i]==salir[0] && cadena[i+1]==salir[1] && cadena[i+2]==salir[2] && cadena[i+3]==salir[3] && cadena[i+4]==salir[4]){
					return 1;
				}
				//**Opcion Saludo**
				else if(cadena[i]==hola[0] && cadena[i+1]==hola[1] && cadena[i+2]==hola[2] && cadena[i+3]==hola[3]){
					cout<<"Hola, que accion deseas realizar? "<<endl;
					break;
				}
				//**Opcion Buscar**
				else if(cadena[i]==encuentra[0] && cadena[i+1]==encuentra[1] && cadena[i+2]==encuentra[2] && cadena[i+3]==encuentra[3] && cadena[i+4]==encuentra[4] && cadena[i+5]==encuentra[5] && cadena[i+6]==encuentra[6] && cadena[i+7]==encuentra[7]){
					bandera=0; bandera2=0; num=0; a=1; bandera3=0; bandera4=0;
					//Recorrer Cadena
					for(j=0;j<lon;j++){
						//Condicional punto decimal
						if(cadena[j]=='.'){
							bandera2=1;
						}
						//Busca el numero de la cadena
						for(k=0;k<10;k++){
							if(cadena[j]==numeros[k]){
							//Numeros decimales
							if(bandera2==1){
							num=num+(k/pow(10,a));
							a++;
							}
							//Numeros Enteros
							else{
								num=(num*10)+k; 
							}
						bandera=1;
						break;break;
							}
						}
						if(bandera==0){
							cout<<"* BORRANDO DISCO DURO **";
						}
						else{
							
						}
					}
					break;
				}
			}
		}
		
		cout<<endl;
	}while(1);
	
	
	
	return 0;
}
