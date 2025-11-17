/*
Arreglos Dinamicos
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	
	//configuracion
  setlocale(LC_ALL, "spanish");	
  
  // Variables
  int *notas, cantNotas, promedio;
  
  // Leer cantidad de notas
  cout << "Cantidad de notas? "; cin >> cantNotas;
  
  // Crear el arreglo
  notas = new int[cantNotas];
  
  // Leer las notas
  for(int i=0; i<cantNotas; i++){
  	cout << "Nota " << i << ": ";
  	cin >> notas[i];
	}
	
	// Promedio
	promedio = 0;
	for(int i=0; i<cantNotas; i++){
		promedio += notas[i];
	}
	promedio /= cantNotas;
	
	// Reporte
	cout << "Promedio: " << promedio << endl;
	cout << endl;
	
	// Leberar memoria
	delete[] notas;
	
	system("pause");
	return 0;
}	
