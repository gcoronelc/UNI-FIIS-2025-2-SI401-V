/*
Ejemplo de pilas
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

// Declaraciones globales
struct Nodo{
	int dato;
	Nodo *siguiente;
};
Nodo *pila;
int dato;

void inicializarVariables(){
	pila = NULL;
}

// La lectura de numeros finaliza cuando ingresa cero.
void cargarDatos(){
	// Variables
	int valor;
	Nodo *nuevoNodo;
	// Proceso
	do{
		cout << "Dato: ";
		cin >> valor;
		if(valor == 0){
			continue;
		}
		nuevoNodo = new Nodo;
		nuevoNodo->dato = valor;
		nuevoNodo->siguiente = pila;
		pila = nuevoNodo;
	}while(valor != 0);
}

int extraerDato(){
	Nodo *auxilar = pila;
	int dato = auxilar->dato;
	pila = auxilar->siguiente;
	delete auxilar;
	return dato;
}

int main(){
	
	//configuracion
  setlocale(LC_ALL, "spanish");	
  
  //Inicializar variables
  inicializarVariables();
  
  // Cargar datos a la pila
  cargarDatos();
  
  // Mostrar datos de la pila
  cout << endl;
  cout << "Datos de la pila:" << endl;
  while(pila != NULL){
  	dato = extraerDato();
  	cout << dato << endl;
	}
	cout << endl;
  
	system("pause");
	return 0;
}	  
