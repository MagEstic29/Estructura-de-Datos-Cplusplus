#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	cout << "Escriba el nombre del archivo a leer: " << endl;
	string filename;
	cin >> filename;
	ifstream file(filename.c_str());
	if(!file)
	{
		cout << "Error no se puede abrir el archivo: " << filename << endl;
                return 1;
	}
	string linea, archivo;
	
	while(getline(file, linea))
		archivo += linea + "\n";
	cout << archivo;
	
	return 0;
}
