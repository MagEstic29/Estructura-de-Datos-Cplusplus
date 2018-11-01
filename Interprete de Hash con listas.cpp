#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

class nodo{
	public:
	int valor;
	int posicion;
	nodo *hash;
	nodo *colicion;
};

typedef nodo *apu_nodo;

class lista{
	public:
		int Insertar(int a);
		int Buscar_Elemento(int a,int x);
		int Insertar_posicion(int n,int x);
		int Mostrar_lista(void);
		lista(){ inicial=NULL; final=NULL; aux=NULL; aux2=NULL; aux3=NULL;
		} apu_nodo inicial, final, aux, aux2, aux3;
};

lista::Insertar(int a){
	srand(time(NULL));
	int b,res;
	for(int i=0;i<a;i++){
		b=rand()%99+1;
		res=b%a;
		if(inicial==NULL){
			aux=new(nodo);
			aux->valor=b;
			aux->posicion=res;
			aux->colicion=NULL;
			aux->hash=NULL;
			inicial=aux;
			final=inicial;
		}
		else{
			aux=new(nodo);
			aux->valor=b;
			aux->posicion=res;
			aux->colicion=NULL;
			aux->hash=NULL;
			//Inserta Inicio
			if(res<inicial->posicion){
				aux->hash=inicial;
				inicial=aux;
			}
			//Inserta Final
			else if(res>final->posicion){
				final->hash=aux;
				final=aux;
			}
			//Inserta en Medio
			else{
				aux2=inicial; aux3=aux2->hash;
				while(aux2!=NULL){
					//Si existe la posicion se vuelve colision
					if(aux2->posicion==res){
						while(aux2->colicion!=NULL){
							aux2=aux2->colicion;
						}
						aux2->colicion=aux;
						break;
					}
					else if(aux2->posicion!=res && aux3->posicion>res){
						aux->hash=aux3;
						aux2->hash=aux;
						break;
					}
					else{
						aux2=aux3;
						aux3=aux2->hash;
					}
				}
			}
		}
	}
}

lista::Buscar_Elemento(int a,int x){
	cout<<endl;
	if(inicial==NULL){
		cout<<">>> ** LISTA VACIA **";
	}
	else{
		int res;
		res=a%x;
		aux=inicial;
		while(aux!=NULL){
			if(aux->posicion==res){
				aux2=aux;
				while(aux2!=NULL){
					if(aux2->valor==a){
						cout<<">>> ** VALOR ENCONTRADO EN LA POSICION "<<res<<" **";
						break;
					}
					else{
						aux2=aux2->colicion;
					}
					if(aux2==NULL){
						cout<<">>> ** VALOR NO ENCONTRADO **";
					}
				}
				break;
			}
			else{
				aux=aux->hash;
			}
			if(aux==NULL){
				cout<<">>> ** VALOR NO ENCONTRADO **";
			}
		}
	}
}

lista::Mostrar_lista(){
	if(inicial==NULL){
		cout<<">>> ** LISTA VACIA **";
	}
	else{
		cout<<">>> POSICION |\t"<<"COLICIONES"<<endl<<endl;
		aux=inicial; int vacio=0;
		while(aux!=NULL){
			while(vacio!=aux->posicion){
				cout<<vacio<<"  |\t"<<endl;
				vacio++;
			}
			//Imprime la posicion 
			cout<<aux->posicion<<"  |\t"<<aux->valor<<"  ";
			vacio++;
			//Imprime Colisiones
			if(aux->colicion!=NULL){
				aux2=aux->colicion;
				while(aux2!=NULL){
					cout<<aux2->valor<<"  ";
					aux2=aux2->colicion;
				}
			}
			cout<<endl;
			aux=aux->hash;
		}
	}
}

int main(){
	int tam,i,j,k,bandera,num,num2;
	char cadena[150];
	char numeros[]={'0','1','2','3','4','5','6','7','8','9'};
	lista p;
	string inserta=("inserta");
	string busca=("busca");
	string mostrar=("mostrar");
	string salir("salir");
	string muestra("muestra");
	
	while(1){
		//Lectura de comando
		cout<<">>> "; cin.getline(cadena,150,'\n');
		tam=strlen(cadena);
		//Recorrido de cadena
		for(i=0;i<tam;i++){
			//Funcion Inserta
			if(cadena[i]==inserta[0] && cadena[i+1]==inserta[1] && cadena[i+2]==inserta[2] && cadena[i+3]==inserta[3] && cadena[i+4]==inserta[4] && cadena[i+5]==inserta[5] && cadena[i+6]==inserta[6]){
				bandera=0; num=0;
				//Busqueda de numero
				for(j=0;j<tam;j++){
					for(k=0;k<10;k++){
						if(cadena[j]==numeros[k]){
							bandera=1;
							num=(num*10)+k;
						}
					}
				}
				//Condicional de error
				if(bandera==0){
					cout<<">>> **ERROR DE COMANDO**";
				}
				else{
					p.Insertar(num);
				}
				cout<<endl;
			}
			//Funcion Buscar
			if(cadena[i]==busca[0] && cadena[i+1]==busca[1] && cadena[i+2]==busca[2] && cadena[i+3]==busca[3] && cadena[i+4]==busca[4]){
				bandera=0; num2=0;
				//Busqueda de numero
				for(j=0;j<tam;j++){
					for(k=0;k<10;k++){
						if(cadena[j]==numeros[k]){
							bandera=1;
							num2=(num2*10)+k;
						}
					}
				}
				//Condicional de error
				if(bandera==0){
					cout<<">>> **ERROR DE COMANDO**";
				}
				else{
					p.Buscar_Elemento(num2,num);
				}
				cout<<endl;
			}
			//Funcion Mostrar
			if(cadena[i]==mostrar[0] && cadena[i+1]==mostrar[1] && cadena[i+2]==mostrar[2] && cadena[i+3]==mostrar[3] && cadena[i+4]==mostrar[4] && cadena[i+5]==mostrar[5] && cadena[i+6]==mostrar[6]  || (cadena[i]==muestra[0] && cadena[i+1]==muestra[1] && cadena[i+2]==muestra[2] && cadena[i+3]==muestra[3] && cadena[i+4]==muestra[4] && cadena[i+5]==muestra[5] && cadena[i+6]==muestra[6])){
				p.Mostrar_lista();
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
