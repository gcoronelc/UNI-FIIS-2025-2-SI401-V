#include <iostream> 
#include <sstream> 
using namespace std; 
int main() { 

	// Variables 
	int n, i; 
	stringstream resultado; // Buffer para el resultado 
	
	// Lectura de datos 
	cout << "LECTURA\n"; 
	cout << "==============================\n"; 
	cout << "Valor de n: "; cin >> n; 
	
	// Proceso 
	resultado << "Serie: "; 
	i = 1; 
	while (i <= n) { 
		resultado << " " << i; 
		i++; 
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
