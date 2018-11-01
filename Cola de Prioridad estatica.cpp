/*
	Name: Cola de Prioridad Estatica
	Copyright: 
	Author: Gutierrez Beltran Jonathan Ivan
	Date: 01/09/17 05:46
	Description: dos arreglos, una para el valor y otra para la prioridad
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

void Menu_vacio(){
	cout<<"[Menu de la Cola]"<<endl<<endl;
	cout<<"1) Insertar Elemento"<<endl;
	cout<<"2) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: : ";
}

void Menu_general(){
	cout<<"[Menu de la Cola]"<<endl<<endl;
	cout<<"1) Insertar Elemento"<<endl;
	cout<<"2) Eliminar Elemento"<<endl;
	cout<<"3) Mostrar Cola"<<endl;
	cout<<"4) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: : ";
}

void Menu_Lleno(){
	cout<<"[Menu de la Cola]"<<endl<<endl;
	cout<<"1) Eliminar Elemento"<<endl;
	cout<<"2) Mostrar Cola"<<endl;
	cout<<"3) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: : ";

}

int main(){
	system("color B");
	int opc,num,prio,i,j,global=0,bandera=0,num2;
	int arg[5];
	int arg_pri[5];
	
	//Limpiamos arreglos
	for(i=0;i<5;i++){
		arg[i]=0;
		arg_pri[i]=0;
	}
	
	do{
		//Menu de cola vacia
		if(global==0){
			Menu_vacio(); cin>>opc;
			system("cls");
			
			switch(opc){
				case 1:
					cout<<"Introduzca un numero: "; cin>>num;
					do{
						system("cls");
						cout<<"Introduzca la prioridad menor o igual a 5: "; cin>>prio;
						if(prio>0 && prio<=5){
							bandera=1;
						}
						else{
							cout<<"Numero Incorrecto";
						}
						
					}while(bandera!=1);
					bandera=0;
					arg[0]=num; arg_pri[0]=prio;
					global++;
					cout<<"\n** ELEMENTO AGREGADO **";
					
					break;
					
				case 2:
					return 0;
					
					break;
			}
		}
		//Menu de general
		else if(global>0 && global<5){
			Menu_general(); cin>>opc;
			system("cls");
			
			switch(opc){
				case 1:
					cout<<"Introduzca un numero: "; cin>>num;
					do{
						system("cls");
						cout<<"Introduzca la prioridad menor o igual a 5: "; cin>>prio;
						if(prio>0 && prio<=5){
							bandera=1;
						}
						else{
							cout<<"Numero Incorrecto";
						}
						
					}while(bandera!=1);
					bandera=0; num2=prio;
					
					for(i=0;i<5;i++){
						if(prio<arg_pri[i]){
							for(j=5;j>i;j--){
								arg[j]=arg[j-1];
								arg_pri[j]=arg_pri[j-1];
							}
							arg[i]=num;
							arg_pri[i]=num2;
							
							global++;
							cout<<"\n** ELEMENTO AGREGADO **";
							break;
						}
						else if(arg_pri[i]==0){
							arg_pri[i]=prio; arg[i]=num;
							global++;
							cout<<"\n** ELEMENTO AGREGADO **";
							break;
						}
					}
					
				break;
				
				case 2:
					for(i=0;i<5;i++){
						arg[i]=arg[i+1];
						arg_pri[i]=arg_pri[i+1];
					}
					arg[5]=0; arg_pri[5]=0;
					global--;
					cout<<"\n** ELEMENTO ELIMINADO **";
				break;
				
				case 3:
					cout<<"ELEMENTOS EN LA COLA:"<<endl<<endl;
					for(i=0;i<5;i++){
						cout<<arg[i]<<"  ";
					}
					cout<<endl<<endl;
					cout<<"PRIORIDAD:"<<endl<<endl;
					for(i=0;i<5;i++){
						cout<<arg_pri[i]<<"  ";
					}
				break;
				
				case 4:
					return 0;
				break;
			}
			
		}
		
		//Menu de LLeno
		else if(global==5){
			Menu_Lleno(); cin>>opc;
			system("cls");
			
			switch(opc){
				case 1:
					for(i=0;i<5;i++){
						arg[i]=arg[i+1];
						arg_pri[i]=arg_pri[i+1];
					}
					arg[5]=0; arg_pri[5]=0;
					global--;
					cout<<"\n** ELEMENTO ELIMINADO **";
				break;
				
				case 2:
					cout<<"ELEMENTOS EN LA COLA:"<<endl<<endl;
					for(i=0;i<5;i++){
						cout<<arg[i]<<"  ";
					}
					cout<<endl<<endl;
					cout<<"PRIORIDAD:"<<endl<<endl;
					for(i=0;i<5;i++){
						cout<<arg_pri[i]<<"  ";
					}
				break;
				
				case 3:
					return 0;
				break;
			}
		}
		
		cout<<endl<<endl<<"---------------------------------"<<endl;
		system("pause");  system("cls");
		
	}while(1);
	
	return 0;
}
