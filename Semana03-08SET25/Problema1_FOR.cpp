#include <iostream> 
#include <sstream> 
using namespace std; 
int main() { 

	// Variables 
	int n; 
	stringstream resultado; // Buffer para el resultado 
	
	// Lectura de datos 
	cout << "LECTURA\n"; 
	cout << "==============================\n"; 
	cout << "Valor de n: "; cin >> n; 
	
	// Proceso 
	resultado << "Serie: "; 
	for (int i = 1; i <= n; i++) { 
		resultado << i << "\t"; 
	} 
	
	// Reporte 
	cout << "\n"; 
	cout << "REPORTE\n";
	cout << "==============================\n"; 
	cout << resultado.str(); 
	cout << "\n"; 
	
	// Fin 
	return 0; 

}
