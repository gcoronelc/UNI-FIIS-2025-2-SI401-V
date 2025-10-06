#include <iostream>
#include <iomanip>
#include <locale>
using namespace std;

int sumar(int n1, int n2){
	// Variables
	int suma;
	// Proceso
	suma = n1 + n2;
	// Reporte
	return suma;
}

int main() {
	// Configurar la consola para caracteres especiales
   setlocale(LC_ALL, "");
   // Datos o Lectura
   int num1 = 40;
	int num2 = 80; 
   // Proceso
   int suma = sumar(num1,num2); 
   // Salida
   cout << "Reporte" << endl;
   cout << "==================" << endl;
   cout << "Numero 1: " << num1 << endl;
   cout << "Numero 2: " << num2 << endl;
   cout << "Suma: " << suma << endl;
   return 0;
}
