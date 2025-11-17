#include <iostream>
using namespace std;

int main(){
	
	//configuracion
  setlocale(LC_ALL, "spanish");
	
	// Dato
	int dato;
	int *pDato;
	
	// Proceso
	dato = 20;
	pDato = &dato;
	
	// Conociendo el dato
	cout << "VARIABLE: dato" << endl;
	cout << "====================================" << endl;
	cout << "Valor: " << dato << endl;
	cout << "Dirección: " << &dato << endl;
	cout << endl;
	
	// Conociendo el puntero
	cout << endl;
	cout << "PUNTERO: pDato" << endl;
	cout << "====================================" << endl;
	cout << "Dirección: " << pDato << endl;
	cout << "Valor: " << *pDato << endl;
	
	// Cambiando el valor
	*pDato = 50;
	cout << endl;
	cout << "Variable dato = " << dato << endl;
	
	// Incrementando el apuntador
	pDato++;
	cout << endl;
	cout << "Valor: " << *pDato << endl;
	cout << endl;
	
	// Incrementando el apuntador
	pDato++;
	cout << "Valor: " << *pDato << endl;
	cout << endl;	
	
	system("pause");
	return 0;
}
