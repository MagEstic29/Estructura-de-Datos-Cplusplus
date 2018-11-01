#include<iostream>

using namespace std;

void funcion1(long long a,long long total,long long i){
	if(a>0){
		total=total*i;
		cout<<i<<"! ="<<"\t"<<total<<endl;
		break;
		funcion1(a-1,total,i+1);
	}
}

int main(){
	long long a=0,total=1,bandera=0,i=1;
	while(bandera!=1){
		cout<<"Dame un numero: "; cin>>a;
		if(a<30){
			bandera=1;
		}
		else system("cls");
	}
	
	
	funcion1(a,total,i);
	
	return 0;
}
