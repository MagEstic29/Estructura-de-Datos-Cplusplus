#include<iostream>

using namespace std;

class nodo{
	public:
		float coe;
		float exp;
		nodo *sig;
};

typedef nodo *apu_nodo;

class lista{
	public:
		float Inserta(float c,float e);
		float Mostrar(void);
		float Derivar(void);
		float Integrar(void);
		float Sumar(float c,float e);
		float Multiplicar(float c, float e);
		lista Multiplicar2(lista p,lista q);
		lista(){
			inicial=NULL; fin=NULL; aux=NULL; aux2=NULL; aux3=NULL;
		}
		apu_nodo inicial,fin,aux,aux2,aux3;
};

float lista::Inserta(float c, float e){
	aux=new(nodo);
	aux->coe=c;
	aux->exp=e;
	aux->sig=NULL;
	if(inicial==NULL){
		inicial=aux;
		fin=inicial;
	}
	else{
		if(aux->exp>inicial->exp){
			aux->sig=inicial;
			inicial=aux;
		}
		else if(aux->exp<fin->exp){
			fin->sig=aux;
			fin=aux;
		}
		else{
			aux2=inicial; aux3=aux2->sig; float bandera=0;
			while(bandera!=1){
				if(aux->exp<=aux2->exp && aux->exp>=aux3->exp){
					aux2->sig=aux;
					aux->sig=aux3;
					bandera=1;
				}
				else{
					aux2=aux2->sig;
					aux3=aux2->sig;
				}
			}
		}
	}
}

float lista::Mostrar(){
	aux=inicial;
	while(aux!=NULL){
		if(aux->coe>=0){
			cout<<"+"<<aux->coe<<"x^"<<aux->exp<<" ";
		}
		else{
			cout<<aux->coe<<"x^"<<aux->exp<<" ";
		}
		
		aux=aux->sig;
	}
}

float lista::Derivar(){
	aux=inicial;
	while(aux!=NULL){
		aux->coe=aux->coe*aux->exp;
		aux->exp=aux->exp-1;
		aux=aux->sig;
	}
}

float lista::Integrar(){
	aux=inicial;
	while(aux!=NULL){
		aux->exp=aux->exp+1;
		aux->coe=aux->coe/aux->exp;
		aux=aux->sig;
	}
}

float lista::Sumar(float c,float e){
	aux=inicial;
	while(aux!=NULL){
		if(e==aux->exp){
			aux->coe=aux->coe+c;
			break;
		}
		else if(e!=aux->exp && aux->sig!=NULL){
			aux=aux->sig;
		}
		else if(e!=aux->exp && aux->sig==NULL){
			Inserta(c,e);
			break;
		}
	}
}

float lista::Multiplicar(float c,float e){
	lista q,o;
	float a,b;
	aux=inicial;
	while(aux!=NULL){
		a=c*aux->coe;
		b=e+aux->exp;
		q.Inserta(a,b);
		
		aux=aux->sig;
	}
	cout<<endl;
	q.Mostrar();
	cout<<endl;
	system("pause");
}

lista lista::Multiplicar2(lista p,lista q){
	lista o;
	aux=p.inicial; int c,e,bandera=0;
	aux2=q.inicial;
	while(aux2!=NULL){
		aux=p.inicial;
		while(aux!=NULL){
			c=aux->coe*aux2->coe;
			e=aux->exp+aux2->exp;
			if(bandera==0){
				o.Inserta(c,e);
				bandera=1;
			}
			else{
				o.Sumar(c,e);
			}
			aux=aux->sig;
		}
		aux2=aux2->sig;
	}
	cout<<"LA MULTIPLICACION ES:"<<endl<<endl;
	o.Mostrar();
}

void Menu(){
	cout<<"[MENU]"<<endl<<endl;
	cout<<"1) Derivar Polinomio"<<endl;
	cout<<"2) Integrar Polinomio"<<endl;
	cout<<"3) Sumar dos Polinomios"<<endl;
	cout<<"4) Multiplicar dos Polinomios"<<endl;
	cout<<"5) Salir"<<endl<<endl;
	cout<<"ELIJA UNA OPCION: ";
}

int main(){
	float terminos,rep=0,coe,exp,bandera,bandera2=0;
	int op;
	lista p,q;
	
	cout<<"Cuantos terminos desea ingresar?: "; cin>>terminos; system("cls");
	
	while(rep!=terminos){
		bandera=0;
		cout<<"[Termino "<<rep+1<<" ]"<<endl<<endl;
		cout<<"Ingrese el coeficiente: "; cin>>coe;
		//Verifica que el exponente sea positivo
		while(bandera!=1){
			cout<<"Ingrese el exponente: "; cin>>exp;
			if(exp<0){
				cout<<"\n** El exponente no puede ser negativo **"<<endl;
			}
			else{
				bandera=1;
			}
		}
		//Metemos los valores a la lista
		if(bandera2==0){
			p.Inserta(coe,exp);
			bandera2=1;
		}
		else{
			p.Sumar(coe,exp);
		}
		
		rep++;
		system("cls");
	}
	
	//Mostramos Menu
	system("cls");
	p.Mostrar();
	cout<<endl<<endl;
	Menu(); cin>>op;
	system("cls");
	
	switch(op){
		case 1: //Derivar
			p.Mostrar();
			cout<<endl<<endl;
			cout<<"La Derivada es:"<<endl<<endl;
			p.Derivar();
			p.Mostrar();
			
			break;
			
		case 2: //Integrar
			p.Mostrar();
			cout<<endl<<endl;
			cout<<"La Integracion es:"<<endl<<endl;
			p.Integrar();
			p.Mostrar();
			
			break;
			
		case 3: //Sumar polinomios
			rep=0;
			cout<<"Cuantos terminos desea ingresar del segundo polonomio?: "; cin>>terminos; system("cls");
			
			while(rep!=terminos){
				bandera=0;
				cout<<"[Termino "<<rep+1<<" ]"<<endl<<endl;
				cout<<"Ingrese el coeficiente: "; cin>>coe;
				//Verifica que el exponente sea positivo
				while(bandera!=1){
					cout<<"Ingrese el exponente: "; cin>>exp;
					if(exp<0){
						cout<<"\n** El exponente no puede ser negativo **"<<endl;
					}
					else{
						bandera=1;
					}
				}
				//Metemos los valores a la lista
				p.Sumar(coe,exp);
				rep++;
				system("cls");
			}
			cout<<"LA SUMA ES:"<<endl<<endl;
			p.Mostrar();
			
			break;
			
		case 4: //Multiplicar polinomios
			rep=0; bandera2=0;
			cout<<"Cuantos terminos desea ingresar del segundo polonomio?: "; cin>>terminos; system("cls");
			
			while(rep!=terminos){
				bandera=0; 
				cout<<"[Termino "<<rep+1<<" ]"<<endl<<endl;
				cout<<"Ingrese el coeficiente: "; cin>>coe;
				//Verifica que el exponente sea positivo
				while(bandera!=1){
					cout<<"Ingrese el exponente: "; cin>>exp;
					if(exp<0){
						cout<<"\n** El exponente no puede ser negativo **"<<endl;
					}
					else{
						bandera=1;
					}
				}
				//Metemos los valores a la lista
				if(bandera2==0){
					q.Inserta(coe,exp);
					bandera2=1;
				}
				else{
					q.Sumar(coe,exp);
				}
				rep++;
				system("cls");
			}
			cout<<"LA MULTIPLICACION ES:"<<endl<<endl;
			p.Mostrar();
			cout<<endl<<endl;
			q.Mostrar();
			p.Multiplicar2(p,q);
			
			
			break;
			
		case 5: //Salir
			break;
			
		default:
			cout<<"\n** OPCION INCORRECTA **";
			break;
		
	}
	
	
	
	
	return 0;
}
