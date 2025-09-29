#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 
#include <sstream> 
using namespace std; 

bool esPrimo(int n) {
    // Casos especiales
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    // Verificar divisores impares hasta n
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


int main() { 
	// Configuración
	setlocale(LC_ALL, "Spanish"); 
	// Variables 
	int tamanio, numero, cont; 
	vector<int> listaGenerada; 
	stringstream primos, arreglo; 
	// Lectura de datos 
	cout << "Tamaño del arreglo: "; cin >> tamanio; 
	// Generar números aleatorios 
	srand(time(NULL)); 
	for (int i = 0; i < tamanio; i++) { 
		numero = rand() % 30 + 1; 
		listaGenerada.push_back(numero); 
	} 
	// Proceso 
	arreglo << "Arreglo: "; 
	primos << "Números primos: "; 
	for (int numero: listaGenerada) { 
		arreglo << numero << " "; 
		if (esPrimo(numero)) { 
			primos << numero << " "; 
		} 
	} 
	// Reporte 
	cout << "\n"; 
	cout << arreglo.str() << "\n"; 
	cout << primos.str() << "\n"; 
	return 0; 
}
		
