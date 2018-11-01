#include<iostream>
#define MAX_POS 6

using namespace std;

void Menu(void){
	cout<<"\n\tPILAS EN C++"<<endl<<endl;
	cout<<"(1) INSERTAR ELEMENTO"<<endl;
	cout<<"(2) MOSTRAR ELEMENTO"<<endl;
	cout<<"(3) ELIMINAR ELEMENTO"<<endl;
	cout<<"(4) SALIR"<<endl<<endl;
	
	cout<<"ELIJA UNA OPCION: ";
}

void limpia_arg(int arreglo[]){
	int o;
	for(o=0;o<MAX_POS;o++){
		arreglo[o]=0;
	}
}

int main(){
	system("color B");
	int op,valor,arreglo[MAX_POS],j=0;
	limpia_arg(arreglo);
	
	do{
		Menu();  cin>>op;
		system("cls");
		switch (op){
			case 1:
				
				cout<<"[INSERTAR ELEMENTO]"<<endl;
				cout<<"\n\nINTRODUZCA UN VALOR: "; cin>>valor;
				
				if(j==MAX_POS){
					cout<<"\n\n** PILA LLENA **";
				}
				else{
					arreglo[j]=valor;
					cout<<"\n\n** ELEMENTO "<<valor<<" AGREGADO **";
					j++;
				}
				
				break;
			
			case 2:
				
				cout<<"[MOSTRAR ELEMENTO]";
				if(j==0){
					cout<<"\n\n** LA PILA ESTA VACIA **";
				}
				else{
					cout<<"\n\nEL ELEMENTO EN LA SUPERFICIE ES:  "<<arreglo[j-1];
				}
				break;
				
			 case 3:
			 	
			 	cout<<"[ELIMINAR ELEMENTO]";
			 	if(j==0){
			 		cout<<"\n\n** LA PILA ESTA VACIA **";
				 }
				 else{
				 	arreglo[j-1]=0;
				 	j--;
				 	cout<<"\n\n** ELEMENTO ELIMINADO **";
				 }
				
				break;
		}
		
		cout<<endl<<endl;
		cout<<"--------------------------------------"<<endl;
		system("pause"); system("cls");
	}while(op!=4);
	
	return 0;
}
