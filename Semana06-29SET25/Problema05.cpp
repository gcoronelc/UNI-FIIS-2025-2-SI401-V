#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 
#include <sstream> 
using namespace std; 

int main() { 
	// Configuraci�n
	setlocale(LC_ALL, "Spanish"); 
	// Variables 
	int tamanio, numero, cont; 
	vector<int> listaGenerada; 
	stringstream primos, arreglo; 
	// Lectura de datos 
	cout << "Tama�o del arreglo: "; cin >> tamanio; 
	// Generar n�meros aleatorios 
	srand(time(NULL)); 
	for (int i = 0; i < tamanio; i++) { 
		numero = rand() % 30 + 1; 
		listaGenerada.push_back(numero); 
	} 
	// Proceso 
	arreglo << "Arreglo: "; 
	primos << "N�meros primos: "; 
	for (int numero: listaGenerada) { 
		arreglo << numero << " "; 
		cont = 0; 
		for (int j = 1; j <= numero; j++) { 
			cont += (numero % j == 0) ? 1 : 0;
		} 
		if (cont == 2) { 
			primos << numero << " "; 
		} 
	} 
	// Reporte 
	cout << "\n"; 
	cout << arreglo.str() << "\n"; 
	cout << primos.str() << "\n"; 
	return 0; 
}
	
	
