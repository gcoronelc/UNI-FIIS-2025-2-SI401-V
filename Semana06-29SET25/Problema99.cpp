#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 
#include <sstream> 
using namespace std;

int main(){
	// Dimension
	int n;
	cout << "Valor de N: "; cin >> n;
	// Generar la matriz
	int matriz[n][n];
	srand(time(NULL)); 
	for (int i = 0; i < n; i++) { 
		for(int j = 0; j < n; j++){
			int numero = rand() % 30 + 1;
			matriz[i][j] = numero;
		}
	}
	// Proceso
	int suma[n];
	for(int columna = 0; columna < n; columna++){
		suma[columna] = 0;
		for(int fila = 0; fila < n; fila++ ){
			suma[columna] = suma[columna] + matriz[fila][columna];
		}
	}
	// Reporte
	cout << "MATRIZ GENERADA" << endl;
	for (int i = 0; i < n; i++) { 
		cout << "Fila " << (i+1) << ":\t";
		for(int j = 0; j < n; j++){
			cout << matriz[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "SUMA :\t";
	for(int i = 0; i < n; i++ ){
		cout << suma[i] << "\t";
	}
	cout << "\n";
	
	return 0;
}
