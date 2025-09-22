#include <iostream> 
#include <sstream>;
using namespace std; 
int main() { 
	// Configuración 
	setlocale(LC_ALL, "Spanish"); 
	// Variables 
	int datos[] = { 12,23,54,67,32,87,3}; 
	int suma, tamanio, pares = 0, impares = 0; 
	stringstream arreglo;
	// Proceso 
	tamanio = sizeof(datos) / sizeof(datos[0]); 
	suma = 0; 
	arreglo << "Arreglo: [";
	for (int i = 0; i < tamanio; i++) { 
		suma += datos[i]; 
		if(datos[i] % 2 == 0){
			pares++;
		}else{
			impares++;
		}
		arreglo << datos[i];
		arreglo << (i==(tamanio-1)?"]":",");
	} 
	// Reporte 
	cout << "Tamaño: " << tamanio << "\n"; 
	cout << arreglo.str() << endl;
	cout << "Suma: " << suma << "\n"; 
	cout<<"El numero de pares es: "<<pares<<endl;
	cout<<"El numero de impares es: "<<impares<<endl;
	return 0; 
}
