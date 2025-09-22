#include <iostream> 
#include <sstream>;
#include <cstdlib>
#include <ctime>
using namespace std; 
int main() { 
	// Configuración 
	setlocale(LC_ALL, "Spanish"); 
	// Inicializar generador de números aleatorios
    srand(time(0));
	// Variables 
	int suma, tamanio, pares = 0, impares = 0; 
	stringstream arreglo;
	// Datos
	tamanio = 8;
	int datos[tamanio];
	for(int i = 0; i < tamanio; i++){
		int numero = rand() % 21 + 10;
		datos[i] = numero;
	}
	// Proceso 
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
