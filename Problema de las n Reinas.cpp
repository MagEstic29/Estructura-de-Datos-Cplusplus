#include<iostream>

using namespace std;

class nodo{
	public:
		int x,y,c,a;
		nodo *sig;
};

typedef nodo *apu_nodo;

class lista{
	public:
		int Insertar(int i);
		int Mostrar_Coord();
		int Mostrar_Matr(int t);
		int Desarrollo(int t);
		lista(){
			inicial=NULL; aux=NULL; aux2=NULL;
		}apu_nodo inicial,aux,aux2;
};

lista::Insertar(int i){
	int g;
	for(int j=0;j<i;j++){
		aux=new(nodo);
		aux->x=0;
		aux->y=j;
		g=j-0;
		aux->c=g;
		aux->sig=NULL;
		if(inicial==NULL){
			aux->a=1;
			inicial=aux;
		}
		else{
			aux2=inicial;
			while(aux2->sig!=NULL){
				aux2=aux2->sig;
			}
			aux->a=0;
			aux2->sig=aux;
		}
	}
}

lista::Mostrar_Coord(){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		aux=inicial;
		while(aux!=NULL){
			cout<<aux->x<<" - "<<aux->y<<"\t"<<aux->c<<endl;
			aux=aux->sig;
		}
	}
}

lista::Mostrar_Matr(int t){
	if(inicial==NULL){
		cout<<"** LISTA VACIA **";
	}
	else{
		int i,j;
		aux=inicial;
		/*
		while(aux!=NULL){
			cout<<aux->x<<" - "<<aux->y<<"\t"<<aux->c<<endl;
			aux=aux->sig;
		}*/
		for(i=0;i<t;i++){
			for(j=0;j<t;j++){
				if(aux->y==i && aux->x==j){
					cout<<"1  ";
				}
				else{
					cout<<"0  ";
				}
			}
			aux=aux->sig;
			cout<<endl;
		}
	}
}

lista::Desarrollo(int t){
	int ban=0,h;
	aux=inicial->sig;
	//PIVOTE
	while(aux!=NULL){
		aux2=inicial;
		//COMPROBACION
		while(aux2!=aux && aux->x<t){
			h=aux->x-aux->y;
			if(h<0){
				h=(-1)*h;
			}
			//cout<<"entra\t"<<aux->x<<" , "<<aux->y<<"\t"<<aux->c<<endl;
			if(aux2->x==aux->x || (aux->x>aux2->x && (aux->x-aux->y==aux2->x-aux2->y)) || (aux2->x>aux->x && (aux->x+aux->y==aux2->x+aux2->y))){
				aux->x=aux->x+1;
				aux->c=aux->y-aux->x;
				if(aux->c<0){
					aux->c=(-1)*aux->c;
				}
				ban=1;
			}
			if(ban==1){
				aux2=inicial;
				ban=0;
			}
			else if(ban!=1){
				aux2=aux2->sig;
			}
		}
		//RETROCESO
		if(aux->x==t){
			aux->x=0;
			aux->c=aux->y-aux->x;
			if(aux->c<0){
				aux->c=(-1)*aux->c;
			}
			aux2=inicial;
			while(aux2->sig!=aux){
				aux2=aux2->sig;
			}
			aux2->x++;
			aux2->c=aux2->y-aux2->x;
			if(aux2->c<0){
				aux2->c=(-1)*aux2->c;
			}
			aux=aux2;			
		}
		else{
			aux=aux->sig;
		}
	}
}

int main(){
	system("color B");
	int tam;
	lista p;
	
	cout<<"\n\t** n - REINAS **"<<endl<<endl;
		cout<<"INGRESE LA DIMENSION DEL TABLERO: "; cin>>tam;
		if(tam==2 || tam==3){
			cout<<endl<<"** NO EXISTE ALGUNA SOLUCION **"<<endl<<endl;
		}
		else{
			cout<<"\nESPERE UN MOMENTO, PORFAVOR..."<<endl<<endl;
			p.Insertar(tam);
			p.Desarrollo(tam);
			cout<<endl;
			if(tam>30){
				p.Mostrar_Coord();
			}
			else{
				p.Mostrar_Matr(tam);
			}
		}
	
	return 0;
}
